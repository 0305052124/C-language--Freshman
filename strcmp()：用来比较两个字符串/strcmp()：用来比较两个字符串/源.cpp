#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
//以null结尾的字符串 const修饰防止字符串被修改，进行保护
int My_strcmp(const char* str1, const char* str2)
{
	assert(NULL != str1);
	assert(NULL != str2);//防御性编程
	while (*(unsigned char*)str1 == *(unsigned char*)str2)
	{
		if (*(unsigned char*)str1 != '\0')
		{
			return 0;//当*(unsigned char*)str1 ==*(unsigned char*)str2==‘\0'时两个字符串完全相等
		}
		str1++;  //比较下个字符
		str2++;
	}
	//*(unsigned char*)str1 与*(unsigned char*)str2的差值与返回值正负匹配
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}
int main()
{
	char str1[] = "I LOVE YOU ";
	char str2[] = "SORRY";
	//经过手算可发现I的ACSII=73，S的ACSII=83,应该返回-10 
	printf("%d\n", My_strcmp(str1, str2));
	return 0;
}