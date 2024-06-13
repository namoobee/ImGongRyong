// 파일 이름: Collision.cpp
// 설명: 이 파일은 Collision 클래스의 구현을 포함하고 있습니다. (충돌)
// 작성자: 전인배
// 작성 날짜: 2024-06-03
// 수정 이력:
//		- 2024-06-03: [Crash 클래스의 이름을 Collision으로 변경] (작성자: 전인배)
//		- 2024-06-03: ['isPassingThrough' 추가] (작성자: 전인배)
//		- 2024-06-04: ['isCollisionCoin' 추가] (작성자: 전인배)

#include "Collision.h"

// 비행기, 파이프, 빈공간 크기, 비행기 높이
bool Collision::checkCollision(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, int gapSize, int planeHeight)
{
    for (const Object::Pipe& pipe : pipes)
    {
        // 비행기 X좌표가 파이프 X좌표 범위에 포함되는지 검사
        if (plane.planeX >= pipe.pipeX && plane.planeX <= pipe.pipeX + 2)
        {
            // 비행기 Y좌표가 파이프 상단보다 작거나, 비행기 하단이 파이프 하단보다 큰지 검사
            if (plane.planeY < pipe.pipeY || plane.planeY + planeHeight > pipe.pipeY + gapSize)
            {
                // 충돌 감지 되면 true
                return true;
            }
        }
    }
    return false;
}

// 비행기, 동전, 점수
bool Collision::checkCoinCollision(Object::Plane& plane, std::vector<Object::Coin>& coins, int& score, int planeHeight)
{
    bool collisionDetected = false;

    for (auto it = coins.begin(); it != coins.end();)
    {
        // 동전 X좌표가 비행기 X좌표 범위 포함되는지, Y좌표도 같음
        if (it->coinX >= plane.planeX && it->coinX <= plane.planeX + 2 &&
            it->coinY >= plane.planeY && it->coinY < plane.planeY + planeHeight)
        {
            // 충돌 감지되면 동전을 벡터에서 제거
            it = coins.erase(it);
            // 30점 증가
            score += 30;
            // 충돌 TRUE 반환
            collisionDetected = true;
        }
        else
        {
            ++it;
        }
    }
    return collisionDetected;
}

