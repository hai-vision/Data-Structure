#include "sort.h"

// ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++) {
		// [0, end]����, �������ݺ���Ȼ��������
		int end = i;
		int tmp = a[end + 1];		// �ݴ浱ǰ���ź���Ԫ�صĺ�һλ
		while (end >= 0) { // �߽��޶�
			if (a[end] > tmp) {	// ���������ź����Ԫ�ش��ڴ������Ԫ��ʱ������
				a[end + 1] = a[end];	// �ƶ�Ԫ��λ��
				end--;		// �����ź���������Ԫ�ص��±�
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;	// ���������Ԫ�ط���������
	}
}

// ϣ������
// ��ֱ�Ӳ�������Ļ����Ͻ��ж��Ԥ����ʹ������Ԫ�ش�������
// ���һ�ν���ֱ������
void ShellSort(int* a, int n)
{
	int gap = n;		// gapΪһ������
	while (gap > 1) {
		gap = gap / 2;			// ���ٱ�֤���һ�ε�����Ϊ1��
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
// ���µ����㷨
void AdjustDown(int* a, int n, int root)
{
	// ǰ�᣺������������С��/�������
	int parent = root;
	int child = parent * 2 + 1;		// Ĭ��Ϊ������
	while (child < n) { // ��Ҷ�ӽ�����
		// ѡ��������������ֵ�ϴ��Ԫ��
		if (child + 1 < n && a[child+1] > a[child]) {// ��child+1>n��ֻ��������
			child += 1;
		}
		// �Ƚϸ��ڵ���ϴ���ӽڵ�
		if (a[parent] < a[child]) {
			// �������ڵ����ӽڵ��ֵ
			Swap(&a[parent], &a[child]);
			// ����parent��child��λ��
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
// ������
void HeapSort(int* a, int n)
{
	int end = n - 1;	// ���һ��Ҷ�ӽ��
	//	����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {//n-1: ��ȡ���һ��Ҷ�ӽ�㣬 (n-1-1)/2�����һ����Ҷ�ӽ��
		AdjustDown(a, n, i);
	}
	while (end > 0) {
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);	// ���µ���
		end--;
	}
}
// ��ѡ������
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
// ���ڿӷ���ʵ�ֿ�������
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
		// ���ҵ����ҵ�һ����keyС��
		while (a[hight] >= key && low < hight) {
			hight--;
		}
		a[pivot] = a[hight];
		pivot = hight;
		// �����ң��ҵ�һ����key���
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