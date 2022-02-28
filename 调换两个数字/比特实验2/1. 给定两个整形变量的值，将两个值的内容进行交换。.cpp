#define _CRT_SECURE_NO_WARNINGS 1
// 给定两个整形变量的值，将两个值的内容进行交换。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int j =0;
	int n = 0;
	printf("请输入两个要交换的数字：\n");
	scanf("%d%d", &i, &j);
	n = i;
	i= j;
	j = n;
	printf("%d %d", i, j);

	return 0;
}