#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"


void TestSort()
{

	int arr[] = { 3,7,5,1,2,6,4,0,9,8 };
	//InsertSort(arr, sizeof(arr)/sizeof(int));
	//ShellSort(arr, sizeof(arr) / sizeof(int));
	//HeapSort(arr, sizeof(arr) / sizeof(int));

	//SelectSort(arr, sizeof(arr) / sizeof(int));

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	PrintfArr(arr, sizeof(arr) / sizeof(int));

}

int main(){
	
	TestSort();
	return 0;
}