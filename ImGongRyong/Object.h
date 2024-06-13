// 파일 이름: Object.h
// 설명: - 게임에 등장하는 다양한 오브젝트를 관리합니다.
// 작성자: 전인배
// 작성 날짜: 2024-06-02
// 수정 이력:
//		- 2024-06-05: ['string& objshpae' -> 'strint& objshape' 오타 수정] (작성자: 전인배)

#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    class Plane
    {
    public:
        int planeX, planeY;
        float velocity;
        Plane(int p_startX, int p_startY) : planeX(p_startX), planeY(p_startY), velocity(0) {}
        void update(float gravity, float jumpSpeed, bool moveUp, bool moveDown);
    };

    class Pipe
    {
    public:
        int pipeX;
        int pipeY;
        Pipe(int pi_startX, int pi_StartY) : pipeX(pi_startX), pipeY(pi_StartY) {}
    };

    class Coin
    {
    public:
        int coinX;
        int coinY;
        Coin(int c_startX, int c_startY) : coinX(c_startX), coinY(c_startY) {}
    };
};




#endif // !OBJECT_H
