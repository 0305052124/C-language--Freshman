#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
//��null��β���ַ��� const���η�ֹ�ַ������޸ģ����б���
int My_strcmp(const char* str1, const char* str2)
{
	assert(NULL != str1);
	assert(NULL != str2);//�����Ա��
	while (*(unsigned char*)str1 == *(unsigned char*)str2)
	{
		if (*(unsigned char*)str1 != '\0')
		{
			return 0;//��*(unsigned char*)str1 ==*(unsigned char*)str2==��\0'ʱ�����ַ�����ȫ���
		}
		str1++;  //�Ƚ��¸��ַ�
		str2++;
	}
	//*(unsigned char*)str1 ��*(unsigned char*)str2�Ĳ�ֵ�뷵��ֵ����ƥ��
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}
int main()
{
	char str1[] = "I LOVE YOU ";
	char str2[] = "SORRY";
	//��������ɷ���I��ACSII=73��S��ACSII=83,Ӧ�÷���-10 
	printf("%d\n", My_strcmp(str1, str2));
	return 0;
}