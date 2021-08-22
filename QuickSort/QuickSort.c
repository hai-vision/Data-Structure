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
	算法思想
	1、分别设置左右两个指针，begin、end
	2、利用“三数取中”选择中间数作为key，并与首元素交换位置
	3、begin指针向右移找到第一个比key大的数
	4、end指针向左移找到第一个比key小的数
	5、交换两个指针所指向的数组元素的值
	6、当begin与end相遇，key交换begin指向的值
*/
int PartSort2(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int key = begin;
	int mid = GetMid(a, left, right);
	Swap(&a[key], &a[mid]);
	while (begin < end) {
		// end向左移找到第一个比key小的数
		while (begin < end && a[end] >= a[key]) {
			--end;
		}
		// begin向右移动，找到第一个比key大的数
		while (begin < end && a[begin] <= a[key]) {
			++begin;
		}
		// 满足上述两者条件，begin与end交换
		Swap(&a[begin], &a[end]);
	}
	// 当begin与end相遇
	Swap(&a[key], &a[begin]);
	return begin;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right) {
		return;
	}
	//int mid = PartSort1(a, left, right);
	int mid = PartSort2(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}
