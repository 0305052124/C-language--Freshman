#define _CRT_SECURE_NO_WARNINGS 1
//��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
//Сдת��д����Ӧ��ASCII��ֵ��32����дתСд�����32
#include<stdio.h>
int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch - 32);
			printf("\n");
		}
		else if (ch >= 'A' && ch <= 'z')
		{
			putchar(ch + 32);
			printf("\n");
		}
		else if (ch >= '0' && ch <= '9')
		{
			;
		}
	}
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)//getchar �ӱ�׼���뷵����һ���ַ�,һ��ֻ��ӡһ���ַ�
//	{
//		if (ch >= ��a�� && ch <= ��z��)
//			//����ASCLL���,��д��Сд֮�����32
//		{
//			putchar(ch - 32);
//		}
//		else if (ch >= ��A�� && ch <= ��Z��)
//		{
//			putchar(ch + 32);
//		}
//		else if (ch >= ��0�� && ch <= ��9��)
//		{
//			;
//		}
//	}
//	system(��pause��);
//	return 0;
//}
