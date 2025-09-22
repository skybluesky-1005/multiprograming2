#include<stdio.h>
#include<stdlib.h>

#define value 50

int main()
{
	srand(time(NULL));

	int a[value];
	int b[value];

	for (int i = 0; i < value; i++)
	{
		a[i] = rand() % value;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				i--;
			}
		}
		printf("%d ", a[i]);
	}
	printf("\n========================================================================================================================\n");
	for (int i = 0; i < value; i++)
	{
		int aindex = -1;
		for (int j = 0; j < value; j++)
		{
			if (i == a[j])
			{
				aindex = j;
				break;
			}
		}
		b[i] = aindex;
		printf("%d ", b[i]);
	}
	return 0;
}