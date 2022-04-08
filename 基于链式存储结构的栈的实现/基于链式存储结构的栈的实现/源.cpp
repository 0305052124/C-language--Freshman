#define _CRT_SECURE_NO_WARNINGS 1
//Stack On Link Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define FALSE   0  //失败 
#define TRUE    1  //成功 

typedef int DataType; //数据元素类型定义
DataType x;
typedef struct node
{
	DataType  data;
	struct node* next;
}LSNode, * LinkStack;
LinkStack head;
LinkStack top; //top就是一个指针变量 

LinkStack CreateLinkStack();  //创建一个空的链栈并返回 
void  DestroyStack(LinkStack top);//释放栈的所有空间,包括头节点 
int IsEmpty(LinkStack top);//判空 
void Push(LinkStack top, DataType x); //进栈 
int Pop(LinkStack top, DataType* x); //出栈 
int GetTop(LinkStack top, DataType* x); //去栈顶元素 
void PrintStack(LinkStack top); //打印栈元素(从栈顶到栈底顺序) 
int main()
{	char sel = ' ';
	int num = 0;
	int ret = 0;
	while (sel != '0')//生成菜单 
	{
		printf("------栈(链式存储结构)演示系统-------\n");
		printf("   版本:1.0   作者:金春依 日期:2022-04-07\n");
		printf("------------------------------------------\n");
		printf("       1.创建空栈\n");
		printf("       2.进栈操作\n");
		printf("       3.出栈操作\n");
		printf("       4.打印栈顶元素\n");
		printf("       5.打印栈\n");
		printf("       6.清空屏幕\n");
		printf("       7.释放栈空间\n");
		printf("       0.退出系统\n");
		printf("请输入选项[0-7]:");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("创建空栈操作.\n");
			head = CreateLinkStack();  //创建一个空的链栈并返回 
			system("pause");
			break;
		case '2':
			printf("进栈操作.\n");
			printf("请输入进栈元素个数 \n");//改进进栈操作，可以输入进栈元素数量
			scanf_s("%d", &num);
			printf("请输入进栈元素 ");
			for (int i = 0; i < num; i++)
			{
				scanf_s("%d", &x);
				Push(head, x); //进栈  
			}
			printf("从栈顶到栈底顺序为：");
			PrintStack(head);
			system("pause"); 
			break;
		case '3':
			printf("出栈操作.\n");
			
				if (Pop(head, &x))
				{
					printf("出栈元素为: %d\n", x);
				}
				else
				{
					printf("出栈失败 \n");
				}
			printf("从栈顶到栈底顺序为：");
					PrintStack(head);
			system("pause"); 
			break;
		case '4':
			printf("打印栈顶元素操作.\n");
			if (GetTop(head, &x))
			{
				printf("栈顶元素为%d \n", x);
				PrintStack(head);
			}
			else
				printf("取栈顶元素失败 \n");
			system("pause"); 
			break;
		case '5':
			printf("打印栈操作.\n");
			PrintStack(head);
			system("pause"); 
			break;
		case '6':
			system("cls");
			break;
		case '7':
			printf("释放栈空间操作.\n");
			DestroyStack(head);
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

LinkStack CreateLinkStack()  //创建一个空的链栈并返回 
{
	LinkStack top = (LinkStack)malloc(sizeof(LSNode));
	if (top == NULL)
	{
		printf("内存分配失败");
	}
	top->next = NULL;
	return top;
}
void PrintStack(LinkStack top) //打印栈元素(从栈顶到栈底顺序) 
{
	LinkStack p = top->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int GetTop(LinkStack top, DataType* x) //取栈顶元素，不出栈 
{
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("堆栈已空出错！");
		return FALSE;
	}
	*x = p->data;
	return TRUE;
}

void DestroyStack(LinkStack top)//释放栈的所有空间,包括头节点 
{
	LinkStack p, p1;
	p = top;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int IsEmpty(LinkStack top)//判空 
{
	//判断堆栈是否非空，非空：return TRUE，空：return FALSE
	if (top->next == NULL)
		return FALSE;
	else
		return TRUE;
}
void Push(LinkStack top, DataType x) //进栈 
{
	//把元素x插入链式堆栈head的栈顶作为新的栈顶
	
	LinkStack p;
	p = (LinkStack)malloc(sizeof(LSNode));
	p->data = x;
	p->next = top->next;//新结点链入栈顶
	top->next = p;//新结点成为新的栈顶
}
int Pop(LinkStack top, DataType* x)//出栈 
{
	//出栈并把栈顶元素由元素x带回，若出栈成功return 1，失败return 0；
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("堆栈已空出错！\n");
		return FALSE;
	}
	else
	{
		top->next = p->next;
		*x = p->data;
		free(p);
		return TRUE;
	}
}