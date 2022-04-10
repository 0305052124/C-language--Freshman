#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
int My_strncmp(const char* str1, const char* str2, int n)
{
	if (!n)
		return 0;
	while (--n && *str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char str1[] = "SSLOVE YOU ";
	char str2[] = "SORRY";
	//经过手算可发现O的ACSII=79，S的ACSII=83,应该返回4 
	printf("%d\n", My_strncmp(str1, str2, 2));
	return 0;
}