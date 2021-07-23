#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SquList.h"

// 初始化顺序表
void SquListInit(SqList* ps)
{
	// 为顺序表动态开辟一块连续的存储空间
	ps->data = (SqList*)malloc(4* sizeof(DataType));
	ps->length = 0;	// 当前顺序表的长度
	ps->capacity = 4;	// 顺序表的当前长度
}
// 顺序表的销毁
void SquListDestroy(SqList* ps);

// 顺序的尾插
void SquListPush(SqList* ps, DataType x)
{
	assert(ps);		// 断言函数
	// 如果容量满了需要增容
	if (ps->length >= ps->capacity) {
		ps->capacity *= 2;		// 扩容两倍
		ps->data = (DataType*)realloc(ps->data, sizeof(DataType)*ps->capacity);
		if (ps->data == NULL)
		{
			printf("扩容失败！\n");
			exit(0);
		}
	}
	ps->data[ps->length] = x;
	ps->length++;

}
// 顺序表的尾删
void SquListPop(SqList* ps);

// 顺序表的头删和头插
void SquListPushFront(SqList* ps, DataType x);
void SquListPopFront(SqList* ps);

// 结果打印
void SquListPrint(SqList* ps)
{
	for (int i = 0; i < ps->length; i++) {
		printf("%d\n", ps->data[i]);
	}
}