#define _CRT_SECURE_NO_WARNINGS 1
//���ͳ�������������Ϊ����ĵڼ��죨�迼��ƽ���꣩
#include<stdio.h>
int main()
{
	int ret = 0;
	int i = 0;
	int year, month, day;
	int LeapYear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int CommYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("���������������գ�");
	scanf("%d %d %d", &year, &month, &day);
	if (year % 100 == 0 || (year % 4 == 0 && year % 100 != 0))//����29��
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
	printf("��%d��ĵ�%d��\n", year, ret + day);
	return 0;
}