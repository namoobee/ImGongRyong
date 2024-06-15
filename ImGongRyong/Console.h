#pragma once

#include <windows.h>

class Console
{
public:
    static void setConsoleSize(int width, int height);
    static void gotoxy(int x, int y);
    static void setCursorVisibility(bool visible);

};
