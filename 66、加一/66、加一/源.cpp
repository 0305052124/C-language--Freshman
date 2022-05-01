#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    int* a = (int*)malloc(sizeof(int) * (digitsSize + 1));
    a[0] = 1;
    for (int i = 0; i < digitsSize; i++)
    {
        a[i + 1] = digits[i];
    }
    free(digits);
    *returnSize = digitsSize + 1;
    return a;
}
int main()
{
    int digits[100] = { 1,2,3,9 };
    int size = 0;
    int *p=plusOne(digits, 4, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *p);
        p++;
    }
    printf("]");
    return 0;
}
 