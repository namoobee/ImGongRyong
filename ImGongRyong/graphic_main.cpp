# include "Graphic.h"

int main()
{
	BYTE count = 0;
	char* dino;
	char* pillar;
	int phase = 1;

	while (1)
	{
		Sleep(500); // 0.5√  µÙ∑π¿Ã
		system("cls");

		//dino = make_dino(count % 2 + 1);


		if (phase < 4)
		{
			if (count > 20 && count <= 50 )
				phase=2;
			 
			if (count > 50 && count <= 100)
				phase=3;
		}
			

		pillar = make_pillar(phase);
		
		/*for (int y = 0; y < DINO_HEIGHT; y++)
		{
			for (int x = 0; x < DINO_WIDTH; x++)
				putchar(dino[y * DINO_WIDTH + x]);

			putchar('\n');
		}*/

		for (int y = 0; y < CONSOLE_Y; y++)
		{
			for (int x = 0; x < DINO_WIDTH; x++)
				putchar(pillar[y * DINO_WIDTH + x]);
			
			putchar('\n');
		}

		//delete[] dino;
		printf("\n\n%d\n", phase);
		delete[] pillar;
		count++;
	}

	return 0;
}