#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int * ret = NULL;
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j) 
        {
            if (nums[i] + nums[j] == target) 
            {
                int* ret = (int*)malloc(sizeof(int) * 2);//开辟空间用来存储下标
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;   //返回下标
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
int main()
{
    int nums[] = {2, 7, 11, 19};
    int target = 18;
    int returnSize=-1;
    int len = sizeof(nums) / sizeof(int);
    int* a = twoSum(nums, len, target, &returnSize);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}