#define _CRT_SECURE_NO_WARNINGS 1
//����ݹ麯����ʽΪrecursion(int  level)
//Ҫ��:
//recursion(0)�������Ϊ��  �ŵ��ұ�����        �ҵ�С����
//recursion(2)�������Ϊ��  �ŵ��ұ����˱��ű����ҵ�С������ҵ���
//
//����������Ҫ��д���ݹ麯��recursion(int  level)

#include<stdio.h>
void recursion(int level)
{
	printf("����");
	if (!level)
	{
		printf("�ҵ�С����");
	}
	else
	{
		recursion(level - 1);
	}
	printf("����");
}
int main()
{
	int n = 0;
	printf("������һ�����֣�");
	scanf("%d", &n);
	printf("�ŵ��ұ�����");
	if (n == 0)
	{
		printf("�ҵ�С����");
	}
	else
	{
		recursion(n - 1);
	}
	return 0;
}


