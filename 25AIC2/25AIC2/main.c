#include<stdio.h>

int main()
{
	for (int i = 0; i <= 15; i++)
	{
		if (i >= 5 && i < 9) printf("\x1B[B\x1B[D");
		if (i >= 9 && i < 13) printf("\x1B[2D");
		if (i >= 13 && i <= 15) printf("\x1B[A\x1B[D");
		printf("*");
	}
	printf("\x1B[5B");
}