#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int missingNumber(int* nums, int numsSize) 
//{
//	int x = 0;
//	for (int i = 0; i < numsSize; i++)
//		x = x ^ nums[i];
//	for (int i = 0; i < numsSize + 1; i++)
//		x = x ^ i;
//	return x;
//}
// 
//int missingNumber(int* nums, int numsSize)
//{
//	int sum1 = 0;
//	int sum2 = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		sum1 += nums[i];
//	}
//	for (int i = 0; i < numsSize + 1; i++)
//	{
//		sum2 += i;
//	}
//	return sum2 - sum1;
//}

int missingNumber(int* nums, int numsSize)
{
	int temp;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = numsSize-1; j > i; j--)
		{
			if (nums[j] < nums[j - 1])
			{
				temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (i != nums[i])
			return i;
	}
}
int main()
{
	int nums[10] = { 9,6,4,2,3,5,7,0,1 };
	int size =9;
	printf("%d", missingNumber(nums, size));
	return 0;
}