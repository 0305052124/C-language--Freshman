#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqStack.h"

void StackInitiate(SeqStack* S)//��ʼ��˳���ջS
{
	S->top = 0;//��ʼ��һ����ջ����ʼ��ջ���±�ֵ��top=0��ʾ��ջΪ��ջ��
}


int StackNotEmpty(SeqStack S)//�ǿշ�
{
	//�ж�˳���ջS�ǿշ����ǿշ���1���շ���0
	if (S.top <= 0)
	    return 0;
	else
		return 1;
}


int StackPush(SeqStack* S, DataType x)//��ջ
{
	//��x����˳���ջS�У�����ջ�ɹ��򷵻�1��ʧ�ܷ���0
	//�ж�ջ��
	if (S->top >= MaxStackSize)
	{
		printf("��ջ�����޷�����! \n");
        return 0;
	}
	else
	{
		//ָ���1����Ԫ��, return
		S->top ++;
		S->Stack[S->top/*-1*/] = x;
		return 1;
	}
}

int StackPop(SeqStack* S, DataType* d)//��ջ
{
	//ȡ��˳��ջ��S��ջ��Ԫ�أ��ɲ���d����
	//��ջ�ɹ�����1��ʧ�ܷ���0
	// 
	//ʧ�������ջ�գ���Ԫ�ؿɳ�ջ
	if (S->top <= 0)
	{
		printf("��ջ�ѿ��޷���ջ! \n");
		return 0;
	}
	//վ�ǿգ�ȡԪ�أ���ָ�룬return
	else
	{
		*d = S->Stack[S->top];
		S->top--;
		return 1;
	}
}
int StackTop(SeqStack S, DataType* d)//ȡջ��Ԫ��
{
	//ȡ˳���ջS�ĵ�ǰջ��Ԫ�أ��ɲ���d����
	//�ɹ�����1��ʧ�ܷ���0
	
	//ʧ�������ջ�գ���Ԫ�ؿ�ȡ
	if (S.top <= 0)
	{
		printf("��ջ�ѿ�,��Ԫ�ؿ�ȡ! \n");
		return 0;
	}
	else
	{
		*d = S.Stack[S.top ];
		return 1;
	}
}