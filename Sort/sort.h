#pragma once

#include <stdio.h>

// 直接插入排序
void InsertSort(int* a, int n);
// 希尔排序
void ShellSort(int* a, int n);
// 堆排序
void HeapSort(int* a, int n);
// 向下调整算法
void AdjustDown(int* a, int n, int root);
void Swap(int* a, int* b);
// 简单选择排序
void SelectSort(int* a, int n);
// “挖坑法”实现快速排序
void QuickSort(int* a, int left, int right);
// 打印输出
void PrintfArr(int* arr, int n);