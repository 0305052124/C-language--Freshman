#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqStack.h"
void  InitStack(SeqStack* S)//初始化栈 
{
	S->top = 0;//初始化一个空栈：初始化栈顶下标值，top=0表示该栈为空栈
}
int IsEmpty(SeqStack* S)//判空
{
	//判断顺序堆栈S非空否
	if (S->top <= 0)
		return TRUE;//栈空返回1
	else
		return FALSE;//非空返回0
}
int Push(SeqStack* S, DataType x) //进栈
{
	//把x存入顺序堆栈S中，若入栈成功则返回TRUE，失败返回FALSE
	if (S->top >= MaxSize)//判断栈满
	{
		printf("堆栈已满无法插入! \n");
		return FALSE;
	}
	else
	{
		S->top++;//指针加1，放元素, return
		S->data[S->top - 1] = x;
		return TRUE;
	}
}
int GetTop(SeqStack S, DataType* x) //取栈顶元素
{
	//取顺序堆栈S的当前栈顶元素，由参数x带回
	//成功返回TRUE，失败返回FALSE

	if (S.top <= 0)//失败情况：栈空，无元素可取
	{
		printf("堆栈已空,无元素可取! \n");
		return FALSE;
	}
	else//栈非空，取元素，减指针，return
	{
		*x = S.data[S.top - 1];
		return TRUE;
	}
}



int Pop(SeqStack* S, DataType* x)//出栈 
{
	//取出顺序栈顶S的栈顶元素，由参数x带回
	//出栈成功返回TRUE，失败返回FALSE
	//失败情况：栈空，无元素可出栈
	if (S->top <= 0)
	{
		printf("堆栈已空无法出栈! \n");
		return FALSE;
	}
	else//栈非空，取元素，减指针，return
	{
		S->top--;
		*x = S->data[S->top];
		return TRUE;
	}
}