#include<stdio.h>
#include<stdlib.h>

#define NUM 20

int main()
{
	srand(time(NULL));

	int a[NUM];
	int b[NUM];
	int index[NUM];
	printf("	");
	for (int i = 0; i < NUM; i++)
	{
		index[i] = i;
		printf("%4d ", index[i]);
	}

	printf("\n\na	");
	int i = 0;

	while (i < NUM)
	{
		a[i] = rand() % NUM;

		int duplicate = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[i])
			{
				duplicate = 1;
				break;
			}
		}

		if (!duplicate)
		{
			printf("%4d ", a[i]);
			i++;
		}
	}
	printf("\nb	");
	for (int i = 0; i < NUM; i++)
	{
		int aindex = -1;
		for (int j = 0; j < NUM; j++)
		{
			if (i == a[j])
			{
				aindex = j;
				break;
			}
		}
		b[i] = aindex;
		printf("%4d ", b[i]);
	}
	return 0;
}