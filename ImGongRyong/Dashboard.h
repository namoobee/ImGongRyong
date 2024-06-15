#pragma once

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>

using namespace std;

class Dashboard
{
public:
	Dashboard();

	// 콘솔창의 중앙을 계산(문자, 색깔)
	void printCenteredText(const string& text, const string& textColor = "");

	// 메인화면 출력
	void displayMainMenu();

	// 선택화면 출력
	int getUserChoice();

	// 게임 조작법 
	void displayControls();
};