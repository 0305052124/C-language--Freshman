#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
//destΪǰ����ַ�����srcΪ����Ҫ�ӵ��ַ�����nΪҪ�������ַ�����
char* My_strncat(char* dest, const char* src, int n)
{
	char* ret = dest;  //��dest�׵�ַ������ret�У���֮��dest++�����У����Է����ҵ�
	assert(dest != NULL && src != NULL);  //��֤dest��src�ǿ�
	while (*dest != '\0')//��ָ������һ�����ң��ҵ�dest��β�ġ�\0��
		dest++;
	while (n && (*dest++ = *src++) != '\0')//��src����ַ�һ��������dest��
		//(*dest++ = *src++) ��ʾ�Ȱ�*src����*dest���ٰ�����ָ��ͬʱ������һλ�������´�ѭ����
		n--;   //ѭ����������
	*dest = '\0';      //�ַ�׷����ɺ���׷�ӡ�\0��
	return ret; //����dest�ַ�����ʼ��ַ
}
int main()
{
	char arr1[20] = "I LOVE YOU ";
	My_strncat(arr1, "SORRY", 3);
	//��������My_strncat�� ��arr1��Ӧ�����ַ���I LOVE YOU SOR
	printf("arr1: %s\n", arr1);
	return 0;
}