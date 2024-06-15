#include "Object.h"

void Object::Plane::update(float gravity, float jumpSpeed, bool moveUp, bool moveDown)
{
    // 속도 조절을 위한 속도 선언
    static const float MAX_DOWN_SPEED = 1.5f;
    static const float MAX_UP_SPEED = -1.5f;

    if (moveUp) // 상승
    {
        velocity = jumpSpeed; // 속도를 점프속도로 설정
    }
    else if (moveDown)
    {
        velocity = -jumpSpeed;
    }
    else
    {
        velocity = velocity + gravity;
    }

    // 속도 조절
    if (velocity > MAX_DOWN_SPEED) velocity = MAX_DOWN_SPEED;
    if (velocity < MAX_UP_SPEED) velocity = MAX_UP_SPEED;

    // 위치 업데이트
    planeY = planeY + velocity;

    // 비행기 화면 이탈 체크
    if (planeY < 0) planeY = 0; // Y좌표가 0보다 작아지지 않도록, 화면 위쪽 이탈 막기
    if (planeY > 20 - 3) planeY = 20 - 3; // 20은 화면 높이, 3은 비행기 높이 화면 아래로 이탈 막기
}

