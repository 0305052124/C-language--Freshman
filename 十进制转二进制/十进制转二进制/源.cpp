#define _CRT_SECURE_NO_WARNINGS 1
//������һ��ʮ����ת���ɶ������� ������ÿλ��������˳���ŵ������У�Ȼ�������
#include<stdio.h>
int main()
{
	int n = 0;
	int arr[32] = { 0 };
	int i=0,j=0;

	printf("Please input a number:\n");
	scanf("%d", &n);//x��ʮ��������
	for (i = 1; i <= n; n /= 2)
	{
		if (n % 2 == 1)
		{
			arr[j] = 1;
		}
		else 
		{
			arr[j] = 0;
		}
		j++;
	}
	j -= 1;
	while (j >= 0)
	{
		printf("%d", arr[j]);
		j--;//�����ӡ
	}
	return 0;
}
