#define _CRT_SECURE_NO_WARNINGS 1
//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, 
//������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char arr1[20] = { 0 };
	char arr2[20] = {"123456"};//����
	for ( i = 0; i < 3;)
	{
      printf("���������룺");
	  scanf("%s", &arr1);
	  if (strcmp(arr1, arr2) == 0)//strcmp()�Ƚ������ַ���
	  {
		  printf("����������ȷ\n");
		  break;
	  }
	  else
	  {
		  i++;
	  }
	}
	if (i >= 3)
	{
		printf("�������������δ����˳�ϵͳ\n");
	}
	return 0;
}



