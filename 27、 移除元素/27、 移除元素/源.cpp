#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
int left = 0;
int removeElement(int* nums, int numsSize, int val) 
{
   
    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] != val)
        {
            nums[left] = nums[i];
            left++;
        }
    }
    return left;
}
int main()
{
    int num[4] = { 3,2,2,3 };
    printf(" %d, num=[",removeElement(num, 4, 2));
    for (int j = 0; j < left-1; j++)
    {
        printf("%d,", num[j]);
    }
    printf("%d ]",num[left-1]);
	return 0;
}



