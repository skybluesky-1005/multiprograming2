#include<stdio.h>
#include<stdlib.h>

#define num 20

int main()
{
	srand(time(NULL));

	int a[num];
	int b[num];
	int index[num];
	printf("	");
	for (int i = 0; i < num; i++)
	{
		index[i] = i;
		printf("%4d ", index[i]);
	}

	printf("\n\na	");
	int i = 0;

	while (i < num)
	{
		a[i] = rand() % num;

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
	for (int i = 0; i < num; i++)
	{
		int aindex = -1;
		for (int j = 0; j < num; j++)
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