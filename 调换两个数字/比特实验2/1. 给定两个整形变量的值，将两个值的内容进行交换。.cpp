#define _CRT_SECURE_NO_WARNINGS 1
// �����������α�����ֵ��������ֵ�����ݽ��н�����
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int j =0;
	int n = 0;
	printf("����������Ҫ���������֣�\n");
	scanf("%d%d", &i, &j);
	n = i;
	i= j;
	j = n;
	printf("%d %d", i, j);

	return 0;
}