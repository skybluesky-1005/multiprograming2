#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{
    //폭탄은 항상 7칸
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )");
}

int main()
{
    // 여기부터 코드를 작성하세요----------------------
    int x = 14;
    int y = 9;
    int n = 2; 
    int preX, preY;
    moveCursor(x, y);
    printf("*");
    for (int i = 1; i <= 12; i ++)
    {
        for (int j = 1; j <= n; j++)
        {
            //if 조건으로 사용되는 식은 제미나이 참고
            if ((i - 1) % 4 == 0) y++;
            if ((i - 2) % 4 == 0) x++;
            if ((i - 3) % 4 == 0) y--;
            if ((i - 4) % 4 == 0) x--;
            moveCursor(x, y);
            printf("#");
        }
        //2번 꺾을 때마다 #의 수가 2씩 증가
        if ((i % 2) == 0) n += 2;
    }
    moveCursor(0, 3);
    printBomb(0);

    x = 14; preX = 14;
    y = 9; preY = 9;
    n = 2;
    moveCursor(x, y);
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Sleep(200);
            if ((i - 1) % 4 == 0) y++;
            if ((i - 2) % 4 == 0) x++;
            if ((i - 3) % 4 == 0) y--;
            if ((i - 4) % 4 == 0) x--;
            moveCursor(x, y);
            printf("*");

            moveCursor(preX, preY);
            printf(" ");
            preX = x;
            preY = y;
        }
        if ((i % 2) == 0) n += 2;
    }
    //폭탄 옆 마지막 * 삭제
    moveCursor(preX, preY);
    printf(" ");

    moveCursor(0, 3);
    printBomb(1);


    // 여기까지 코드를 작성하세요----------------------   
    moveCursor(10, 20);
    return 0;
}
