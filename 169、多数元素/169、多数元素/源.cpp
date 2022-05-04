#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int majorityElement(int* nums, int numsSize)
{
    if (numsSize == 0)   return 0;
    int count = 1;
    int value = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (value == nums[i])  count++;
        else
        {
            count--;
            if (count == 0)
            {
                value = nums[i];
                count = 1;
            }
        }
    }
    return value;
}
int main()
{
    int nums[] = { 3, 2, 3 };
    printf("%d\n", majorityElement(nums, 3));
    return 0;
}