#include "sort.h"

// 直接插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++) {
		// [0, end]有序, 插入数据后任然保持有序
		int end = i;
		int tmp = a[end + 1];		// 暂存当前已排好序元素的后一位
		while (end >= 0) { // 边界限定
			if (a[end] > tmp) {	// 当数组已排好序的元素大于待排序的元素时，交换
				a[end + 1] = a[end];	// 移动元素位置
				end--;		// 更新排好序数组中元素的下标
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;	// 将待排序的元素放入数组中
	}
}

// 希尔排序
// 在直接插入排序的基础上进行多次预排序，使得数组元素大体有序
// 最后一次进行直接排序
void ShellSort(int* a, int n)
{
	int gap = n;		// gap为一个增量
	while (gap > 1) {
		gap = gap / 2;			// 至少保证最后一次的增量为1；
		for (int i = 0; i < n-gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}
// 向下调整算法
void AdjustDown(int* a, int n, int root)
{
	// 前提：左右子树都是小堆/大堆排序
	int parent = root;
	int child = parent * 2 + 1;		// 默认为左子树
	while (child < n) { // 到叶子结点结束
		// 选出左右子树中数值较大的元素
		if (child + 1 < n && a[child+1] > a[child]) {// 当child+1>n：只有左子树
			child += 1;
		}
		// 比较父节点与较大的子节点
		if (a[parent] < a[child]) {
			// 交换父节点与子节点的值
			Swap(&a[parent], &a[child]);
			// 更新parent与child的位置
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
// 堆排序
void HeapSort(int* a, int n)
{
	int end = n - 1;	// 最后一个叶子结点
	//	建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {//n-1: 获取最后一个叶子结点， (n-1-1)/2：最后一个非叶子结点
		AdjustDown(a, n, i);
	}
	while (end > 0) {
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);	// 向下调整
		end--;
	}
}
// 简单选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int maxIndex = begin;
		int minIndex = begin;
		for (int i = begin; i < end; i++) {
			if (a[i] > a[maxIndex]) {
				maxIndex = i;
			}
			if (a[i] < a[minIndex]) {
				minIndex = i;
			}
		}
		Swap(&a[begin], &a[minIndex]);
		if (begin == maxIndex) {
			maxIndex = minIndex;
		}
		Swap(&a[end], &a[maxIndex]);
		begin++;
		end--;
	}
}
// “挖坑法”实现快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right) {
		return;
	}
	int low = left;
	int hight = right;
	int key = a[left];
	int pivot = left;
	while (low < hight) {
		// 从右到左，找第一个比key小的
		while (a[hight] >= key && low < hight) {
			hight--;
		}
		a[pivot] = a[hight];
		pivot = hight;
		// 从左到右，找第一个比key大的
		while (a[low] <= key && low < hight) {
			low++;
		}
		a[pivot] = a[low];
		pivot = low;
	}
	pivot = low;
	a[pivot] = key;
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);
}
void PrintfArr(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}