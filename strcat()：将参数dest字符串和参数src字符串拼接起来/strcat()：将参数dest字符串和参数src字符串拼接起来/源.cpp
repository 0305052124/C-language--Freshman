#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
//destΪǰ����ַ�����srcΪ����Ҫ�ӵ��ַ���
//dest��Ϊ�ڴ�Ҫ�ı䣬���Բ��ܼ�const����src���ϸ���
char* My_strcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);  //��֤dest��src�ǿ�
	char* ret = dest;    //��dest�׵�ַ������ret�У���֮��dest++�����У����Է����ҵ�
	while (*dest != '\0')  //��ָ������һ�����ң��ҵ�dest��β�ġ�\0��
		dest++;
	while ((*dest++ = *src++) != '\0')//��src����ַ�һ��������dest��
		;
	return ret;  //����dest�ַ�����ʼ��ַ
}
int main()
{
	char arr1[20] = "I LOVE YOU";
	My_strcat(arr1, " SORRY");
	//��������My_strcat�� ��arr1��Ӧ�����ַ���I LOVE YOU SORRY
	printf("arr1: %s\n", arr1);
	return 0;
}
