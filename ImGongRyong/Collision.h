#pragma once

#include <vector>
#include "Object.h"

class Collision
{
public:
    static bool checkCollision(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, int gapSize, int planeHeight);
    static bool checkCoinCollision(Object::Plane& plane, std::vector<Object::Coin>& coins, int& score, int planeHeight);
};
