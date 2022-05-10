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

BiTree Create();//二叉树的创建
void PreOrder(BiTree bt);//先序
void InOrder(BiTree bt);//中序
void PostOrder(BiTree bt);//后序
int Count1(BiTree bt);//二叉树的叶子节点的数量
int Count2(BiTree bt);//度为2的节点的数量
int Treehigh(BiTree bt);//二叉树的深度
void ChangeTree(BiTree bt);//交换左右子树
void Destory(BiTree bt); //释放空间

int main()
{
	BiTree t;
	char sel = ' ';
	while (sel != '0')
	{
		printf("------二叉树演示系统-------\n");
		printf("   版本:1.0   作者:金春依 日期:2022-05-07\n");
		printf("------------------------------------------\n");
		printf("       1.创建二叉树\n");
		printf("       2.先序排列操作\n");
		printf("       3.中序排列操作\n");
		printf("       4.后序排列操作\n");
		printf("       5.输出二叉树的叶子节点和度为2的节点的数量\n");
		printf("       6.输出二叉树的深度\n");
		printf("       7.将二叉树所有节点的左右子树互换\n");
		printf("       8.删除二叉树\n");
		printf("       0.退出系统\n");
		printf("请输入选项[0-8]:");
		sel = getch();
		switch (sel)
		{
		case '1':
			printf("创建二叉树.\n");
			t = Create();
			printf("成功\n");
			system("pause");
			break;
		case '2':
			printf("先序排列操作.\n");
			PreOrder(t);
			system("pause");
			break;
		case '3':
			printf("中序排列操作.\n");
			InOrder(t);
			system("pause");
			break;
		case '4':
			printf("后序排列操作.\n");
			PostOrder(t);
			system("pause");
			break;
		case '5':
			printf("输出二叉树的叶子节点和度为2的节点的数量.\n");
			printf("叶子节点：%d个\n度为2的节点:%d个\n", Count1(t), Count2(t));
			system("pause");
			break;
		case '6':
			printf("输出二叉树的深度.\n");
			printf("%d\n", Treehigh(t));
			system("pause");
			break;
		case '7':
			printf("将二叉树所有节点的左右子树互换.\n");
			ChangeTree(t);
			system("pause");
			break;
		case '8':
			printf("删除二叉树.\n");
			Destory(t);
			printf("删除成功\n");
			system("pause");
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

BiTree Create()  //用先序序列(改造过的)来创建二叉树，返回指向二叉树根节点的指针
{
	char ch = getchar();
	if (ch != ' ')
	{
		BiTree root = (BiTree)malloc(sizeof(BiTreeNode));
		root->data = ch;
		getchar();
		root->leftChild = Create(); //先序创建左子树
		getchar();
		root->rightChild = Create(); //先序创建右子树
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
	if (bt == NULL)  high = 0;//空树
	else
	{
		lefthigh = Treehigh(bt->leftChild);
		righthigh = Treehigh(bt->rightChild);
		int i = lefthigh > righthigh ? lefthigh : righthigh;//找到子树的深度
		high = i + 1;//子树深度+1=树的深度
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
		bt->leftChild = temp;//上面三步，把bt结点的左右结点交换成功
		ChangeTree(bt->leftChild);
		ChangeTree(bt->rightChild);
	}
	else return;
}

void Destory(BiTree bt) //后序遍历，释放结点空间
{
	if (bt != NULL)
	{
		if (bt->leftChild != NULL)    Destory(bt->leftChild);
		if (bt->rightChild != NULL) Destory(bt->rightChild);
		free(bt);
	}
}
