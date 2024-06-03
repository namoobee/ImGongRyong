// 파일 이름: Object.cpp
// 설명: 이 파일은 Object 클래스의 구현을 포함하고 있습니다. (물체)
// 작성자: 전인배
// 작성 날짜: 2024-06-02
// 수정 이력:
//		- 2024-xx-xx: [	] (작성자:)

#include <iostream>
#include "Object.h"

using namespace std;

	// 매개변수가 있는 생성자
	Object::Object(int objX, int objY, int objWidth, int objHeight, string& shape)
	{
		this->objX = objX;
		this->objY = objY;
		this->objWidth = objWidth;
		this->objHeight = objHeight;
		this->objShape = objShape;
	}
	
	// 좌표 설정자
	void Object::setPosition(int objX, int objY)
	{
		this->objX = objX;
		this->objY = objY;
	}

	// 크기 설정자
	void Object::setSize(int objWidth, int objHeight)
	{
		this->objWidth = objWidth;
		this->objHeight = objHeight;
	}

	// 모양 설정자
	void Object::setShape(string& shape)
	{
		this->objShape = objShape;
	}

	// 좌표 접근자
	int Object::getObj_x()
	{
		return this->objX;
	}
	int Object::getObj_y()
	{
		return this->objY;
	}

	// 크기 접근자
	int Object::getObj_Width()
	{
		return this->objWidth;
	}
	int Object::getObj_Height()
	{
		return this->objHeight;
	}

	// 모양 접근자
	string Object::getObj_Shape()
	{
		return this->objShape;
	}
