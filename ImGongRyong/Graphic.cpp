#include "Graphic.h"

// 객체 그래픽 생성

char* make_pillar(int phase)
{
	/*---------------------------------------*/
	// 1. 처음에 입구없는 기둥 생성
	/*---------------------------------------*/

	// 사이즈 20*200 출입문 없음
	int pillar_Size = DINO_WIDTH * CONSOLE_Y;
	char* pillar = new char[pillar_Size];
	
	for (int i = 0; i < pillar_Size; i++)
	{
		pillar[i] = '*';
	}

	/*---------------------------------------*/
	// 2. 페이즈에 맞는 입구의 높이 설정 1~3까지
	/*---------------------------------------*/
	
	// (페이즈에 맞는 높이) * 20 의 출입문 하나 생성

	srand(time(NULL));

	int voidWidth = DINO_WIDTH;
	int voidHeight;

	switch (phase)
	{
	case 1:
		voidHeight = 45;
		break;

	case 2:
		voidHeight = 35;
		break;

	case 3:
		voidHeight = 25;
		break;
	}

	/*---------------------------------------*/
	// 3. 설정된 높이에 따라 랜덤으로 위치를 선택
	/*---------------------------------------*/

	// y축이 사용할 수 있는 범위
	// 기존 기둥좌표는 0~199 여기서 페이즈에 맞는 높이를 빼주면 된다.

	int Yscope = 200 - voidHeight - 1;
	int Ypos = (rand()*rand()-2*rand()) % Yscope;


	/*---------------------------------------*/
	// 4. 설정된 좌표에서 설정된 높이만큼 입구 생성
	/*---------------------------------------*/


	for (int y = Ypos; y < Ypos + voidHeight; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			pillar[y * 20 + x] = ' '; // 빈공간은 스페이스 바;
		}
	}

	return pillar;
}

char* make_dino(long sequence)
{
    /*---------------------------------------*/
    // 1. 공룡생성
    /*---------------------------------------*/

    int dinoSize = DINO_WIDTH * DINO_HEIGHT;
    char* dino = new char[dinoSize + 1];
    
    char* write_begin = dino;

    /*---------------------------------------*/
    // 2. 공룡 시퀀스에 따라서 공룡모양 선택
    /*---------------------------------------*/

    // 빈칸 * 2 = 네모 하나
    if (sequence == 1)
    {
        strncpy(write_begin, "        *           ", 20); write_begin += 20;
        strncpy(write_begin, "     * **********   ", 20); write_begin += 20;
        strncpy(write_begin, "    ****O*********  ", 20); write_begin += 20;
        strncpy(write_begin, "    *********** **  ", 20); write_begin += 20;
        strncpy(write_begin, "    ******** **     ", 20); write_begin += 20;
        strncpy(write_begin, "    ********        ", 20); write_begin += 20;
        strncpy(write_begin, "     ******** * *   ", 20); write_begin += 20;
        strncpy(write_begin, "     ***   *****    ", 20); write_begin += 20;
        strncpy(write_begin, "      ***           ", 20); write_begin += 20;
        strncpy(write_begin, "      ******        ", 20); write_begin += 20;
        strncpy(write_begin, "      ********      ", 20); write_begin += 20;
        strncpy(write_begin, "      ******  ***   ", 20); write_begin += 20;
        strncpy(write_begin, "      * ** ***      ", 20); write_begin += 20;
        strncpy(write_begin, "*     ******  **    ", 20); write_begin += 20;
        strncpy(write_begin, "*     *    *        ", 20); write_begin += 20;
        strncpy(write_begin, "*  *********        ", 20); write_begin += 20;
        strncpy(write_begin, "*  **  ** **        ", 20); write_begin += 20;
        strncpy(write_begin, "*****  ** **        ", 20); write_begin += 20;
        strncpy(write_begin, " **    **  ***      ", 20); write_begin += 20;
        strncpy(write_begin, "       ****         ", 20); write_begin += 20;
    }
    else
    {
        strncpy(write_begin, "        *           ", 20); write_begin += 20;
        strncpy(write_begin, "     * **********   ", 20); write_begin += 20;
        strncpy(write_begin, "    ****O*********  ", 20); write_begin += 20;
        strncpy(write_begin, "    *********** **  ", 20); write_begin += 20;
        strncpy(write_begin, "    ******** **     ", 20); write_begin += 20;
        strncpy(write_begin, "    ********        ", 20); write_begin += 20;
        strncpy(write_begin, "     ******** * *   ", 20); write_begin += 20;
        strncpy(write_begin, "     ***   *****    ", 20); write_begin += 20;
        strncpy(write_begin, "      ***           ", 20); write_begin += 20;
        strncpy(write_begin, "      ******        ", 20); write_begin += 20;
        strncpy(write_begin, "      **********    ", 20); write_begin += 20;
        strncpy(write_begin, "      ******    *   ", 20); write_begin += 20;
        strncpy(write_begin, "      * ** ****     ", 20); write_begin += 20;
        strncpy(write_begin, "*     ******  *     ", 20); write_begin += 20;
        strncpy(write_begin, "*     *    *        ", 20); write_begin += 20;
        strncpy(write_begin, "*  *********        ", 20); write_begin += 20;
        strncpy(write_begin, "*  **  ** **        ", 20); write_begin += 20;
        strncpy(write_begin, "***** **    **      ", 20); write_begin += 20;
        strncpy(write_begin, " **  **      ***    ", 20); write_begin += 20;
        strncpy(write_begin, "     ****          ", 20); write_begin += 20;
    }

    *write_begin = '\0'; // Null 추가

    return dino;
}