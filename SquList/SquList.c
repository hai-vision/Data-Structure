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
void SquListDestroy(SqList* ps)
{
	free(ps->data);	// 释放指向顺序表的指针
	ps->length = 0;
	ps->capacity = 0;
}

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
void SquListPop(SqList* ps) 
{
	assert(ps);
	// 直接将顺序表的长度减一，以实现删除末尾的数据
	if (ps->length >= 0) {
		ps->length--;
	}
	else {
		printf("顺序表已为空！\n");
	}
	
}

// 顺序表的头插
void SquListPushFront(SqList* ps, DataType x)
{
	assert(ps);
	// 如果容量满了需要增容
	ps->capacity *= 2;		// 增2倍
	if (ps->length >= ps->capacity) {
		ps->data = (DataType*)realloc(ps->data, ps->capacity * sizeof(DataType));
	}
	// 从末尾元素开始，所有元素依次后移，并且顺序表的长度加1
	for (int i = ps->length; i > 0; i--) {
		ps->data[i] = ps->data[i-1];	// 从末尾开始后移
	}
	ps->data[0] = x;
	ps->length++;

}
// 顺序表的头删
void SquListPopFront(SqList* ps)
{
	assert(ps);
	if (ps->length >= 0) {
		// 从删除元素开始，后面元素前移，顺序表的长度减1；
		for (int i = 0; i < ps->length - 1; i++) {
			ps->data[i] = ps->data[i + 1];
		}
		ps->length--;
	}
	else {
		printf("顺序表已为空！\n");
	}
	

}

// 结果打印
void SquListPrint(SqList* ps)
{
	for (int i = 0; i < ps->length; i++) {
		printf("%d\n", ps->data[i]);
	}
}
