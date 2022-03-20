#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MaxStackSize 10// MaxStackSize表示顺序堆栈数组Stack的最大内存单元个数（允许存储的元素最大个数）
typedef int DataType;

//定义结构体SeqStack，定义抽象数组，和栈顶位置
typedef struct {
	DataType Stack[MaxStackSize];//Stack表示顺序堆栈存放元素的数组
	int top;//top表示顺序堆栈数组Stack的当前栈顶位置
}SeqStack;

//DataType d, x;
//SeqStack S;

void StackInitiate(SeqStack* S);//初始化顺序堆栈S
int StackNotEmpty(SeqStack S);//非空否
int StackPush(SeqStack* S, DataType x);//入栈
int StackPop(SeqStack* S, DataType* d);//出栈
int StackTop(SeqStack S, DataType* d);//取栈顶元素