#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>

//dest为目标数组，src为源数组，n为要复制的字符个数
char* My_strncpy(char* dest, const char* src, int n)
{
	assert(dest != NULL);//保证dest非空
	assert(src != NULL); //保证src非空
	char* ret = dest;    //将dest首地址储存在ret中，在之后dest++运算中，可以方便找到
	while (n)   //一次复制一个字符，要复制n次
	{
		*dest = *src;  //复制
		src++;    //源地址往后+1
		dest++;   //目标地址往后+1
		n--;      //跳出循环条件
	}
	return ret;  //返回目的数组的首地址
}
int main()
{
	char arr1[] = "I LOVE YOU";
	char arr2[] = "SORRY";
	My_strncpy(arr1, arr2, 5);
	//经过函数My_strncpy后 ，arr1里应该是字符串 SORRYE YOU
	printf("arr1: %s\n", arr1);
	return 0;
}