#include "MergeSort.h"
// �鲢����
/*
	�㷨ǰ��
	1��������������Ұ���������
	2������Ԫ�����������Ƚϣ�С�ķŵ���ʱ������
	3����ĳһ�����������ʣ�������ڵ�Ԫ�����ηŵ���ʱ����
	4������ʱ���鿽����ԭ����

	�㷨˼�룺
	1�����õݹ���ԣ������仮��Ϊ���������֡������䳤��Ϊ1ʱ���ٻ���
	2�����αȽ���������Ԫ�ش�С������С�ķŵ���ʱ����
	3���ٽ���ʱ�����е�ֵ������ԭ������
*/
void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right) {
		return;
	}
	int mid = (left + right) >> 1;	// ��λ�������黮��Ϊ������
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2<=end2) {
		if (a[begin1] < a[begin2]) {
			tmp[index++] = a[begin1++];		// ����++�� �ȸ�ֵ��ִ�м�1����
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
	// ���ص�ԭ����
	for (int i = left; i <= right; i++) {
		a[i] = tmp[i];
	}


}
// �鲢����

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);

}
