// 파일 이름: Graphic.h
// 설명: - 게임의 그래픽 출력과 관련된 기능을 제공합니다.
// 작성자: 
// 작성 날짜: 24.06.01
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define DINO_HEIGHT 20
#define DINO_WIDTH 20
#define CONSOLE_HEIGHT 200
#define CONSOLE_WIDTH 200
#define COIN_WIDTH 10
#define COIN_HEIGHT 10

char* make_dino(long sequence);
char* make_pillar(int phase);
char* make_coin();