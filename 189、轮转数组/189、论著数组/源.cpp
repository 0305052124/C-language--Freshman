#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//思路一：旋转k次
// 时间复杂度：O（n*k）
//void rotate(int* nums, int numsSize, int k) 
//{
//	while (k--)
//	{
//		int temp = nums[numsSize - 1];
//		for (int end = numsSize - 2; end >= 0; --end)
//		{
//			nums[end + 1] = nums[end];
//		}
//		nums[0] = temp;
//	}
//}
// //思路二:以空间换时间
//时间复杂度，空间复杂度O（n）
//void rotate(int* nums, int numsSize, int k)
//{
//	int a[100];
//	int j=0;
//	for (int i = numsSize  - k; i <numsSize ; i++)
//	{
//		a[j] = nums[i];
//		j++;
//	}
//	j = 3;
//	for (int i = 0; i < numsSize -k; i++)
//	{
//		a[j] = nums[i];
//		j++;
//	}
//	for (int i = 0; i < numsSize ; i++)
//	{
//		nums[i] = a[i];
//	}
//}

//思路三：
 //1、后k个逆置
 //2、前n-k个逆置
 //3、整体逆置
void Reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		right--;
		left++;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	if (k > numsSize)
		k = k % numsSize;
	Reverse(nums, numsSize - k, numsSize - 1);
	Reverse(nums, 0, numsSize - k - 1);
	Reverse(nums, 0, numsSize - 1);
}

int main()
{
	int nums[7] = { 1,2,3,4,5,6,7 };//numsSize=7
	int size = 7;
	int k = 3;
	rotate(nums, size, k);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}