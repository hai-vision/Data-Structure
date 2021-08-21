#include "QuickSort.h"

// 三数取中
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) >> 1;	// 移位操作
	if (a[left] > a[mid]) {
		if (a[left] < a[right]) {
			return left;
		}
		else if (a[mid] > a[right]) {
			return mid;
		}
		else {
			return right;
		}
	}
	else {//a[left] < a[mid]
		if (a[mid] < a[right]) {
			return mid;
		}
		else if (a[left] > a[right]) {
			return left;
		}
		else {
			return right;
		}
	}
}
// 交换元素的值
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// 前后指针法
// 在闭区间[left, right]间进行，对数组进行一次快排
/*	算法思想：
	1、设置前后指针：prev， cur
	2、利用“三数取中的方法得到一个关键字key，并将key与数组第一个元素位置交换
	3、cur向右移动找到第一个比key小的数
	4、++prev，交换当前cur与prev指向的元素值
	5、++cur
*/
int PartSort1(int* a, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	int key = prev;
	int mid = GetMid(a, left, right);
	// 将首元素与mid指向元素的位置进行交换
	Swap(&a[key], &a[mid]);
	while (cur <= right) {
		if (a[cur] < a[key] && ++prev!= cur) {
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[key], &a[prev]);
	return prev;

}
// 左右指针法
// 在闭区间[left, right]间进行，对数组进行一次快排
/*
	
*/
void QuickSort(int* a, int left, int right)
{
	if (left >= right) {
		return;
	}
	int mid = PartSort1(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}