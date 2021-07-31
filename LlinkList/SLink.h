#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDatatype;
// 声明一个单链表结构体
typedef struct SListNode{
	SListDatatype data;		// 数据域
	struct SListNode* next;	// 指针域
}SListNode;

// 尾插
void SListNodePushBack(SListNode** pphead, SListDatatype x);
// 尾删
void SListNodePopBack(SListNode** pphead);

// 头插
void SListNodePushFront(SListNode** pphead, SListDatatype x);
// 头删
void SListNodePopFront(SListNode** pphead);

// 按位查找
SListNode* SListNodeFindByPos(SListNode** pphead, SListDatatype x);
// 按值查找
SListNode* SListNodeFindByValue(SListNode** pphead, SListDatatype x);
// 按位序插入
void SListNodeInsertByPos(SListNode** pphead, SListDatatype x, SListDatatype y);
// 按位序删除
void SListNodeDelectByPos(SListNode** pphead, SListDatatype x);

// 节点创建
SListNode* CreateListNode(SListDatatype x);


// 结果输出
void SListNodePrint(SListNode* phead);
