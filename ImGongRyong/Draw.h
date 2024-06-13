// 파일 이름: Draw.h
// 설명: - 그래픽을 그리는 기능과 관련된 기능을 제공합니다.
// 작성자: 
// 작성 날짜:
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#pragma once
#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <vector>
#include "Object.h"

class Draw
{
public:
    static void draw(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, const std::vector<Object::Coin>& coins, int score, int highScore, int width, int height, int gapSize, bool paused);
};

#endif
