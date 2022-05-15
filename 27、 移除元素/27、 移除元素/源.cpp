#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
//思路一
//int removeElement(int* nums, int numsSize, int val)
//{
//    int len = numsSize;
//        for (int i = 0; i < numsSize; i++)
//        {
//            if (nums[i] == val)
//            {
//                for (int j = i; j < numsSize - 1; j++)
//                {
//                    nums[j] = nums[j + 1];
//                }
//                len--;
//                i--;
//            }
//        }
//    return len;
//}
//思路二：
//int copy[] = { 0 };
//int removeElement(int* nums, int numsSize, int val)
//{
//    int size = 0;
//    
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            copy[size] = nums[i];
//            size++;
//        }
//    }
//    return size;
//}
 
  
//思路三：
int removeElement(int* nums, int numsSize, int val)
{
    int src = 0;
    int dst = 0;
    while (src < numsSize)
    {
        if (nums[src] != val)
        {
            nums[dst++] = nums[src++];
        }
        else
        {
            ++src;
        }
    }
    return dst;
}


int main()
{
    int nums[6] = { 3,2,2,3,5,9};
    int len = removeElement(nums, 6, 2);
    for (int i = 0; i < len; i++)
    {
        printf("%d ",nums[i]);
        //printf("%d ", copy[i]);//思路二里的全局变量
    }
    return 0;
}



