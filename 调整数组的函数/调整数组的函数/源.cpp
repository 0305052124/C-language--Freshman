#define _CRT_SECURE_NO_WARNINGS 1
//1.����һ�����飬ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
#include<stdio.h>
void init(int arr[], int sz)//����init������ʼ������
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 2 * i - 1;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void empty(int arr[], int sz)//empty�����������
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[], int sz)//reverse��������Ԫ�ص�����
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0, j = sz - 1; i < j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr, sz);	
	reverse(arr, sz);
	empty(arr, sz);
	return 0;
}
