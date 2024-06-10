// 파일 이름: Gravity.h
// 설명: - 중력 적용과 관련된 기능을 제공합니다.
// 작성자: 이동환
// 작성 날짜: 24.06.02
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#pragma once
#ifndef GRAVITY_H
#define GRAVITY_H

#include "Character.h"
#include <iostream>

using namespace std;


class Gravity
{
public:
	void isGravity(Character &character)
	{
		character.moveDefault();
	}
};


#endif // !GRAVITY_H
