#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>

#include "Draw.h"
#include "Object.h"
#include "Console.h"
#include "Collision.h"
#include "Dashboard.h"
#include "Storage.h"

using namespace std;

// 게임 화면 크기 설정
const int WIDTH = 110;
const int HEIGHT = 20;

// 비행기 위치 및 크기 설정
const int PLANE_X = 5;
const int PLANE_HEIGHT = 3;

// 비행기 중력과 점프 속도 설정
const float GRAVITY = 0.25;
const float JUMP_SPEED = -1.0f;

Dashboard dashboard;
Storage storage;
bool running = true;
int highScore = 0; // 최고점수를 유지시키기 위해 전역으로 설정

// 점수 출력 함수
void drawScore(int score, int highScore, bool paused);

// 게임 화면 출력 함수
void showGameScreen();

int main() {
    // 콘솔 창 크기 설정
    Console::setConsoleSize(WIDTH, HEIGHT + 2);

    // 커서 숨기기
    Console::setCursorVisibility(false);

    // 난수 생성 시드 초기화
    srand(static_cast<unsigned int>(time(0)));

    // 메인 게임 루프
    while (running) {
        // 메인 메뉴 표시
        dashboard.displayMainMenu();
        int choice = dashboard.getUserChoice();

        switch (choice) {
        case 1:
            // 게임 시작
            showGameScreen();
            break;
        case 2:
            // 랭킹 표시
            storage.displayRanking();
            dashboard.printCenteredText("아무 키나 누르면 메인 화면으로 돌아갑니다...");
            while (!_kbhit()) {}
            _getch();
            break;
        case 3:
            // 게임 방법
            dashboard.displayControls();
            while (!_kbhit()) {}
            _getch();
            break;
        case 4:
            // 게임 종료
            dashboard.printCenteredText("게임을 종료합니다.");
            running = false;
            break;
        default:
            // 잘못된 선택 처리
            dashboard.printCenteredText("잘못된 선택입니다. 다시 선택해주세요.");
            cout << endl << endl;
            dashboard.printCenteredText("아무 키나 누르면 메인 화면으로 돌아갑니다...");
            while (!_kbhit()) {}
            _getch();
            break;
        }
    }
    return 0;
}

// 점수 출력 함수 구현
void drawScore(int score, int highScore, bool paused) {
    Console::gotoxy(0, 22);
    cout << "현재 점수: " << score << setw(20) << "최고 점수: " << highScore << setw(20) << "일시정지: 'P'";
    if (paused) {
        Console::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
        cout << "일시정지";
    }
}

// 게임 화면 출력 함수 구현
void showGameScreen() {
    int PLANE_Y = HEIGHT / 2;  // 비행기 초기 위치 설정
    float velocity = 0;  // 초기 속도 설정
    int score = 0;  // 초기 점수 설정
    int gapSize = PLANE_HEIGHT + 6;  // 장애물 간격 설정
    int pipeInterval = WIDTH / 4;  // 장애물 간격 설정
    float pipeSpeed = 2.0f;  // 장애물 이동 속도 설정

    // 장애물과 동전 초기화
    vector<Object::Pipe> pipes = { {WIDTH, HEIGHT / 2 - gapSize / 2} };
    vector<Object::Coin> coins;
    Object::Plane plane(PLANE_X, PLANE_Y);

    bool paused = false;
    DWORD startTime = GetTickCount64();

    // 게임 루프
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'p') {
                paused = !paused;
            }
            if (!paused) {
                if (ch == 'w' || ch == 'W') {
                    plane.update(GRAVITY, JUMP_SPEED, true, false);
                }
                else if (ch == 's' || ch == 'S') {
                    plane.update(GRAVITY, JUMP_SPEED, false, true);
                }
            }
        }

        if (!paused) {
            // 비행기 위치 업데이트
            plane.update(GRAVITY, JUMP_SPEED, false, false);
            if (Collision::checkCollision(plane, pipes, gapSize, PLANE_HEIGHT)) {
                break;
            }
            Collision::checkCoinCollision(plane, coins, score, PLANE_HEIGHT);

            // 점수에 따라 장애물 속도와 간격 조정
            if (score > 900) {
                pipeSpeed = 1.5f;
                gapSize = PLANE_HEIGHT + 5;
            }
            else if (score > 600) {
                pipeSpeed = 1.3f;
                gapSize = PLANE_HEIGHT + 6;
            }
            else if (score < 100) {
                pipeSpeed = 1;
                gapSize = PLANE_HEIGHT + 6;
            }

            // 모든 장애물 이동
            for (Object::Pipe& pipe : pipes) {
                pipe.pipeX -= pipeSpeed;
            }

            // 모든 동전 이동
            for (Object::Coin& coin : coins) {
                coin.coinX -= pipeSpeed;
            }

            // 새로운 장애물 추가
            if (pipes.back().pipeX < WIDTH - pipeInterval) {
                pipes.push_back({ WIDTH, rand() % (HEIGHT - gapSize) });
            }

            // 일정 확률로 동전 추가
            if (rand() % 10 == 0) {
                coins.push_back({ WIDTH, rand() % HEIGHT });
            }

            // 화면을 벗어난 장애물 제거
            if (pipes.front().pipeX < -3) {
                pipes.erase(pipes.begin());
            }

            // 점수 증가
            DWORD currentTime = GetTickCount64();
            if (currentTime - startTime >= 100) {
                score++;
                startTime = currentTime;
            }

            // 최고 점수 갱신
            if (score > highScore) {
                highScore = score;
            }
        }

        // 점수와 게임 상태 출력
        drawScore(score, highScore, paused);
        Draw::draw(plane, pipes, coins, score, highScore, WIDTH, HEIGHT, gapSize, paused);

        // 프레임 속도 조절
         Sleep(30);
    }

    // 게임 오버 메시지 출력
    Console::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
    cout << "Game Over!";
    Console::gotoxy(0, 22);
    cout << string(80, ' ');
    Console::gotoxy(0, 22);
    cout << "현재 점수: " << score << endl << "최고 점수: " << highScore << endl;

    // 점수 저장 여부 묻기
    storage.askSaveScore(score);
}
