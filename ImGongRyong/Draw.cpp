// 파일 이름: Draw.cpp
// 설명: 이 파일은 Draw 클래스의 구현을 포함하고 있습니다.
// 작성자: 
// 작성 날짜: 
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#include "Draw.h"
#include "Consol.h"
#include <cstring>
#include <iostream>
#include <Windows.h>

using namespace std;

// Draw 클래스 draw 함수 선언 const로 내부 수정되지 않게
// 비행기, 파이프, 동전 객체
// 현재점수, 최고점수, 화면 사이즈, 빈공간크기, 일시정지
void Draw::draw
(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, const std::vector<Object::Coin>& coins, int score, int highScore, int width, int height, int gapSize, bool paused)
{
    // 상수로 동전, 게임 벽의 문자를 정의
    const char CoinChar = '$';
    const char TopBottomWall = '-';
    const char SideWall = '|';

    // 비행기 높이, 너비 정의 문자열 배열 초기화
    const int PLANE_WIDTH = 3;
    const int PLANE_HEIGHT = 3;
    const char* PlaneGraphic[PLANE_HEIGHT] =
    {
        " > ",
        ">>^",
        " > "
    };

    // 콘솔 핸들 (콘솔 입출력 제어)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // COORD 구조체 bufferSize 변수선언 콘솔 화면크기 설정 +2는 벽을 위해 추가
    COORD bufferSize;
    bufferSize.X = static_cast<SHORT>(width + 2);
    bufferSize.Y = static_cast<SHORT>(height + 2);

    // 동적 할당 (문자 저장)
    CHAR_INFO* buffer = new CHAR_INFO[(width + 2) * (height + 2)];

    // 콘솔에 텍스트 출력 영역 설정
    SMALL_RECT writeRegion;
    writeRegion.Left = 0;
    writeRegion.Top = 0;
    writeRegion.Right = static_cast<SHORT>(width + 1);
    writeRegion.Bottom = static_cast<SHORT>(height + 1);

    // 버퍼 초기화하여 이전 데이터가 남아있지 않게
    memset(buffer, 0, sizeof(CHAR_INFO) * (width + 2) * (height + 2));

    // 공백 문자로 초기화
    for (int i = 0; i < (width + 2) * (height + 2); ++i)
    {
        buffer[i].Char.AsciiChar = ' ';
        buffer[i].Attributes = 0x0F;
    }

    // 상단 벽 설정
    for (int x = 0; x < width + 2; ++x)
    {
        buffer[x].Char.AsciiChar = TopBottomWall;
    }

    // 왼쪽 벽 설정
    for (int y = 0; y < height; ++y)
    {
        buffer[(y + 1) * (width + 2)].Char.AsciiChar = SideWall;

        // 객체를 화면에 그림

        // x : 현재 가로 위치, width : 화면너비
        for (int x = 0; x < width; ++x)
        {
            bool isPipe = false;

            // 파이프 객체 리스트
            for (const Object::Pipe& pipe : pipes)
            {
                // 파이프 가로 세로 위치 와 현 위치 비교 후 파이프를 그림
                if ((x == pipe.pipeX || x == pipe.pipeX + 1 || x == pipe.pipeX + 2) && (y < pipe.pipeY || y >= pipe.pipeY + gapSize))
                {
                    buffer[(y + 1) * (width + 2) + (x + 1)].Char.AsciiChar = '|';
                    isPipe = true;
                    break;
                }
            }

            if (!isPipe) // 파이프가 없는 경우
            {
                bool isCoin = false;

                // 파이프 그림 그리는 것과 동일
                for (const Object::Coin& coin : coins)
                {

                    if (x == coin.coinX && y == coin.coinY)
                    {
                        buffer[(y + 1) * (width + 2) + (x + 1)].Char.AsciiChar = CoinChar;
                        isCoin = true;
                        break;
                    }
                }

                if (!isCoin) // 파이프와 동전이 없는 경우
                {
                    if (y >= plane.planeY && y < plane.planeY + PLANE_HEIGHT && x >= plane.planeX && x < plane.planeX + PLANE_WIDTH)
                    {
                        buffer[(y + 1) * (width + 2) + (x + 1)].Char.AsciiChar = PlaneGraphic[y - plane.planeY][x - plane.planeX];
                    }
                }
            }
        }
        buffer[(y + 1) * (width + 2) + (width + 1)].Char.AsciiChar = SideWall;
    }

    // 게임 하단 벽 설정
    for (int x = 0; x < width + 2; ++x)
    {
        buffer[(height + 1) * (width + 2) + x].Char.AsciiChar = TopBottomWall;
    }

    // 설정 된 내용을 실제 콘솔에 그림
    WriteConsoleOutput(hConsole, buffer, bufferSize, { 0, 0 }, &writeRegion);

    // 동적 할당 해제
    delete[] buffer;

}
