#include "Dashboard.h"


Dashboard::Dashboard() {}

void Dashboard::printCenteredText(const string& text, const string& textColor)
{
    // �ܼ� �ڵ� ��������
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        std::cerr << "����: �ܼ� �ڵ��� ������ �� �����ϴ�." << endl;
        return;
    }

    // �ܼ� ���� ��������
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        cerr << "����: �ܼ� ȭ�� ���� ������ ������ �� �����ϴ�." << endl;
        return;
    }

    // �ܼ� â�� ũ�� ���
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // �ؽ�Ʈ�� �߾ӿ� ������ ��ġ ���
    int x = (consoleWidth - (int)text.length()) / 2;

    // Ŀ�� ��ġ ����
    COORD coord = { static_cast<SHORT>(x), csbi.dwCursorPosition.Y };
    SetConsoleCursorPosition(hConsole, coord);

    // ANSI �÷� �ڵ� ����
    std::cout << textColor << text;

    // ���� ANSI �÷� �ڵ�
    if (!textColor.empty())
    {
        std::cout << "\033[0m"; // ����
    }

}

void Dashboard::displayMainMenu()
{

    // ȭ�� �����
    system("cls");

    const string redColor = "\033[31m"; // ������
    const string blueColor = "\033[34m"; // �Ķ���
    const string greenColor = "\033[032m"; // �ʷϻ�
    const string resetColor = "\033[0m"; // ���


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
        cout << resetColor << endl; // �� �ʱ�ȭ �� �� �ٲ�
    }

    vector<string> menuItems =
    {
        "1. ���� ����",
        "2. ��ŷ Ȯ��",
        "3. ���� ���",
        "4. ���� ����"
    };

    for (const auto& item : menuItems)
    {
        printCenteredText(item);
        cout << endl;
    }
    
    cout << endl;

    printCenteredText("������ �׸��� �Է����ּ���: ");
}

// ����� �Է� �ޱ�
int Dashboard::getUserChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

// ���� ���۹� ǥ��
void Dashboard::displayControls()
{
    system("cls");
    const vector<string> Controls =
    {
        "                                   ",
        " �Ʊ� �ͷ� ũ���� ������ �����ϴ�! ",
        "                                   ",
        "   ������ �������� ������ �ּ���.  ",
        "                                   ",
        "������ �Ծ� �߰� ������ ȹ���ϼ���.",
        "                                   ",
        "===================================",
        "|         ���� ���۹� �ȳ�        |",
        "===================================",
        "|                                 |",
        "|   W: ũ���� ���� �̵���ŵ�ϴ�.  |",
        "|                                 |",
        "|  S: ũ���� �Ʒ��� �̵���ŵ�ϴ�. |",
        "|                                 |",
        "|     P: ������ ���� ��ŵ�ϴ�.    |",
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
    printCenteredText("�ƹ� Ű�� ������ ���� ȭ������ ���ư��ϴ�...");
    cout << endl;
}
