// 파일 이름: Collision.h
// 설명: - 충돌 검사에 필요한 함수를 선언합니다.
// 작성자: 전인배
// 작성 날짜: 2024-06-03
// 수정 이력:
//		- 2024-06-03: ['isPassingThrough' 추가] (작성자: 전인배)
//		- 2024-06-04: ['isCollisionCoin' 추가] (작성자: 전인배)

#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include "Object.h"

class Collision
{
public:
    static bool checkCollision(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, int gapSize, int planeHeight);
    static bool checkCoinCollision(Object::Plane& plane, std::vector<Object::Coin>& coins, int& score, int planeHeight);
};

#endif
