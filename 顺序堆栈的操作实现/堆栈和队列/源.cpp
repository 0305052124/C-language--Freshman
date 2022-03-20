#define _CRT_SECURE_NO_WARNINGS 1
//堆栈：后进先出，栈顶插入，栈顶删除，
//队列：先进先出，队尾插入，队头删除，
#include"SeqStack.h"

int main()
{
	SeqStack MyStack;
	int i, x;
	StackInitiate(&MyStack);//初始化顺序堆栈S

	for (i = 0; i < 10; i++)
	{
      StackPush( &MyStack, i+1);//入栈
	}
    StackTop(MyStack, &x);//取栈顶元素
	printf("当前栈顶元素是：%d\n", x);

	printf("依次出栈的元素序列如下：\n");
	while (StackNotEmpty(MyStack))
	{
		 StackPop(&MyStack, &x);//出栈
		 printf("%d ",x);
	}
	


	return 0;
}