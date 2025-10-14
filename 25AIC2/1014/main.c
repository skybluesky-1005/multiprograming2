#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[4] = { 4, 3, 2, 1 };
    int* pArr = (int*)malloc(sizeof(int) * 4);

    // malloc 실패 시 즉시 종료
    if (pArr == NULL)
    {
        printf("malloc error\n");
        return 1;
    }

    for (int i = 0; i < 4; ++i)
    {
        *(pArr + i) = arr[i];
    }

    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", pArr[i]);
    }
    printf("\n");

    free(pArr);
    system("pause");
    return 0;
}