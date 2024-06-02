// 파일 이름: Control.h
// 설명: 이 파일은 Control 클래스의 선언을 포함하고 있습니다. Control 클래스는 게임에서 [		] 을 관리 합니다.
// 작성자: 이동환
// 작성 날짜: 24.06.02
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "Character.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Control
{
public :
	void inputKey(Character& character)
	{
		while (_kbhit())
		{
			int key = _getch();

			if (key == 0 || key == 224)
			{
				key = _getch();

				switch (key)
				{
				case 72:
					character.moveUp();
					break;

				case 80:
					character.moveDown();
					break;

				default:
					break;
				}
			}
		}
	}


};

#endif // !CONTROL_H
