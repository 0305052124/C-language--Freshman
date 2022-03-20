#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqStack.h"

void StackInitiate(SeqStack* S)//初始化顺序堆栈S
{
	S->top = 0;//初始化一个空栈：初始化栈顶下标值，top=0表示该栈为空栈，
}


int StackNotEmpty(SeqStack S)//非空否
{
	//判断顺序堆栈S非空否，若非空返回1，空返回0
	if (S.top <= 0)
	    return 0;
	else
		return 1;
}


int StackPush(SeqStack* S, DataType x)//入栈
{
	//把x存入顺序堆栈S中，若入栈成功则返回1，失败返回0
	//判断栈满
	if (S->top >= MaxStackSize)
	{
		printf("堆栈已满无法插入! \n");
        return 0;
	}
	else
	{
		//指针加1，放元素, return
		S->top ++;
		S->Stack[S->top/*-1*/] = x;
		return 1;
	}
}

int StackPop(SeqStack* S, DataType* d)//出栈
{
	//取出顺序栈顶S的栈顶元素，由参数d带回
	//出栈成功返回1，失败返回0
	// 
	//失败情况：栈空，无元素可出栈
	if (S->top <= 0)
	{
		printf("堆栈已空无法出栈! \n");
		return 0;
	}
	//站非空，取元素，减指针，return
	else
	{
		*d = S->Stack[S->top];
		S->top--;
		return 1;
	}
}
int StackTop(SeqStack S, DataType* d)//取栈顶元素
{
	//取顺序堆栈S的当前栈顶元素，由参数d带回
	//成功返回1，失败返回0
	
	//失败情况：栈空，无元素可取
	if (S.top <= 0)
	{
		printf("堆栈已空,无元素可取! \n");
		return 0;
	}
	else
	{
		*d = S.Stack[S.top ];
		return 1;
	}
}