#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>

//destΪĿ�����飬srcΪԴ���飬nΪҪ���Ƶ��ַ�����
char* My_strncpy(char* dest, const char* src, int n)
{
	assert(dest != NULL);//��֤dest�ǿ�
	assert(src != NULL); //��֤src�ǿ�
	char* ret = dest;    //��dest�׵�ַ������ret�У���֮��dest++�����У����Է����ҵ�
	while (n)   //һ�θ���һ���ַ���Ҫ����n��
	{
		*dest = *src;  //����
		src++;    //Դ��ַ����+1
		dest++;   //Ŀ���ַ����+1
		n--;      //����ѭ������
	}
	return ret;  //����Ŀ��������׵�ַ
}
int main()
{
	char arr1[] = "I LOVE YOU";
	char arr2[] = "SORRY";
	My_strncpy(arr1, arr2, 5);
	//��������My_strncpy�� ��arr1��Ӧ�����ַ��� SORRYE YOU
	printf("arr1: %s\n", arr1);
	return 0;
}