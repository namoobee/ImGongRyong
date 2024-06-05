// 파일 이름: Collision.cpp
// 설명: 이 파일은 Collision 클래스의 구현을 포함하고 있습니다. (충돌)
// 작성자: 전인배
// 작성 날짜: 2024-06-03
// 수정 이력:
//		- 2024-06-03: [Crash 클래스의 이름을 Collision으로 변경] (작성자: 전인배)
//		- 2024-06-03: ['isPassingThrough' 추가] (작성자: 전인배)
//		- 2024-06-04: ['isCollisionCoin' 추가] (작성자: 전인배)

#include "Collision.h"

bool Collision::isCollision(Object& dino, Object& Obstacle)
{
	// 공룡의 경계 계산
	int Dino_left = dino.getObj_x(); // 공룡의 왼쪽 경계
	int Dino_right = dino.getObj_x() + dino.getObj_Width(); // 공룡의 오른쪽 경계
	int Dino_top = dino.getObj_y(); // 공룡의 상단 경계
	int Dino_bottom = dino.getObj_y() + dino.getObj_Height(); // 공룡의 하단 경계
	
	// 장애물의 경계 계산
	int Obstacle_left = Obstacle.getObj_x(); // 장애물의 왼쪽 경계
	int Obstacle_right = Obstacle.getObj_x() + Obstacle.getObj_Width(); // 장애물의 오른쪽 경계
	int Obstacle_top = Obstacle.getObj_y(); // 장애물의 상단 경계
	int Obstacle_bottom = Obstacle.getObj_y() + Obstacle.getObj_Width(); // 장애물의 하단 경계

	// 충돌 여부 확인 (부딪히면 false)
	if (Dino_right > Obstacle_left && Dino_left < Obstacle_right && Dino_bottom > Obstacle_top && Dino_top < Obstacle_bottom)
	{
		return false;
	}
	return true;
}

bool Collision::isPassingThrough(Object& dino, Object& upperObstacle, Object& lowerObstacle)
{
	// 공룡과 장애물들의 충돌이 일어나는지 확인 (충돌하지 않았다면 true)
	return isCollision(dino, upperObstacle) && isCollision(dino, lowerObstacle);
}

bool Collision::isCollisionCoin(Object& dino, Object& coin)
{
	// 공룡의 경계 계산
	int Dino_left = dino.getObj_x(); 
	int Dino_right = dino.getObj_x() + dino.getObj_Width();
	int Dino_top = dino.getObj_y();
	int Dino_bottom = dino.getObj_y() + dino.getObj_Height();

	// 코인의 경계 계산
	int Coin_left = coin.getObj_x(); // 코인의 왼쪽 경계
	int Coin_right = coin.getObj_x() + coin.getObj_Width(); // 코인의 오른쪽 경계
	int Coin_top = coin.getObj_y(); // 코인의 상단 경계
	int Coin_bottom = coin.getObj_y() + coin.getObj_Height(); // 코인의 하단 경계

	// 충돌 여부 확인 (공룡과 코인이 충돌하면 true)
	if (Dino_right > Coin_left && Dino_left < Coin_right && Dino_bottom > Coin_top && Dino_top < Coin_bottom)
	{
		return true;
	}
	return false;
}
