#define _CRT_SECURE_NO_WARNINGS 1
////1������һ��ӵ��10��Ԫ�ص�float���顣
//Ҫ��(1)��forѭ���ṹ���Ӽ�����������Ԫ�ء�
//      (2)�ҳ�����������е����ֵmax����Сֵmin��

#include<stdio.h>
int main()
{
	int j = 0;
	float a[10] = { 0.0 };
	
	
	for (j = 0; j < 10; j++)
	{
		scanf("%f", &a[j]);
	}
	float max=a[0];
	float min = a[0];
	for (j = 0; j < 10; j++)
	{
		if (a[j] > max)
		{
			max = a[j];
		}
		if (a[j] < min)
		{
			min = a[j];
		}
     }
	
	for (j = 0; j < 10; j++)
	{
		printf("%f\n ", a[j]);
	}	
	printf("��Сֵ��%f\n ", min);
	printf("���ֵ��%f\n ", max);
	return 0;
}
