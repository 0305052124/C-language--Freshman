#define _CRT_SECURE_NO_WARNINGS 1
//       ����ƥ�����
//������ʽ�а����������ţ�Բ����()��������[]�ͻ�����{}���������ǿ�������Ƕ�ס�
//����{ [()] ()[{}] }��[{()}([])]��Ϊ��ȷ��ʽ����{ [}()] ��[({ )]Ϊ����ȷ�ĸ�ʽ��
//���������������ʽ����ֻ���������ŵ�ƥ��������д����ж�,�粻ƥ�䣬����������ʾ��
// 
//���룺[(3 + 4)* { 5 } - 3]
//�����true
//
//���룺[{3 + 6[}(3 + 5)]
//�����required ��]��
//
//���룺{}())]
//�����required ��(��

//#include"SeqStack.h"
//void  ExpIsCorrect(char exp[], int n)
//{
//	SeqStack MyStack;
//	int i;
//	char c;
//	DataType d;
//	InitStack(&MyStack);
//	for (i=0; i < n; i++)
//	{
//		if ((exp[i] == '(') ||( exp[i] == '[') || (exp[i] == '{'))
//		{
//			Push(&MyStack, exp[i]);
//		}//������ջ
//		else if (exp[i] == ')' && IsEmpty(&MyStack)==0 && GetTop(MyStack, &c) && c == '(')
//		{
//			Pop(&MyStack, &d);//ƥ��ɹ���ջ
//		}
//		else if (exp[i] == ')' && IsEmpty(&MyStack) == 0 && GetTop(MyStack, &c) && c != '(')
//		{
//			if (c == '[')
//				printf("required ']' \n");
//			else
//				printf("required '}' \n");
//			return ;
//		}
//		else if (exp[i] == ']' && IsEmpty(&MyStack) == 0 && GetTop(MyStack, &c) && c == '[')
//		{
//			Pop(&MyStack, &d);//ƥ��ɹ���ջ
//		}
//		else if (exp[i] == ']' && IsEmpty(&MyStack) == 0 && GetTop(MyStack, &c) && c != '[')
//		{
//			if (c == '(')
//				printf("required ')' \n");
//			else
//				printf("required '}' \n");
//			return;
//		}
//		else if (exp[i] == '}' && IsEmpty(&MyStack) == 0 && GetTop(MyStack, &c) && c == '{')
//		{
//			Pop(&MyStack, &d);//ƥ��ɹ���ջ
//		}
//		else if (exp[i] == '}' && IsEmpty(&MyStack) == 0 && GetTop(MyStack, &c) && c != '{')
//		{
//			if(c=='[')
//			printf("required ']' \n");
//			else 
//				printf("required ')' \n");
//			return ;
//		}
//		else if ((exp[i] == ')')&& IsEmpty(&MyStack)==1)
//		{
//			printf("required '( '\n");
//			return;
//		}
//		else if ((exp[i] == ']') && IsEmpty(&MyStack) == 1)
//		{
//			printf("required '['\n");
//			return;
//		}
//		else if ( (exp[i] == '}')&& IsEmpty(&MyStack) == 1)
//		{
//			printf("required '{ '\n");
//			return;
//		}
//	}
//	if(IsEmpty(&MyStack) == 1)
//	{
//		printf("ture\n");
//	}
//}
//
//int main(void)
//{
//	char a[MaxSize];
//	printf("������һ���ַ���: ");
//	gets_s(a);
//	int n = strlen(a);
//	ExpIsCorrect(a, n);
//}	
//
#include<stdio.h>
#include<string.h>
#define MaxSize 100

int isValid(char* s)
{
    char q[3500];
    char temp;
    int count = -1;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')  q[++count] = s[i];
        else
        {
            if (count < 0)          return 0;
            temp = q[count];
            if (s[i] == ')')
            {
                if (temp != '(')    return 0;
                else count--;
            }

            if (s[i] == '}')
            {
                if (temp != '{')    return 0;
                else count--;
            }
            if (s[i] == ']')
            {
                if (temp != '[')    return 0;
                else count--;
            }
        }
    }
    if (count >= 0) return 0;
    return 1;
}
int main(void)
{
    char a[MaxSize];
    printf("������һ���ַ���: ");
    gets_s(a);
    int n = strlen(a);
    if (isValid(a)) printf("true");
    else printf("false");
}