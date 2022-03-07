#define _CRT_SECURE_NO_WARNINGS 1
//编程统计输入的年月日为当年的第几天（需考虑平闰年）
#include<stdio.h>
int main()
{
	int ret = 0;
	int i = 0;
	int year, month, day;
	int LeapYear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int CommYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请依次输入年月日：");
	scanf("%d %d %d", &year, &month, &day);
	if (year % 100 == 0 || (year % 4 == 0 && year % 100 != 0))//闰年29天
	{
		for (i = 0; i < month-1; i++)
		{
			ret += LeapYear[i];
		}
	}
	else
	{
		for (i = 0; i < month-1; i++)
		{
			ret += CommYear[i];
		}
	}
	printf("是%d年的第%d天\n", year, ret + day);
	return 0;
}