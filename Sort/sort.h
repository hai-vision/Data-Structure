#pragma once

#include <stdio.h>

// ֱ�Ӳ�������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ������
void HeapSort(int* a, int n);
// ���µ����㷨
void AdjustDown(int* a, int n, int root);
void Swap(int* a, int* b);
// ��ѡ������
void SelectSort(int* a, int n);
// ���ڿӷ���ʵ�ֿ�������
void QuickSort(int* a, int left, int right);
// ��ӡ���
void PrintfArr(int* arr, int n);