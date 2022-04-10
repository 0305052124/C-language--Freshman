#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
//dest为前面的字符串，src为后面要加的字符串
//dest因为内存要改变，所以不能加const，而src加上更好
char* My_strcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);  //保证dest、src非空
	char* ret = dest;    //将dest首地址储存在ret中，在之后dest++运算中，可以方便找到
	while (*dest != '\0')  //用指针往后一个个找，找到dest结尾的‘\0’
		dest++;
	while ((*dest++ = *src++) != '\0')//把src里的字符一个个放入dest后
		;
	return ret;  //返回dest字符串起始地址
}
int main()
{
	char arr1[20] = "I LOVE YOU";
	My_strcat(arr1, " SORRY");
	//经过函数My_strcat后 ，arr1里应该是字符串I LOVE YOU SORRY
	printf("arr1: %s\n", arr1);
	return 0;
}
