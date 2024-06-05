// 파일 이름: System.cpp
// 설명: 이 파일은 System 클래스의 구현을 포함하고 있습니다. (시스템)
// 작성자: 전인배
// 작성 날짜: 2024-06-04
// 수정 이력:
//		- 2024-06-05 ['calculateTimeScore', 'isgamePaused' 추가] (작성자: 전인배)

#include <ctime>
#include "System.h"

// 생성자
System::System()
{
	this->startTime = 0;
	this->currentTime = 0;
	this->timeScore = 0;
	this->coinScore = 0;
	this->totalScore = 0;
	this->isPaused = false;
}

// 게임을 시작할 때의 현재 시간을 시작 시간으로 설정
void System::startTimer()
{
	startTime = clock();
}


// 현재 시간 업데이트
void System::updateTime()
{
	if (isPaused) 
	{
		currentTime = clock();
	}
}

// 시간 점수 계산
void System::calculateTimeScore()
{
	updateTime();
	double overedTime = double(currentTime - startTime) / CLOCKS_PER_SEC; // 경과 시간을 초 단위로 계산

	// 결과를 정수형으로 변환.(소수점 이하는 버리지만 10을 곱해 0.1초 단위 계산 가능) 
	timeScore = static_cast<long>(overedTime * 10); // 0.1초당 1점으로 계산
}

// 코인 점수 추가
void System::addCoinScore(int coins)
{
	coinScore += coins;
}

// 일시 정지
void System::pauseGame()
{
	if (isPaused)
	{
		currentTime = clock() - startTime;
		isPaused = true;
	}
}

// 게임 재개
void System::resumeGame()
{
	if (!isPaused) 
	{
		startTime = clock() - currentTime;
		isPaused = false;
	}
}

// 현재 게임의 총 점수를 계산(시간 점수 + 코인 점수)
void System::calculateTotalScore()
{
	if (!isPaused)
	{
		calculateTimeScore(); // timeScore를 계산
	}
	totalScore = timeScore + coinScore;
}

// 게임의 총 점수를 반환
int System::getTotalScore()
{
	return totalScore;
}

// 현재 게임이 일시 정지 상태인지 여부를 반환
bool System::isGamePaused()
{
	return isPaused;
}