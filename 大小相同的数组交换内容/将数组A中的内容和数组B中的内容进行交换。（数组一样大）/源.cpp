#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a2[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int i = 0;
	int t=0;
	for (i = 0; i < 10; i++)
	{
		t = a1[i];
		a1[i] = a2[i];
		a2[i] = t;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a1[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a2[i]);
		}
	return 0;
}   