#define _CRT_SECURE_NO_WARNINGS 1
//4. ��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

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
	printf("ԭ�ַ����ǣ�%s\n", a);
	printf("��ת����ַ����ǣ�");
	reverse_string(a);
	return 0;
}

