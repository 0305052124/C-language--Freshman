#define _CRT_SECURE_NO_WARNINGS 1
//����Swap(), �ú������ʵ�����������ж�ӦԪ��ֵ�Ľ���
#include<stdio.h>
void Swap(int a[], int b[])
{
	int temp = 0;
	for (int i = 5; i >= 0; i--)
	{
		temp=a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("a[]=");
	for (int j = 0; j < 5; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
	printf("b[]=");
	for (int j = 0; j < 5; j++)
	{
		printf("%d ", b[j]);
	}
	printf("\n");

}
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 5,4,3,2,1 };
	Swap(a,b);
	return 0;
}