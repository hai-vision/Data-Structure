#define _CRT_SECURE_NO_WARNINGS
#include "MergeSort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
void TestSort()
{
	int arr[] = { 49,38,65,97,49,13,27,76 };	
	MergeSort(arr, 7);
	Print(arr, 7);
}


int main(){
	
	TestSort();
	return 0;
}