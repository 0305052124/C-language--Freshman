#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqStack.h"
void  InitStack(SeqStack* S)//��ʼ��ջ 
{
	S->top = 0;//��ʼ��һ����ջ����ʼ��ջ���±�ֵ��top=0��ʾ��ջΪ��ջ
}
int IsEmpty(SeqStack* S)//�п�
{
	//�ж�˳���ջS�ǿշ�
	if (S->top <= 0)
		return TRUE;//ջ�շ���1
	else
		return FALSE;//�ǿշ���0
}
int Push(SeqStack* S, DataType x) //��ջ
{
	//��x����˳���ջS�У�����ջ�ɹ��򷵻�TRUE��ʧ�ܷ���FALSE
	if (S->top >= MaxSize)//�ж�ջ��
	{
		printf("��ջ�����޷�����! \n");
		return FALSE;
	}
	else
	{
		S->top++;//ָ���1����Ԫ��, return
		S->data[S->top - 1] = x;
		return TRUE;
	}
}
int GetTop(SeqStack S, DataType* x) //ȡջ��Ԫ��
{
	//ȡ˳���ջS�ĵ�ǰջ��Ԫ�أ��ɲ���x����
	//�ɹ�����TRUE��ʧ�ܷ���FALSE

	if (S.top <= 0)//ʧ�������ջ�գ���Ԫ�ؿ�ȡ
	{
		printf("��ջ�ѿ�,��Ԫ�ؿ�ȡ! \n");
		return FALSE;
	}
	else//ջ�ǿգ�ȡԪ�أ���ָ�룬return
	{
		*x = S.data[S.top - 1];
		return TRUE;
	}
}



int Pop(SeqStack* S, DataType* x)//��ջ 
{
	//ȡ��˳��ջ��S��ջ��Ԫ�أ��ɲ���x����
	//��ջ�ɹ�����TRUE��ʧ�ܷ���FALSE
	//ʧ�������ջ�գ���Ԫ�ؿɳ�ջ
	if (S->top <= 0)
	{
		printf("��ջ�ѿ��޷���ջ! \n");
		return FALSE;
	}
	else//ջ�ǿգ�ȡԪ�أ���ָ�룬return
	{
		S->top--;
		*x = S->data[S->top];
		return TRUE;
	}
}