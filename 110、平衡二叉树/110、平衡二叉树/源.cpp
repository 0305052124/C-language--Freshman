#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<malloc.h>

struct TreeNode {//创建一个结构体
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
TreeNode* CreatePreTree()//建立二叉树 
{
    char c;
    scanf("%c", &c);
    if (c == '#')  //空格 
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
int depth(struct TreeNode* root)//求深度的子函数
{
    if (root == NULL)
    {
        return 0;
    }
    int left = depth(root->left) + 1;//左边的节点加上头节点，就等同于左边的深度
    int right = depth(root->right) + 1;//同理，
    return left > right ? left : right;//再看其左子树和右子树的深度；
}
int  isBalanced(struct TreeNode* root)
{
    if (root == NULL) return 1;//如果是空树，就是平衡二叉树 
    int left = depth(root->left);
    int right = depth(root->right);
    if (abs(left - right) > 1)  return 0;//如果大于1，说明它不是平衡二叉树m
    //return isBalanced(root->left) && isBalanced(root->right);//对二叉树进行递归
}
int main()
{
    printf("创建二叉树.\n");
    TreeNode* T=CreatePreTree();
    if (isBalanced(T) == 1)
    {
        printf("TRUE\n");
    }
    else printf("FALSE\n");
	return 0;
}