#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define true 1
#define false 0
#define num 3

int count = 0;
int  isPowerOfThree(int n)
{
    if (n == 1) return true;
    else if (n == 0 || n / num * num != n) return false;
    else
    {
        count++;
        return isPowerOfThree(n / num);
    }
}

int main()
{
    int x = 0;
    scanf_s("%d", &x);
    if (isPowerOfThree(x))
        printf("����%d��%d��%d�η�\n", x, num, count);
    else printf("����%d����%d���ݴη�\n", x, num);
}