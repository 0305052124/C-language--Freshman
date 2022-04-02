#define _CRT_SECURE_NO_WARNINGS 1
//Linear Table On Sequence Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE  100
#define SUCCESS   0  //成功
#define FAIL 1  //失败

typedef int DataType; //数据元素类型定义
DataType x;
DataType y;
DataType px;

typedef struct {  //顺序表（顺序结构）的定义
	DataType elem[MAXSIZE];
	int last;//最后一个元素的位置
}SeqList;

//函数声明
void ListInitiate(SeqList* L);//初始化线性表
int ListLength(SeqList* L);//求线性表的长度，返回线性表L中数据元素个数
int ListInsert(SeqList* L, int i, DataType x);//第i位置插入元素x，插入成功返回SUCCESS,否则FAIL
int ListDelete(SeqList* L, int i); //删除表中第i个元素，删除成功返回SUCCESS,否则FAIL
int ListSearch(SeqList* L, DataType x);//查找表中元素x的位置，查找成功返回位置，否则返回-1 
void ListPrint(SeqList* L);//用（a1,a2,a3,...,an)个格式输出线性表
int ListGet(SeqList* L, int i, DataType* px);//取第i个元素，查找成功返回SUCCESS并把元素放入*px,查找失败返回FAIL 

int main()
{
	SeqList L;  //创建一个线性表 
	//生成菜单 
	char sel = ' ';
	while (sel != '0')
	{

		printf("------线性表(顺序存储结构)演示系统-------\n");
		printf("   版本:1.0   作者:金春依 日期:2022/03/21\n");
		printf("------------------------------------------\n");
		printf("       1.初始化线性表\n");
		printf("       2.查找元素位置\n");
		printf("       3.按位置查找元素\n");
		printf("       4.插入一个元素\n");
		printf("       5.删除一个元素\n");
		printf("       6.显示该线性表\n");
		printf("       7.清空屏幕\n");
		printf("       8.查看线性表长度\n");
		printf("       0.退出系统\n");
		printf("请输入选项[0-8]:\n");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("初始化线性表操作->\n");
			ListInitiate(&L);//初始化函数
			ListPrint(&L);//再打印一遍线性表
			system("pause"); //按任意键继续 
			break;
		case '2':
			DataType y;
			printf("查找元素操作->\n");
			printf("请输入要查找的元素：");
			scanf("%d", &y);
			if (ListSearch(&L, y) == -1)
			{
				printf("查找失败\n");
			}
			else
			{
				printf("元素%d当前地址为：<%d>", y, ListSearch(&L, y));
			}
			ListPrint(&L);//再打印一遍线性表
			system("pause"); //按任意键继续 
			break;
		case '3':
			int z;
			printf("按位置查找元素操作->\n");
			printf("请输入要查找的位置：");
			scanf("%d", &z);
			if (ListGet(&L, z, &px) == -1)
			{
				printf("查找失败\n");
			}
			else
			{
				printf("你要查地址为<%d>的当前元素为：%d", z, px);
			}
			ListPrint(&L);//再打印一遍线性表
			system("pause"); //按任意键继续 
			break;
		case '4':
			int i;
			printf("插入一个元素操作->\n");
			printf("请输入要插入的元素和位置：");
			scanf("%d%d", &x, &i);
			ListInsert(&L, i, x);//插入函数
			ListPrint(&L);//再打印一遍线性表
			system("pause"); //按任意键继续 
			break;
		case '5':
			int x;
			printf("删除一个元素操作->\n");
			printf("你要删除第几个元素：\n");
			scanf("%d", &x);
			ListDelete(&L, x);//删除函数
			ListPrint(&L);//再打印一遍线性表
			system("pause"); //按任意键继续 
			break;
		case '6':
			printf("显示线性表操作->\n");
			ListPrint(&L);
			system("pause"); //按任意键继续 
			break;
		case '7':
			system("cls");
			break;
		case '8':
			printf("查看线性表长度->\n");
			printf("线性表的长度为：%d\n", ListLength(&L));
			system("pause"); //按任意键继续 
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
int ListGet(SeqList* L, int i, DataType* px)
{
	//取线性表第i个元素，成功返回SUCCESS并把元素放入*px,查找失败返回FAIL
	if (L->last <= 0)
	{
		printf("线性表为空\n");
		return FAIL;
	}
	if (i<0 || i> L->last)//线性表里没有这个第i个元素
	{
		printf("参数i不合法 \n");
		return FAIL;
	}
	else
	{
		*px = L->elem[i - 1]; //元素放入* px
		return SUCCESS;
	}
}
void ListInitiate(SeqList* L)//初始化线性表
{
	int m = 0;
	printf("你要申请多少长度的线性表：\n");
	scanf("%d", &m);
	L->last = m;
	for (int i = 0; i < L->last; i++)
	{
		L->elem[i] = i + 1;
	}
	//初始化线性表为：1 2 3 4 5 6 7 8 9 10。。。。。L->last （ m）
}

int ListLength(SeqList* L)//求线性表的长度，返回线性表L中数据元素个数
{
	return L->last;
}

int ListInsert(SeqList* L, int i, DataType x)//第i位置插入元素x，插入成功返回SUCCESS,否则FAIL
{
	int j;
	if (i<0 || i>L->last)
	{
		printf("参数i不合法 \n");
		return FAIL;
	}
	else if (L->last >= MAXSIZE)
	{
		printf("线性表已满无法插入 \n");
		return FAIL;
	}
	else
	{
		L->last++;    //线性表长度+1

		for (j = L->last; j > i - 1; j--)
		{
			L->elem[j] = L->elem[j - 1];//i和i后的数据往后移
		}
		L->elem[i - 1] = x;   //在线性表第i个位置，即数组下标插入x
		return SUCCESS;
	}
}

void ListPrint(SeqList* L)//用（a1,a2,a3,...,an)个格式输出线性表
{
	printf("\n线性表为：(");//输出(
	int i;
	for (i = 0; i < L->last - 1; i++)
	{
		printf("%d,", L->elem[i]);
	}
	if (i == L->last - 1)
	{
		printf("%d", L->elem[i]);
	}
	printf(")\n");	//输出）
}

int ListDelete(SeqList* L, int i) //删除表中第i个元素，删除成功返回SUCCESS,否则FAIL 
{
	int j;
	if (i<0 || i> L->last)//线性表里没有这个第i个元素
	{
		printf("参数i不合法 \n");
		return FAIL;
	}
	else if (L->last <= 0)
	{
		printf("线性表已空无法插入 \n");
		return FAIL;
	}
	else
	{
		for (j = i; j <= L->last; j++)//元素i被删除后，i后面的元素依次往前移
		{
			L->elem[j - 1] = L->elem[j];
		}
		L->last--;//删除元素后，长度-1
		return SUCCESS;
	}
}


int ListSearch(SeqList* L, DataType x)//查找表中元素x的位置，查找成功返回位置，否则返回-1 
{
	if (L->last <= 0)
	{
		printf("线性表为空\n");
		return FAIL;
	}
	for (int j = 0; j < L->last; j++)
	{
		if (x == L->elem[j])
		{
			return j + 1;
		}
	}
	return FAIL;
}


