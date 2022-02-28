#define _CRT_SECURE_NO_WARNINGS 1
//1.创建一个数组，实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
#include<stdio.h>
void init(int arr[], int sz)//函数init（）初始化数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 2 * i - 1;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void empty(int arr[], int sz)//empty（）清空数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[], int sz)//reverse（）数组元素的逆置
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
