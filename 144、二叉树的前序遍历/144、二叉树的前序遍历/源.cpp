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
    if (root == NULL)  return;           //�п�
    res[(*resSize)++] = root->val;       //��������
    preorder(root->left, res, resSize);  //�ݹ鵱ǰ����������
    preorder(root->right, res, resSize); //�ݹ鵱ǰ����������
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * 2000);//��������ռ�
    *returnSize = 0;
    preorder(root, res, returnSize);//����㣬Ŀ�����飬����
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