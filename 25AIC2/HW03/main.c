#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
    //��ź�� �׻� 7ĭ
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
    // ������� �ڵ带 �ۼ��ϼ���----------------------
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
            //if �������� ���Ǵ� ���� ���̳��� ����
            if ((i - 1) % 4 == 0) y++;
            if ((i - 2) % 4 == 0) x++;
            if ((i - 3) % 4 == 0) y--;
            if ((i - 4) % 4 == 0) x--;
            moveCursor(x, y);
            printf("#");
        }
        //2�� ���� ������ #�� ���� 2�� ����
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
    //��ź �� ������ * ����
    moveCursor(preX, preY);
    printf(" ");

    moveCursor(0, 3);
    printBomb(1);


    // ������� �ڵ带 �ۼ��ϼ���----------------------   
    moveCursor(10, 20);
    return 0;
}
