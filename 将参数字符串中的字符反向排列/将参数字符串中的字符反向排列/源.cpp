#define _CRT_SECURE_NO_WARNINGS 1
//4. 编写一个函数 reverse_string(char* string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

#include<stdio.h>
char reverse_string(char* p)
{
	if (*p!=NULL)
	{
		p++;
		reverse_string(p);
		printf("%c", *(p - 1));
	}
	return 0;
}
int main()
{
	char a[] = "abc";
	printf("原字符串是：%s\n", a);
	printf("翻转后的字符串是：");
	reverse_string(a);
	return 0;
}

