#include "QuickSort.h"

// ����ȡ��
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) >> 1;	// ��λ����
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
// ����Ԫ�ص�ֵ
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// ǰ��ָ�뷨
// �ڱ�����[left, right]����У����������һ�ο���
/*	�㷨˼�룺
	1������ǰ��ָ�룺prev�� cur
	2�����á�����ȡ�еķ����õ�һ���ؼ���key������key�������һ��Ԫ��λ�ý���
	3��cur�����ƶ��ҵ���һ����keyС����
	4��++prev��������ǰcur��prevָ���Ԫ��ֵ
	5��++cur
*/
int PartSort1(int* a, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	int key = prev;
	int mid = GetMid(a, left, right);
	// ����Ԫ����midָ��Ԫ�ص�λ�ý��н���
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
// ����ָ�뷨
// �ڱ�����[left, right]����У����������һ�ο���
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