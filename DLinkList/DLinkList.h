#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DLinkNode
{
	ElemType data;
	struct DLinkNode* prev;
	struct DLinkNode* next;
}DListNode;

// 初始化双向链表
void DLinkListInit(DListNode** phead);
// 销毁双向链表
void DLinkListDestroy(DListNode** phead);
// 尾插
void DLinkListPushBack(DListNode** phead,ElemType x);
// 尾删
void DLinkListPopBack(DListNode** phead);
// 头插
void DLinkListPushFront(DListNode** phead, ElemType x);
// 头删
void DLinkListPopFront(DListNode** phead);
// 动态申请一个结点
DListNode* CreateByListNode(ElemType x);
// 遍历双向链表
void DListNodePrint(DListNode* phead);
// 按位查找
DListNode* DLinkListSearchByLocation(int x);

