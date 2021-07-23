#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
// �ṹ������
typedef struct SqList {
	DataType* data;
	DataType length;		// ��ǰ˳���ĳ���
	DataType capacity;	// ˳��������
}SqList;

// ��ʼ��˳���
void SquListInit(SqList* ps);
// ˳��������
void SquListDestroy(SqList* ps);

// ˳���β���βɾ
void SquListPush(SqList* ps, DataType x);
void SquListPop(SqList* ps);

// ˳����ͷɾ��ͷ��
void SquListPushFront(SqList* ps, DataType x);
void SquListPopFront(SqList* ps);

// �����ӡ
void SquListPrint(SqList* ps);

