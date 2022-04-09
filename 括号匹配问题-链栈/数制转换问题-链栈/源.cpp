#define _CRT_SECURE_NO_WARNINGS 1
#include"SLNode.h"
void  ExpIsCorrect(char exp[], int n)
{
	int i;	
	char c;
	DataType d;
	LSNode MyStack;
	LinkStack head = CreateLinkStack();
	for (i = 0; i < n; i++)
	{
		if ((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
		{
			Push(head, exp[i]); 
		}//括号入栈
		else if (exp[i] == ')' && IsEmpty(&MyStack) == 0 && GetTop(&MyStack, &c) && c == '(')
		{
			Pop(&MyStack, &d);//匹配成功出栈
		}
		else if (exp[i] == ')' && IsEmpty(&MyStack) == 0 && GetTop(&MyStack, &c) && c != '(')
		{
			if (c == '[')
				printf("required ']' \n");
			else
				printf("required '}' \n");
			return;
		}
		else if (exp[i] == ']' && IsEmpty(&MyStack) == 0 && GetTop(&MyStack, &c) && c == '[')
		{
			Pop(&MyStack, &d);//匹配成功出栈
		}
		else if (exp[i] == ']' && IsEmpty(&MyStack) == 0 && GetTop(&MyStack, &c) && c != '[')
		{
			if (c == '(')
				printf("required ')' \n");
			else
				printf("required '}' \n");
			return;
		}
		else if (exp[i] == '}' && IsEmpty(&MyStack) == 0 && GetTop(&MyStack, &c) && c == '{')
		{
			Pop(&MyStack, &d);//匹配成功出栈
		}
		else if (exp[i] == '}' && IsEmpty(&MyStack) == 0 && GetTop(&MyStack, &c) && c != '{')
		{
			if (c == '[')
				printf("required ']' \n");
			else
				printf("required ')' \n");
			return;
		}
		else if ((exp[i] == ')') && IsEmpty(&MyStack) == 1)
		{
			printf("required '( '\n");
			return;
		}
		else if ((exp[i] == ']') && IsEmpty(&MyStack) == 1)
		{
			printf("required '['\n");
			return;
		}
		else if ((exp[i] == '}') && IsEmpty(&MyStack) == 1)
		{
			printf("required '{ '\n");
			return;
		}
	}
	if (IsEmpty(&MyStack) == 1)
	{
		printf("ture\n");
	}
}
int main(void)
{
	char a[MaxSize];
	printf("请输入一个字符串: ");
	gets_s(a);
	int n = strlen(a);
	ExpIsCorrect(a, n);
}