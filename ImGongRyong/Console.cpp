#include "console.h"

void Console::setConsoleSize(int width, int height)
{
    // 콘솔 창의 핸들을 가져옴
    HWND console = GetConsoleWindow();
    // RECT 구조체 선언
    RECT r;
    // 콘솔 창 현재 위치와 크기를 RECT 구조체에 저장
    GetWindowRect(console, &r);
    // 콘솔 창 위치와 크기 설정, r.left와 top은 현 위치 유지, 너비 높이는 픽셀단위로 설정
    MoveWindow(console, r.left, r.top, width * 10, height * 20, TRUE);
}

void Console::gotoxy(int x, int y)
{
    // 콘솔 화면 좌표 SHORT 타입으로 구조체 저장
    COORD coord = { (SHORT)x, (SHORT)y };
    // 콘솔 커서를 지정 위치 이동 표준 출력 핸들을 가져옴
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::setCursorVisibility(bool visible)
{
    // 콘솔 표준 출력 핸들 가져옴
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    // 현재 커서 정보
    GetConsoleCursorInfo(console, &cursorInfo);
    // 커서 가시성 설정
    cursorInfo.bVisible = visible;
    // 변경 된 커서 정보 설정
    SetConsoleCursorInfo(console, &cursorInfo);
}
