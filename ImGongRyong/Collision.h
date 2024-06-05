// 파일 이름: Collision.h
// 설명: 이 파일은 Collision 클래스의 선언을 포함하고 있습니다. Collision 클래스는 게임에서 물체의 충돌을 관리 합니다.
// 작성자: 전인배
// 작성 날짜: 2024-06-03
// 수정 이력:
//		- 2024-06-03: ['isPassingThrough' 추가] (작성자: 전인배)
//		- 2024-06-04: ['isCollisionCoin' 추가] (작성자: 전인배)

#pragma once

#include "Object.h"

class Collision : public Object
{
public:
	// 공룡(obj1)과 장애물(obj2)이 충돌하는지 확인
	bool isCollision(Object& dino, Object& Obstacle);

	// 장애물은 2곳(위, 아래)에 있기 때문에 두개의 객체로 나누고, 각 객체에 대한 충돌 검사
	bool isPassingThrough(Object& dino, Object& upperObstacle, Object& lowerObstacle);

	// 공룡과 코인이 충돌하는지 확인
	bool isCollisionCoin(Object& dino, Object& coin);
};