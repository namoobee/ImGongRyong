#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define DINO_HEIGHT 20
#define DINO_WIDTH 20
#define CONSOLE_Y 200
#define CONSOLE_X 200

char* make_dino(long sequence);
char* make_pillar(int phase);
