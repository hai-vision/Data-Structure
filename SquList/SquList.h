#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
// 结构体声明
typedef struct SqList {
	DataType* data;
	DataType length;		// 当前顺序表的
	DataType capacity;	// 顺序表的容量
}SqList;

// 初始化顺序表
void SquListInit(SqList* ps);
// 顺序表的销毁
void SquListDestroy(SqList* ps);

// 顺序的尾插和尾删
void SquListPush(SqList* ps, DataType x);
void SquListPop(SqList* ps);

// 顺序表的头删和头插
void SquListPushFront(SqList* ps, DataType x);
void SquListPopFront(SqList* ps);

// 结果打印
void SquListPrint(SqList* ps);

