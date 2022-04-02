#define _CRT_SECURE_NO_WARNINGS 1
//Stack On Sequence Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Stack_Size  100
#define FALSE   0
#define TRUE    1

typedef int DataType; //数据元素类型定义
DataType x;

//顺序栈的定义
typedef struct {  
	DataType  elem[Stack_Size];//Stack表示顺序堆栈存放元素的数组
	int top;//top表示顺序堆栈数组Stack的当前栈顶位置
}SeqStack;

void  InitStack(SeqStack* S);//初始化栈 
int IsEmpty(SeqStack* S);//判空 
int IsFull(SeqStack* S);//判满 
int Push(SeqStack* S, DataType x); //进栈 
int Pop(SeqStack* S, DataType* x); //出栈 
int GetTop(SeqStack S, DataType* x); //取栈顶元素 
void PrintStack(SeqStack* S); //打印栈元素(从栈顶到栈底顺序) 

int main()
{
	SeqStack S;  //创建一个线性表 
	char sel = ' ';
	while (sel != '0')//生成菜单 
	{
		printf("------栈(顺序存储结构)演示系统-------\n");
		printf(" 版本:1.0 作者:金春依 日期:2022-04-01\n");
		printf("------------------------------------------\n");
		printf("       1.初始化栈\n");
		printf("       2.进栈操作\n");
		printf("       3.出栈操作\n");
		printf("       4.打印栈顶元素\n");
		printf("       5.打印栈\n");
		printf("       6.清空屏幕\n");
		printf("       0.退出系统\n");
		printf("请输入选项[0-6]:\n");
		sel = getchar();
		int i;
		switch (sel)
		{
		case '1':
			printf("初始化栈.\n");
			InitStack(&S);
			system("pause");
			break;
		case '2':
			printf("进栈操作.\n");
			printf("进栈之后的元素依次为： ");
			for (i = 0; i < 10; i++)
			{
				Push(&S, i+1); 
			}
			PrintStack(&S); //打印栈元素(从栈顶到栈底顺序)  
			system("pause"); 
			break;
		case '3':
			printf("出栈操作.\n");
			Pop(&S, &x);
			printf("出栈元素为：%d\n", x);
			PrintStack(&S); //打印栈元素(从栈顶到栈底顺序)  
			system("pause"); 
			break;
		case '4':
			printf("打印栈顶元素操作.\n");
			GetTop( S, &x);
			printf("当前栈顶元素为：%d\n", x);
			PrintStack(&S); //打印栈元素(从栈顶到栈底顺序)
			system("pause");
			break;
		case '5':
			printf("打印栈操作.\n");
			PrintStack(&S); //打印栈元素(从栈顶到栈底顺序)  
			system("pause"); 
			break;
		case '6':
			system("cls");
			break;
		case '0':
			printf("\n谢谢使用，再见！\n");
			break;
		default:
			printf("您输入的选项不合法，请重新选择！\n");
		}
	}
	return 0;
}

void  InitStack(SeqStack* S)//初始化栈 
{
	S->top = 0;//初始化一个空栈：初始化栈顶下标值，top=0表示该栈为空栈
}

int IsEmpty(SeqStack* S)//判空
{
	//判断顺序堆栈S非空否，若非空返回FALSE，空返回TRUE
	if (S->top <= 0)
		return FALSE;
	else
		return TRUE;
}

int IsFull(SeqStack* S)//判满 
{
	//判断顺序堆栈S满不满，若满返回FALSE，不满返回TRUE
	if (S->top >= Stack_Size)
	{
		printf("堆栈已满无法插入! \n");
		return FALSE;
	}
	else
		return TRUE;
}
int Push(SeqStack* S, DataType x) //进栈
{
	//把x存入顺序堆栈S中，若入栈成功则返回TRUE，失败返回FALSE
	if (S->top >= Stack_Size)//判断栈满
	{
		printf("堆栈已满无法插入! \n");
		return FALSE;
	}
	else
	{
		S->top++;//指针加1，放元素, return
		S->elem[S->top-1] = x;
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
		*x = S->elem[S->top];
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
		*x = S.elem[S.top-1];
		return TRUE;
	}
}
void PrintStack(SeqStack* S) //打印栈元素(从栈顶到栈底顺序) 
{
	int i = 0;
	while(i<S->top)
	{
		printf("%d ", S->elem[i]);
		i++;
	}
	printf("\n ");
}











