#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
typedef struct Node//������Ľڵ㶨��
{
	Datatype data;
	struct Node*  next;
}SLNode;
void ListInitiata(SLNode** head)//��ʼ��������
{
	*head = (SLNode*)malloc(sizeof(SLNode));//����ͷ��㣬��headָʾ���ַ
	(*head)->next = NULL;  //�ý�����־NULL
}
int ListLength(SLNode** head)//��ǰԪ�ظ���
{
	SLNode* p = *head;    //pָ��ָ��ͷ���
	int size = 0;             
	while (p->next != NULL)
	{
		p = p->next;        //pָ���¸���ַ
		size++;
	}
	return size;
}
int ListInsert(SLNode* head, int  i, Datatype x)
{
	//�ڴ�ͷ���ĵ�����head�ĵ�i��0~size�������ǰ����һ��Ԫ��x�Ľ��
	//����ɹ�����1��ʧ�ܷ���0
	SLNode * p=head;
	SLNode* q;
	int j =-1;
	while (p->next != NULL && j < i - 1)//��ָ֤����ָ�����ڣ���֤������ָ��pָ��i-1���
	{
		//��ָ��pָ���i-1�����
		p=p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("����Ԫ��λ�ò�������\n");
		return 0;
	}
	q = (SLNode*)malloc(sizeof(SLNode));//�����½��
	q->data = x;//���½�㸳ֵ

	q->next = p->next;
	p->next = q;
	
	return 1;
}
int ListDelete(SLNode* head, int  i, Datatype x)
{
	//ɾ����ͷ��㵥����head�ĵ�i��0~size-1�������
	//��ɾ������������x���أ�ɾ���ɹ�����1��ʧ�ܷ���0
	SLNode* p = head;
	SLNode* q;
	int j=-1;
	while (p->next != NULL && j < i - 1 && p->next ->next!= NULL)
	{
		//p->next != NULL��֤��i-1��������
		//p->next ->next!= NULL��֤��i��������
		//j < i - 1��֤ѭ������ָ��pָ���i-1�����
		//����p->next��ָ���i��ָ���ˣ�Ҳ����˵����q=p->next��qָ��ָ��Ľ����ǵ�i��ָ��Ҫɾ����
		p=p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("����Ԫ��λ�ò�������\n");
		return 0;
	}
	q = p->next;//ָ��qָ���i�����
	x = q->data;//��ָ��qָ����������ݷ���x�����
	p->next = p->next->next;//ɾ��qָ��ĵ�i�����,ʹ��i���������
	free(q);//�ͷ�ָ��q��ָ�����ڴ�ռ�
	return 1;
}
int ListGet(SLNode* head, int  i, Datatype x)
{
	SLNode* p = head;
	int j = -1;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("����Ԫ��λ�ò�������\n");
		return 0;
	}
	x = p->data;
	return 1;
}
void Destroy(SLNode** head)
{
	SLNode* p = *head;
	while (p != NULL)
	{
		SLNode* p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
int main()
{
	SLNode* head;     //����ͷָ�����
	ListInitiata(&head);//��ͷָ���ַ
	int length =ListLength(& head);
	int i = 2;
	Datatype x;
	int y=ListInsert( head, i, x);//���뺯��
	int m = ListDelete(head, i, x);//ɾ������
	int n = ListGet(head, i, x);//ȡԪ�غ���
	Destroy(&head);//����������
	return 0;
}