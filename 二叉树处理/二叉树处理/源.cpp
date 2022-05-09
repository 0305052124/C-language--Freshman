#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct Node {
	DataType data;
	struct Node* leftChild;
	struct Node* rightChild;
}BiTreeNode, * BiTree;

BiTree Create();//�������Ĵ���
void PreOrder(BiTree bt);//����
void InOrder(BiTree bt);//����
void PostOrder(BiTree bt);//����
int Count1(BiTree bt);//��������Ҷ�ӽڵ������
int Count2(BiTree bt);//��Ϊ2�Ľڵ������
int Treehigh(BiTree bt);//�����������
void ChangeTree(BiTree bt);//������������
void Destory(BiTree bt); //�ͷſռ�

int main()
{
	BiTree t;
	char sel = ' ';
	while (sel != '0')
	{
		printf("------��������ʾϵͳ-------\n");
		printf("   �汾:1.0   ����:���� ����:2022-05-07\n");
		printf("------------------------------------------\n");
		printf("       1.����������\n");
		printf("       2.�������в���\n");
		printf("       3.�������в���\n");
		printf("       4.�������в���\n");
		printf("       5.�����������Ҷ�ӽڵ�Ͷ�Ϊ2�Ľڵ������\n");
		printf("       6.��������������\n");
		printf("       7.�����������нڵ��������������\n");
		printf("       8.ɾ��������\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-8]:");
		sel = getch();
		switch (sel)
		{
		case '1':
			printf("����������.\n");
			t = Create();
			printf("�ɹ�\n");
			system("pause");
			break;
		case '2':
			printf("�������в���.\n");
			PreOrder(t);
			system("pause");
			break;
		case '3':
			printf("�������в���.\n");
			InOrder(t);
			system("pause");
			break;
		case '4':
			printf("�������в���.\n");
			PostOrder(t);
			system("pause");
			break;
		case '5':
			printf("�����������Ҷ�ӽڵ�Ͷ�Ϊ2�Ľڵ������.\n");
			printf("Ҷ�ӽڵ㣺%d��\n��Ϊ2�Ľڵ�:%d��\n", Count1(t), Count2(t));
			system("pause");
			break;
		case '6':
			printf("��������������.\n");
			printf("%d\n", Treehigh(t));
			system("pause");
			break;
		case '7':
			printf("�����������нڵ��������������.\n");
			ChangeTree(t);
			system("pause");
			break;
		case '8':
			printf("ɾ��������.\n");
			Destory(t);
			printf("ɾ���ɹ�\n");
			system("pause");
			break;
		case '0':
			printf("\nллʹ�ã��ټ���\n");
			break;
		default:
			printf("�������ѡ��Ϸ���������ѡ��\n");
		}
	}
	return 0;
}

BiTree Create()  //����������(�������)������������������ָ����������ڵ��ָ��
{
	char ch = getchar();
	if (ch != ' ')
	{
		BiTree root = (BiTree)malloc(sizeof(BiTreeNode));
		root->data = ch;
		getchar();
		root->leftChild = Create(); //���򴴽�������
		getchar();
		root->rightChild = Create(); //���򴴽�������
		return root;
	}
	else return NULL;
}
int Count1(BiTree bt)
{
	if (bt == NULL) return 0;
	else if (bt->leftChild == NULL && bt->rightChild == NULL)
		return 1;
	else
		return (Count1(bt->leftChild) + Count1(bt->rightChild));
}
int Count2(BiTree bt)
{
	if (bt == NULL) return 0;
	else if (bt->leftChild != NULL && bt->rightChild != NULL)
		return 1;
	else
		return (Count2(bt->leftChild) + Count2(bt->rightChild));
}
void PreOrder(BiTree bt)
{
	if (bt == NULL) return;
	printf("%c  ", bt->data);
	PreOrder(bt->leftChild);
	PreOrder(bt->rightChild);
}
void InOrder(BiTree bt)
{
	if (bt == NULL) return;
	InOrder(bt->leftChild);
	printf("%c  ", bt->data);
	InOrder(bt->rightChild);
}
void PostOrder(BiTree bt)
{
	if (bt == NULL) return;
	PostOrder(bt->leftChild);
	PostOrder(bt->rightChild);
	printf("%c  ", bt->data);
}

int Treehigh(BiTree bt)
{
	int lefthigh, righthigh, high;
	if (bt == NULL)  high = 0;//����
	else
	{
		lefthigh = Treehigh(bt->leftChild);
		righthigh = Treehigh(bt->rightChild);
		int i = lefthigh > righthigh ? lefthigh : righthigh;//�ҵ����������
		high = i + 1;//�������+1=�������
	}
	return high;
}

void ChangeTree(BiTree bt)
{
	BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
	if (bt)
	{
		temp = bt->rightChild;
		bt->rightChild = bt->leftChild;
		bt->leftChild = temp;//������������bt�������ҽ�㽻���ɹ�
		ChangeTree(bt->leftChild);
		ChangeTree(bt->rightChild);
	}
	else return;
}

void Destory(BiTree bt) //����������ͷŽ��ռ�
{
	if (bt != NULL)
	{
		if (bt->leftChild != NULL)    Destory(bt->leftChild);
		if (bt->rightChild != NULL) Destory(bt->rightChild);
		free(bt);
	}
}
