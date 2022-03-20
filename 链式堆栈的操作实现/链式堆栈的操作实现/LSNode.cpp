#define _CRT_SECURE_NO_WARNINGS 1
#include"LSNode.h"
void StackInitiate(LSNode** head)//��ʼ����ͷ�����ʽ��ջ
{
	//��ʼ����ͷ�����ʽ��ջ
	*head = (LSNode*)malloc(sizeof(LSNode));
	(*head)->next = NULL;
}


int StackNotEmpty(LSNode* head)//�ǿշ�
{
	//�ж϶�ջ�Ƿ�ǿգ��ǿգ�return 1���գ�return 0
	if (head->next == NULL)  return 0;
	else return 1;
}

void StackPush(LSNode* head, DataType x)//��ջ
{
	//��Ԫ��x������ʽ��ջhead��ջ����Ϊ�µ�ջ��
	LSNode* p;
	p= (LSNode*)malloc(sizeof(LSNode));
	p->data = x;
	p->next = head->next;//�½������ջ��
	head->next = p;//�½���Ϊ�µ�ջ��
}

int StackPop(LSNode* head, DataType* d)//��ջ
{
	//��ջ����ջ��Ԫ����Ԫ��d���أ�����ջ�ɹ�return 1��ʧ��return 0��
	LSNode* p=head->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���\n");
	    return 0;
	}
	else
	{
		head->next = p->next;
		*d = p->data;
		free(p);
		return 1;
	}
}


void Destroy(LSNode* head)//������̬����ռ�
{
	LSNode* p, * p1;
	p = head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}