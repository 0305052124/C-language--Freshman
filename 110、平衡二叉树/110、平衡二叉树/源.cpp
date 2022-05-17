#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<malloc.h>

struct TreeNode {//����һ���ṹ��
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
TreeNode* CreatePreTree()//���������� 
{
    char c;
    scanf("%c", &c);
    if (c == '#')  //�ո� 
        return NULL;
    else
    {
        TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
        T->val = c;
        T->left = CreatePreTree();
        T->right = CreatePreTree();
        return T;
    }
}
int depth(struct TreeNode* root)//����ȵ��Ӻ���
{
    if (root == NULL)
    {
        return 0;
    }
    int left = depth(root->left) + 1;//��ߵĽڵ����ͷ�ڵ㣬�͵�ͬ����ߵ����
    int right = depth(root->right) + 1;//ͬ��
    return left > right ? left : right;//�ٿ���������������������ȣ�
}
int  isBalanced(struct TreeNode* root)
{
    if (root == NULL) return 1;//����ǿ���������ƽ������� 
    int left = depth(root->left);
    int right = depth(root->right);
    if (abs(left - right) > 1)  return 0;//�������1��˵��������ƽ�������m
    //return isBalanced(root->left) && isBalanced(root->right);//�Զ��������еݹ�
}
int main()
{
    printf("����������.\n");
    TreeNode* T=CreatePreTree();
    if (isBalanced(T) == 1)
    {
        printf("TRUE\n");
    }
    else printf("FALSE\n");
	return 0;
}