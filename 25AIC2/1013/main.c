#include <stdio.h>

int main()
{
	int number[16][8];

	int i = 0;
	for (i = 0; i < 8; i++)
	{
		int j = 0;
		for (j = 0; j < 16; j++)
		{
			number[j][i] = (i + j) * 2;
			printf("%3d", number[j][i]);
		}
		printf("\n");
	}

	printf("%d", *(number[15]) + 3);
}