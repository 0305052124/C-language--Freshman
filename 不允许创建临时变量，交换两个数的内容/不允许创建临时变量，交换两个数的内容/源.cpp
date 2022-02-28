#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 3;
	int j = 9;
	i = i ^ j;
	j = i ^ j;
	i = i ^ j;
	printf("i=%d j=%d\n", i, j);
	return 0;
}