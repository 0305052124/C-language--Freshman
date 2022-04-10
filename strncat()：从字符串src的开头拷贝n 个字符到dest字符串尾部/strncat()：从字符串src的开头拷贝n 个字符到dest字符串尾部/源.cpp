#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
//dest为前面的字符串，src为后面要加的字符串，n为要拷贝的字符个数
char* My_strncat(char* dest, const char* src, int n)
{
	char* ret = dest;  //将dest首地址储存在ret中，在之后dest++运算中，可以方便找到
	assert(dest != NULL && src != NULL);  //保证dest、src非空
	while (*dest != '\0')//用指针往后一个个找，找到dest结尾的‘\0’
		dest++;
	while (n && (*dest++ = *src++) != '\0')//把src里的字符一个个放入dest后
		//(*dest++ = *src++) 表示先把*src赋给*dest，再把两个指针同时往后移一位（方便下次循环）
		n--;   //循环跳出条件
	*dest = '\0';      //字符追加完成后，再追加’\0’
	return ret; //返回dest字符串起始地址
}
int main()
{
	char arr1[20] = "I LOVE YOU ";
	My_strncat(arr1, "SORRY", 3);
	//经过函数My_strncat后 ，arr1里应该是字符串I LOVE YOU SOR
	printf("arr1: %s\n", arr1);
	return 0;
}