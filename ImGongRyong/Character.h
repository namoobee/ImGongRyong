// 파일 이름: Character.h
// 설명: 이 파일은 Character 클래스의 선언을 포함하고 있습니다. Character 클래스는 게임에서 [	캐릭터 	] 을 관리 합니다.
// 작성자: 이동환
// 작성 날짜: 24.06.01
// 수정 이력:
//		- 2024-xx-xx: [		내용	] (작성자: )

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>

using namespace std;

class Character
{

protected:
	// 캐릭터 현재좌표
	int character_x;
	int character_y;

	// 캐릭터 크기
	int c_width;
	int c_height;

	// 캐릭터 그래픽
	vector<string> shape_character;

public :
	// 캐릭터 클래스 생성자 선언 및 초기화
	Character(int ch_x, int ch_y, int ch_width, int ch_height, vector<string> ch_shape) 
		: character_x(ch_x), character_y(ch_y), c_width(ch_width), c_height(ch_height), shape_character(ch_shape) {}

	// 캐릭터 이동
	void moveUp();
	void moveDown();
	void moveDefault();

	// 캐릭터 현재좌표 받기
	int getCharacter_x() const;
	int getCharacter_y() const;

	// 캐릭터 그래픽 받기
	const vector<string>& getShpaeCh() const;
};


#endif // !CHARACTER_H
