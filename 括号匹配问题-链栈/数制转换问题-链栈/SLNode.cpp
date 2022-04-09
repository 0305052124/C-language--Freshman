#define _CRT_SECURE_NO_WARNINGS 1
#include"SLNode.h"
LinkStack CreateLinkStack()  //����һ���յ���ջ������ 
{
	LinkStack top = (LinkStack)malloc(sizeof(LSNode));
	if (top == NULL)
	{
		printf("�ڴ����ʧ��");
	}
	top->next = NULL;
	return top;
}
void PrintStack(LinkStack top) //��ӡջԪ��(��ջ����ջ��˳��) 
{
	LinkStack p = top->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int GetTop(LinkStack top, char* x) //ȡջ��Ԫ�أ�����ջ 
{
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���");
		return FALSE;
	}
	*x = p->data;
	return TRUE;
}

void DestroyStack(LinkStack top)//�ͷ�ջ�����пռ�,����ͷ�ڵ� 
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
int IsEmpty(LinkStack top)//�п� 
{
	//�ж϶�ջ�Ƿ�ǿգ��ǿգ�return TRUE���գ�return FALSE
	if (top->next == NULL)
		return FALSE;
	else
		return TRUE;
}
void Push(LinkStack top, char x) //��ջ 
{
	//��Ԫ��x������ʽ��ջhead��ջ����Ϊ�µ�ջ��

	LinkStack p;
	p = (LinkStack)malloc(sizeof(LSNode));
	p->data = x;
	p->next = top->next;//�½������ջ��
	top->next = p;//�½���Ϊ�µ�ջ��
}
int Pop(LinkStack top, DataType* x)//��ջ 
{
	//��ջ����ջ��Ԫ����Ԫ��x���أ�����ջ�ɹ�return 1��ʧ��return 0��
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���\n");
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