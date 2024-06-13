// 파일 이름: Main.cpp
// 설명: 이 파일은 main.cpp 를 구현합니다
// 작성자: 류성수
// 작성 날짜: 2024-06-04
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "Object.h"
#include "Consol.h"
#include "Draw.h"
#include "Collision.h"

using namespace std;

// 게임화면 너비 높이 설정
const int WIDTH = 110;
const int HEIGHT = 20;
// 비행기 x좌표 초기 위치 설정
const int PLANE_X = 5;
// 비행기 높이 설정
const int PLANE_HEIGHT = 3;
// 비행기 중력 가속도 설정
const float GRAVITY = 0.02f;
// 비행기 점프속도 설정
const float JUMP_SPEED = -1.0f;

// 게임화면 상단 점수 출력

void drawScore(int score, int highScore, bool paused);

int main()
{

    // 콘솔 창 크기 설정 및 커서 숨김
    Consol::setConsoleSize(WIDTH, HEIGHT + 2);
    // 콘솔 커서 가시성 설정(Consol.cpp) false 일땐 커서가 보이지 않음
    Consol::setCursorVisibility(false);

    // 현재시간 난수 생성 시드 전달
    srand(static_cast<unsigned int>(time(0)));
    // 비행기 y좌표 초기 위치를 화면 중앙으로 설정
    int PLANE_Y = HEIGHT / 2;
    // 비행기 초기 속도 0으로 설정
    float velocity = 0;
    // 초기 점수를 0으로 설정
    int score = 0;
    // 최고 점수 0 설정 이건 후에 수정
    int highScore = 0;
    // 파이프 이동 속도
    int pipeSpeed = 2;
    // 빈공간
    int gapSize = PLANE_HEIGHT + 6;
    // 파이프 생성 간격 화면 너비 1/4
    int pipeInterval = WIDTH / 4;



    // 파이프, 코인, 비행기 초기화
    vector<Object::Pipe> pipes = { {WIDTH, HEIGHT / 2 - gapSize / 2} };
    vector<Object::Coin> coins;
    Object::Plane plane(PLANE_X, PLANE_Y);

    // 게임 루프 제어
    bool running = true;
    bool paused = false;

    DWORD startTime = GetTickCount();

    // 게임 루프 시작
    while (running)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 'p' || ch == 'P')
            {
                paused = !paused;
            }

            if (!paused)
            {
                if (ch == 'w' || ch == 'W')
                {
                    plane.update(GRAVITY, JUMP_SPEED, true, false);
                }

                else if (ch == 's' || ch == 'S')
                {
                    plane.update(GRAVITY, JUMP_SPEED, false, true);
                }
            }

        }

        if (!paused)
        {
            // 중력 영향으로 비행기 위치 업데이트
            plane.update(GRAVITY, JUMP_SPEED, false, false);
            // 비행기와 파이프 충돌 확인, 충돌 시 게임종료
            if (Collision::checkCollision(plane, pipes, gapSize, PLANE_HEIGHT))
            {
                running = false;
            }

            // 비행기와 동전 충돌 확인, 충돌 시 점수 증가
            Collision::checkCoinCollision(plane, coins, score, PLANE_HEIGHT);

            // 모든 파이프의 x 좌표를 줄여 이동 (오른쪽에서 왼쪽이동)
            for (Object::Pipe& pipe : pipes)
            {
                pipe.pipeX -= pipeSpeed;
            }

            // 모든 동전의 x 좌표를 줄여 이동 (파이프와 동일)
            for (Object::Coin& coin : coins)
            {
                coin.coinX -= pipeSpeed;
            }

            // 마지막 파이프가 특정 위치 도달 시 새 파이프 추가
            if (pipes.back().pipeX < WIDTH - pipeInterval)
            {
                pipes.push_back({ WIDTH, rand() % (HEIGHT - gapSize) });
            }

            // 일정 확률로 동전 추가
            if (rand() % 10 == 0)
            {
                coins.push_back({ WIDTH, rand() % HEIGHT });
            }

            // 화면을 벗어난 파이프 제거
            if (pipes.front().pipeX < -3)
            {
                pipes.erase(pipes.begin());
            }

            DWORD currentTime = GetTickCount();
            if (currentTime - startTime >= 100)
            {
                score++;
                startTime = currentTime;
            }

            if (score > highScore)
            {
                highScore = score;
            }
        }


        // 게임 화면 그리기
        drawScore(score, highScore, paused);

        Draw::draw(plane, pipes, coins, score, highScore, WIDTH, HEIGHT, gapSize, paused);


        // 50ms동안 대기 게임속도 조절
        Sleep(50);
    }
    // 커서를 지정 위치로 이동 (Consol.cpp 참조)
    Consol::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
    std::cout << "Game Over!" << std::endl;
    Sleep(3000);
    return 0;
}


void drawScore(int score, int highScore, bool paused)
{
    Consol::gotoxy(1, 23);
    cout << "일시정지 : 'P'" << setw(20) << "최고점수 : " << highScore << setw(20) << "현재 점수 :" << score;

    if (paused)
    {
        Consol::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
        cout << "일시정지";
    }
}
