// 파일 이름: Character.cpp
// 설명: 이 파일은 Character 클래스의 구현을 포함하고 있습니다. (캐릭터)
// 작성자: 이동환
// 작성 날짜: 24.06.01
// 수정 이력:
//		- 2024-06-01: [		내용	] (작성자: 이동환 )

#include "Character.h"

using namespace std;

void Character::moveUp()
{
	character_y = character_y - 3;
}

void Character::moveDown()
{
	character_y = character_y + 3;
}

void Character::moveDefault()
{
	character_y = character_y + 1;
}

int Character::getCharacter_x() const
{
	return character_x;
}

int Character::getCharacter_y() const
{
	return character_y;
}

const vector<string> Character::getShpaeCh() const
{
	return shape_character;
}