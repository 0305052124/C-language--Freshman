#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Isyear(int year)
{
	if (year % 400 == 0 || ((year / 4 == 0) && year / 100 != 0))
	/*f (((year % 4 == 0) && year % 100 != 0) || year % 400 == 0)*/

	{
		return 1;
	}
	return 0;
}
int main()
{
	int year = 0;
	scanf("%d", &year);
	int ret = Isyear(year);
	if (ret == 1)
	{
		printf("%d年是闰年\n", year);
	}
	else
	{
		printf("%d年不是闰年\n", year);
	}
	return 0;
}
