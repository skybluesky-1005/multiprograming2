#include<stdio.h>
#include<Windows.h>

int draw()
{
	printf("(B)");
	for (int i = 1; i <= 25; i++)
	{
		if (i <= 5)
		{
			if (i == 5) printf("+");
			else printf("-");
		}

		if (i > 5 && i <= 9)
		{
			printf("\x1B[B\x1B[D");

			if (i == 9) printf("+");
			else printf("|");
		}
		if (i > 9 && i <= 13)
		{
			printf("\x1B[2D");

			if (i == 13) printf("+");
			else printf("-");
		}
		if (i > 13 && i <= 16)
		{
			printf("\x1B[A\x1B[D");

			if (i == 16) printf("+");
			else printf("|");
		}
		if (i > 16 && i <= 19)
		{
			if (i == 19) printf("+");
			else printf("-");
		}
		if (i > 19 && i <=21)
		{
			printf("\x1B[B\x1B[D");
			
			if (i == 21) printf("+");
			else printf("|");
		}
		if (i > 21 && i <= 23)
		{
			printf("\x1B[2D");
			
			if (i == 23) printf("+");
			else printf("-");
		}
		if (i > 23 && i <= 24)
		{
			printf("\x1B[A\x1B[D");
			
			if (i == 24) printf("+");
			else printf("|");
		}
		if (i == 25) printf("*");
	}
}
int fire()
{
	for (int i = 25; i >= 1; i--)
	{
		Sleep(500);
		
		if (i == 25)
		{
			printf("\x1B[D");
			printf(" ");
		}
		if (i >= 24)
		{
			printf("\x1B[2D");
			printf(" ");
		}
	}
}
int main()
{
	draw();
	fire();

	printf("\x1B[5B");
}