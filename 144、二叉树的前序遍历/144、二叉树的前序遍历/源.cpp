#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef char DataType;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int* resSize;
void preorder(struct TreeNode* root, int* res, int* resSize)
{
    if (root == NULL)  return;           //判空
    res[(*resSize)++] = root->val;       //存入数组
    preorder(root->left, res, resSize);  //递归当前结点的左子树
    preorder(root->right, res, resSize); //递归当前结点的右子树
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * 2000);//开辟数组空间
    *returnSize = 0;
    preorder(root, res, returnSize);//跟结点，目标数组，长度
    return res;
}
int main()
{
    struct TreeNode root;
    int* size = 0;
    int* res =preorderTraversal(&root, size);
    for (int* i = 0; i < resSize; i++)
    {
        printf("%d ", (*res)++);
    }
    return 0;
}