#define _CRT_SECURE_NO_WARNINGS 1
//��ջ������ȳ���ջ�����룬ջ��ɾ����
//���У��Ƚ��ȳ�����β���룬��ͷɾ����
#include"SeqStack.h"

int main()
{
	SeqStack MyStack;
	int i, x;
	StackInitiate(&MyStack);//��ʼ��˳���ջS

	for (i = 0; i < 10; i++)
	{
      StackPush( &MyStack, i+1);//��ջ
	}
    StackTop(MyStack, &x);//ȡջ��Ԫ��
	printf("��ǰջ��Ԫ���ǣ�%d\n", x);

	printf("���γ�ջ��Ԫ���������£�\n");
	while (StackNotEmpty(MyStack))
	{
		 StackPop(&MyStack, &x);//��ջ
		 printf("%d ",x);
	}
	


	return 0;
}