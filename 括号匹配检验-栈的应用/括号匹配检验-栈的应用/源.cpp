#define _CRT_SECURE_NO_WARNINGS 1
//       括号匹配检验
//假设表达式中包含三种括号：圆括号()、方括号[]和花括号{}，并且它们可以任意嵌套。
//例如{ [()] ()[{}] }或[{()}([])]等为正确格式，而{ [}()] 或[({ )]为不正确的格式。
//输入可以是任意表达式，但只对三种括号的匹配情况进行处理判断,如不匹配，给出错误提示。
// 
//输入：[(3 + 4)* { 5 } - 3]
//输出：true
//
//输入：[{3 + 6[}(3 + 5)]
//输出：required ‘]’
//
//输入：{}())]
//输出：required ‘(‘

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
//		}//括号入栈
//		else if (exp[i] == ')' && IsEmpty(&MyStack)==0 && GetTop(MyStack, &c) && c == '(')
//		{
//			Pop(&MyStack, &d);//匹配成功出栈
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
//			Pop(&MyStack, &d);//匹配成功出栈
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
//			Pop(&MyStack, &d);//匹配成功出栈
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
//	printf("请输入一个字符串: ");
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
    printf("请输入一个字符串: ");
    gets_s(a);
    int n = strlen(a);
    if (isValid(a)) printf("true");
    else printf("false");
}