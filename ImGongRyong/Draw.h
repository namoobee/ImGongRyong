#pragma once

#include <windows.h>
#include <vector>
#include "Object.h"

class Draw
{
public:
    static void draw(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, const std::vector<Object::Coin>& coins, int score, int highScore, int width, int height, int gapSize, bool paused);
};
