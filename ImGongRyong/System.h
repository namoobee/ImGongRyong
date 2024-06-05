// 파일 이름: System.h
// 설명: 이 파일은 System 클래스의 선언을 포함하고 있습니다. System 클래스는 게임에서 시간과 점수, 일시정지를 관리 합니다.
// 작성자: 전인배
// 작성 날짜: 2024-06-04
// 수정 이력:
//		- 2024-06-05 ['calculateTimeScore', 'isgamePaused' 추가] (작성자: 전인배)


#pragma once

class System
{
protected:
	int startTime; // 시작 시간
	int currentTime; // 현재 시간 (실제 플레이 시간)
	int timeScore; // 시간 점수
	int coinScore; // 코인 점수
	int totalScore; // 총 점수
	bool isPaused; // 게임이 일시정지 상태인지 확인

public:
	System(); // 생성자

	// 시간 관련 메서드
	void startTimer(); // 타이머 시작
	void updateTime(); // 현재 시간 업데이트
	void calculateTimeScore(); // 시간 점수 계산

	// 코인 관련 메서드
	void addCoinScore(int coins); // 코인 점수 추가

	// 총 점수 계산
	void calculateTotalScore(); // 게임 종료시 총 점수 계산

	// 점수 반환 메서드
	int getTotalScore(); // 총 점수 반환

	// 일시 정지 관련 메서드
	void pauseGame(); // 게임 일시 정지
	void resumeGame(); // 게임 재개
	bool isGamePaused(); //게임 일시 정지 여부 반환
};