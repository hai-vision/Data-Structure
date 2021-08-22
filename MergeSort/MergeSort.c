#include "MergeSort.h"
// 归并操作
/*
	算法前提
	1、左半区间有序，右半区间有序
	2、区间元素依次两两比较，小的放到临时数组中
	3、当某一区间结束，将剩余区间内的元素依次放到临时数组
	4、将临时数组拷贝到原数组

	算法思想：
	1、利用递归策略，将区间划分为左右两部分。当区间长度为1时不再划分
	2、依次比较两个区间元素大小，将较小的放到临时数组
	3、再将临时数组中的值拷贝到原数组中
*/
void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right) {
		return;
	}
	int mid = (left + right) >> 1;	// 移位，将数组划分为两部分
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2<=end2) {
		if (a[begin1] < a[begin2]) {
			tmp[index++] = a[begin1++];		// 后置++， 先赋值后执行加1操作
		}
		else {
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[index++] = a[begin2++];
	}
	// 拷回到原数组
	for (int i = left; i <= right; i++) {
		a[i] = tmp[i];
	}


}
// 归并排序

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);

}
