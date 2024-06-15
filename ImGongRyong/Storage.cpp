#include "Storage.h"

// 점수 저장
void Storage::saveScore(int score)
{
	// 기존 파일을 읽기 위한 ifstream 객체 생성
	ifstream recordFile("HighScores.txt");

	// 점수와 이름을 저장
	vector<pair<int, string>> highScores;

	// 기존 랭킹 데이터를 파일에서 읽어와 벡터에 저장
	int currentScore;
	string initials;

	while (recordFile >> currentScore >> initials)
	{
		highScores.push_back({ currentScore, initials });
	}
	recordFile.close();

	// 이름 입력 받기
	Dashboard::printCenteredText("이름을 입력하세요: ");
	string name;
	cin >> name;

	// 새로운 점수와 이름을 벡터에 추가
	highScores.push_back({ score, name });

	// 벡터를 점수가 높은 순으로 정렬
	sort(highScores.begin(), highScores.end(), greater<pair<int, string>>());
	
	// 랭킹 10위까지만 유지하도록 벡터의 크기 조정
	highScores.resize(min(highScores.size(), static_cast<size_t>(10)));

	// 파일에 새로운 랭킹 데이터 저장
	ofstream recordOutFile("HighScores.txt");
	for (const auto& entry : highScores)
	{
		// 정렬된 랭킹 데이터를 파일에 쓰기
		recordOutFile << entry.first << " " << entry.second << endl;
	}
	recordOutFile.close();
}

// 랭킹 화면 출력
int Storage::displayRanking()
{
	ifstream recordFile("HighScores.txt");

	// 파일이 열리지 않을때 경고
	if (!recordFile)
	{
		Dashboard::printCenteredText("경고: 아직 랭킹이 없습니다. 게임을 플레이해서 저장해주세요.");
		cout << endl << endl;
		Dashboard::printCenteredText("아무 키나 누르면 메인 화면으로 돌아갑니다...");

		// Windows API를 사용하여 키 입력이 있을 때까지 대기
		while (!_kbhit()) {}

		// 키 입력 받기
		char key = _getch();

		return 0;
	}

	vector<pair<int, string>> highScores;

	int currentScore;
	string initials;
	
	// 파일에서 랭킹 데이터를 읽어와 벡터에 저장
	while (recordFile >> currentScore >> initials)
	{
		highScores.push_back({ currentScore, initials });
	}
	recordFile.close();

	system("cls"); // 화면 지우기

	const std::string redColor = "\033[31m"; // 빨간색
	const std::string greenColor = "\033[32m"; // 초록색
	const std::string yellowColor = "\033[33m"; // 파란색
	const std::string whiteColor = "\033[0m"; // 흰색
	
	// 랭킹 헤더 출력
	printCenteredText("********* Ranking *********", yellowColor);
	cout << endl;
	printCenteredText("***************************", greenColor);
	cout << endl;

	// 상위 10개의 랭킹만 출력
	int rank = 1;
	for (const auto& entry : highScores)
	{
		string scoreLine = to_string(rank) + ". 이름: " + entry.second + ", 점수: " + to_string(entry.first) + "점";
		printCenteredText(scoreLine, whiteColor); 
		cout << endl;
		rank++;
	}
	printCenteredText("***************************", greenColor);
	cout << endl;
	printCenteredText("***************************", yellowColor);
	cout << endl;

	// 출력된 랭킹 수 반환
	return highScores.size();
}

// 점수를 저장할지 묻기
void Storage::askSaveScore(int score)
{
	while (true)
	{
		cout << "점수를 저장하시겠습니까?(Y/N): ";
		char saveChoice;
		cin >> saveChoice;
		cin.ignore(); // 입력 버퍼 비우기

		// 입력을 소문자로 변환하여 처리
		saveChoice = tolower(saveChoice);

		if (saveChoice == 'y')
		{
			ifstream recordFile("HighScores.txt");

			// 파일이 없다면 생성
			if (!recordFile)
			{

				// 빈 파일 생성
				ofstream newFile("HighScores.txt");
				newFile.close();

				// 생성한 파일 다시 열기
				recordFile.open("HighScores.txt");
				if (!recordFile)
				{
					Dashboard::printCenteredText("경고: 'HighScores.txt' 파일이 생성되지 않습니다.");
					return;
				}
				Dashboard::printCenteredText("점수: ");
				cout << score << endl;

				// saveScore 호출하여 점수 저장
				saveScore(score);

				return;
			}

			recordFile.close();

			if (displayRanking()) // 랭킹 점수판 표시
			{
				Dashboard::printCenteredText("점수: ");
				cout << score << endl;

				// saveScore 호출하여 점수 저장
				saveScore(score);
			}
			break; // 저장 완료 후 반복문 종료
		}
		else if (saveChoice == 'n')
		{
			// n 을 입력했을 때 메인 화면으로 돌아가기
			return;
		}
		else
		{
			// 잘못된 입력 처리
			cout << "경고: 잘못된 입력입니다. 'y' 또는 'n'을 입력해주세요." << endl;
		}
	}
}
