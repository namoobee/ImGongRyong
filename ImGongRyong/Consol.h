// 파일 이름: Gravity.h
// 설명: - 중력 적용과 관련된 기능을 제공합니다.
// 작성자: 이동환
// 작성 날짜: 24.06.02
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#pragma once
#ifndef CONSOL_H
#define CONSOL_H

#include <windows.h>

class Consol
{
public:
    static void setConsoleSize(int width, int height);
    static void gotoxy(int x, int y);
    static void setCursorVisibility(bool visible);

};

#endif
