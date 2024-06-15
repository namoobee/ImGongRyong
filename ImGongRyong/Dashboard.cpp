#include "Dashboard.h"


Dashboard::Dashboard() {}

void Dashboard::printCenteredText(const string& text, const string& textColor)
{
    // 콘솔 핸들 가져오기
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        std::cerr << "오류: 콘솔 핸들을 가져올 수 없습니다." << endl;
        return;
    }

    // 콘솔 정보 가져오기
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        cerr << "오류: 콘솔 화면 버퍼 정보를 가져올 수 없습니다." << endl;
        return;
    }

    // 콘솔 창의 크기 계산
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // 텍스트가 중앙에 오도록 위치 계산
    int x = (consoleWidth - text.length()) / 2;

    // 커서 위치 설정
    COORD coord = { static_cast<SHORT>(x), csbi.dwCursorPosition.Y };
    SetConsoleCursorPosition(hConsole, coord);

    // ANSI 컬러 코드 적용
    std::cout << textColor << text;

    // 리셋 ANSI 컬러 코드
    if (!textColor.empty())
    {
        std::cout << "\033[0m"; // 리셋
    }

}

void Dashboard::displayMainMenu()
{

    // 화면 지우기
    system("cls");

    const string redColor = "\033[31m"; // 빨간색
    const string blueColor = "\033[34m"; // 파란색
    const string greenColor = "\033[032m"; // 초록색
    const string resetColor = "\033[0m"; // 흰색


    const vector<string> crong = {
        "=============================================",
        "=============================================",
        "                                             ",
        "  ####   #####      ####   ##   ###   #####  ",
        " #    #  #    #    #    #   ##   #   #     # ",
        "#        #    #   #      #  ##   #  #        ",
        "#        #####    #      #  # #  #  #        ",
        "#        #   #    #      #  #  # #  #    ####",
        "#        #    #   #      #  #   ##  #     # #",
        " #   ##  #     #   #    #   #   ##   #    # #",
        "  ####   ###    ##  ####   ###   #    ### # #",
        "                                             ",
        "=============================================",
        "============================================="
    };

    for (int i = 0; i < crong.size(); ++i)
    {
        if (i == 0 || i == 12)
        {
            cout << redColor;
        }
        else if (i == 1 || i == 13)
        {
            cout << blueColor;
        }
        else
        {
            cout << greenColor;
        }
        printCenteredText(crong[i]);
        cout << resetColor << endl; // 색 초기화 및 줄 바꿈
    }

    vector<string> menuItems =
    {
        "1. 게임 시작",
        "2. 랭킹 확인",
        "3. 게임 방법",
        "4. 게임 종료"
    };

    for (const auto& item : menuItems)
    {
        printCenteredText(item);
        cout << endl;
    }
    
    cout << endl;

    printCenteredText("선택한 항목을 입력해주세요: ");
}

// 사용자 입력 받기
int Dashboard::getUserChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

// 게임 조작법 표시
void Dashboard::displayControls()
{
    system("cls");
    const vector<string> Controls =
    {
        "                                   ",
        " 아기 익룡 크롱이 모험을 떠납니다! ",
        "                                   ",
        "   날개를 부지런히 움직여 주세요.  ",
        "                                   ",
        "코인을 먹어 추가 점수를 획득하세요.",
        "                                   ",
        "===================================",
        "|         게임 조작법 안내        |",
        "===================================",
        "|                                 |",
        "|   W: 크롱을 위로 이동시킵니다.  |",
        "|                                 |",
        "|  S: 크롱을 아래로 이동시킵니다. |",
        "|                                 |",
        "|     P: 게임을 정지 시킵니다.    |",
        "|                                 |",
        "===================================",
        "                                   "
    };
    for (int i = 0; i < Controls.size(); ++i)
    {
        printCenteredText(Controls[i]);
        cout << endl;
    }
    cout << endl;
    printCenteredText("아무 키나 누르면 메인 화면으로 돌아갑니다...");
    cout << endl;
}
