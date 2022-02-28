#define _CRT_SECURE_NO_WARNINGS 1
//编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
//小写转大写，对应的ASCII码值减32，大写转小写，则加32
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
//	while ((ch = getchar()) != EOF)//getchar 从标准输入返回下一个字符,一次只打印一个字符
//	{
//		if (ch >= ‘a’ && ch <= ‘z’)
//			//利用ASCLL码表,大写和小写之间相差32
//		{
//			putchar(ch - 32);
//		}
//		else if (ch >= ‘A’ && ch <= ‘Z’)
//		{
//			putchar(ch + 32);
//		}
//		else if (ch >= ‘0’ && ch <= ‘9’)
//		{
//			;
//		}
//	}
//	system(“pause”);
//	return 0;
//}
