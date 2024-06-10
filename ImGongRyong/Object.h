// 파일 이름: Object.h
// 설명: - 게임에 등장하는 다양한 오브젝트를 관리합니다.
// 작성자: 전인배
// 작성 날짜: 2024-06-02
// 수정 이력:
//		- 2024-06-05: ['string& objshpae' -> 'strint& objshape' 오타 수정] (작성자: 전인배)

#pragma once

#include <string>

class Object
{
protected:
	int objX; // 물체의 x 좌표
	int objY; // 물체의 y 좌표
	int objWidth; // 물체의 너비
	int objHeight; // 물체의 높이
	std::string objShape; // 물체의 현재 모양을 나타내는 문자열 (ex: "Dino" )
	

public:
	// 생성자
	Object(int objX, int objY, int objWidth, int objHeight, std::string& objShape);

	// 좌표 설정자
	void setPosition(int objX, int objY);

	// 크기 설정자
	void setSize(int objWidth, int objHeight);

	// 모양 설정자
	void setShape(std::string& objShape);

	// 좌표 접근자
	int getObj_x(); 
	int getObj_y(); 

	// 크기 접근자
	int getObj_Width(); 
	int getObj_Height(); 

	// 모양 접근자
	std::string getObj_Shape(); 

};