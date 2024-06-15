#pragma once

#include "Dashboard.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <conio.h>


using namespace std;

class Storage : public Dashboard
{
protected:
	const string HighScoresFile = "HighScore.txt";
public:
	// 점수 저장 묻기
	void askSaveScore(int score);
	// 점수 저장 하기
	void saveScore(int score);
	// 랭킹 보기
	int displayRanking();
};