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

// ���� ȭ�� ũ�� ����
const int WIDTH = 110;
const int HEIGHT = 20;

// ����� ��ġ �� ũ�� ����
const int PLANE_X = 5;
const int PLANE_HEIGHT = 3;

// ����� �߷°� ���� �ӵ� ����
const float GRAVITY = 0.25;
const float JUMP_SPEED = -1.0f;

Dashboard dashboard;
Storage storage;
bool running = true;
int highScore ; // �ְ������� ������Ű�� ���� �������� ����

// ���� ��� �Լ�
void drawScore(int score, int highScore, bool paused);

// ���� ȭ�� ��� �Լ�
void showGameScreen();

int main() {
    // �ܼ� â ũ�� ����
    Console::setConsoleSize(WIDTH, HEIGHT + 2);

    // Ŀ�� �����
    Console::setCursorVisibility(false);

    // ���� ���� �õ� �ʱ�ȭ
    srand(static_cast<unsigned int>(time(0)));

    // ���� ���� ����
    while (running) {
        // ���� �޴� ǥ��
        dashboard.displayMainMenu();
        int choice = dashboard.getUserChoice();

        switch (choice) {
        case 1:
            // ���� ����
            showGameScreen();
            break;
        case 2:
            // ��ŷ ǥ��
            storage.displayRanking();
            dashboard.printCenteredText("�ƹ� Ű�� ������ ���� ȭ������ ���ư��ϴ�...");
            while (!_kbhit()) {}
            _getch();
            break;
        case 3:
            // ���� ���
            dashboard.displayControls();
            while (!_kbhit()) {}
            _getch();
            break;
        case 4:
            // ���� ����
            dashboard.printCenteredText("������ �����մϴ�.");
            running = false;
            break;
        default:
            // �߸��� ���� ó��
            dashboard.printCenteredText("�߸��� �����Դϴ�. �ٽ� �������ּ���.");
            cout << endl << endl;
            dashboard.printCenteredText("�ƹ� Ű�� ������ ���� ȭ������ ���ư��ϴ�...");
            while (!_kbhit()) {}
            _getch();
            break;
        }
    }
    return 0;
}

// ���� ��� �Լ� ����
void drawScore(int score, int highScore, bool paused) {
    Console::gotoxy(0, 22);
    cout << "���� ����: " << score << setw(20) << "�ְ� ����: " << highScore << setw(20) << "�Ͻ�����: 'P'";
    if (paused) {
        Console::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
        cout << "�Ͻ�����";
    }
}

// ���� ȭ�� ��� �Լ� ����
void showGameScreen() {
    int PLANE_Y = HEIGHT / 2;  // ����� �ʱ� ��ġ ����
    float velocity = 0;  // �ʱ� �ӵ� ���� 
    int score = 1000;  // �ʱ� ���� ���� 
    int gapSize = PLANE_HEIGHT + 6;  // ��ֹ� ���� ����
    int pipeInterval = WIDTH / 4;  // ��ֹ� ���� ����
    float pipeSpeed = 2.0f;  // ��ֹ� �̵� �ӵ� ���� 
    int Properties = 5;     // ���η����Լ� ������ �и�
    int RestTime = 60; // sleep �Լ� �� ms����

    // ��ֹ��� ���� �ʱ�ȭ
    vector<Object::Pipe> pipes = { {WIDTH, HEIGHT / 2 - gapSize / 2} };
    vector<Object::Coin> coins;
    Object::Plane plane(PLANE_X, PLANE_Y);
    bool paused = false;
    DWORD startTime = GetTickCount64();

    // ���� ����
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
            // ����� ��ġ ������Ʈ
            plane.update(GRAVITY, JUMP_SPEED, false, false);
            if (Collision::checkCollision(plane, pipes, gapSize, PLANE_HEIGHT)) {
                break;
            }
            Collision::checkCoinCollision(plane, coins, score, PLANE_HEIGHT);

            // ������ ���� ��ֹ� �ӵ��� ���� ����
            if (score > 1000) { // 3�ܰ�
                pipeSpeed = 2;
                gapSize = PLANE_HEIGHT + 4;
                Properties = 20;
                RestTime = 30;
            }
            else if (score <= 1000 && score >= 500) { // 2�ܰ�
                pipeSpeed = 1;
                gapSize = PLANE_HEIGHT + 4;
                Properties = 10;
                RestTime = 30;
            }
            else { // �ʱ� 1�ܰ� 
                gapSize = PLANE_HEIGHT + 6;
            }

            // ��� ��ֹ� �̵�
            for (Object::Pipe& pipe : pipes) {
                pipe.pipeX -= (int)pipeSpeed;
            } 

            // ��� ���� �̵�
            for (Object::Coin& coin : coins) {
                coin.coinX -= (int)pipeSpeed;
            }

            // ���ο� ��ֹ� �߰�
            if (pipes.back().pipeX < WIDTH - pipeInterval) {
                pipes.push_back({ WIDTH, rand() % (HEIGHT - gapSize) });
            }
             
            // ���� Ȯ���� ���� �߰�
            if (rand() % Properties == 0) {
                coins.push_back({ WIDTH, rand() % HEIGHT });
            }

            // ȭ���� ��� ��ֹ� ����
            if (pipes.front().pipeX < -3) {
                pipes.erase(pipes.begin());
            }

            // ���� ����
            DWORD currentTime = GetTickCount64();
            if (currentTime - startTime >= 100) {
                score++;
                startTime = currentTime;
            }

            // �ְ� ���� ����
            if (score > highScore) {
                highScore = score;
            }
        }

        // ������ ���� ���� ���
        drawScore(score, highScore, paused);
        Draw::draw(plane, pipes, coins, score, highScore, WIDTH, HEIGHT, gapSize, paused);

        // ������ �ӵ� ����
         Sleep(RestTime);
    }

    // ���� ���� �޽��� ���
    Console::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
    cout << "Game Over!";
    Console::gotoxy(0, 22);
    cout << string(80, ' ');
    Console::gotoxy(0, 22);
    cout << "���� ����: " << score << endl << "�ְ� ����: " << highScore << endl;

    // ���� ���� ���� ����
    storage.askSaveScore(score);
}
