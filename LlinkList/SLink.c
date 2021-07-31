#include "SLink.h"

// 尾插
void SListNodePushBack(SListNode** pphead, SListDatatype x)
{
	SListNode* tail = *pphead;		// 定义一个尾指针
	// 1、当链表为空时
	if (*pphead == NULL) {
		*pphead = CreateListNode(x);	// 创建一个新结点，并让头指针指向新创建的节点
	}
	else {	// 当链表不为空
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = CreateListNode(x);
	}
}
// 尾删
void SListNodePopBack(SListNode** pphead)
{
	SListNode* tail = *pphead;		// 定义一个尾指针
	SListNode* prev = NULL;		// 定义一个指针，用于存放tail指针指向结点的直接前驱
	//1、当链表为空时
	if (*pphead == NULL) {
		printf("链表为空\n");
		exit(0);
	}
	else if ((*pphead)->next == NULL) {
		// 2、当只有一个元素结点
		*pphead = NULL;
	}
	else {
		// 3、当链表有1个以上的元素结点
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		// 找到尾
		free(tail);
		prev->next = NULL;	// 将prev指针指向的下一地址置为空，防止野指针
	}
}

// 头插
void SListNodePushFront(SListNode** pphead, SListDatatype x)
{
	// 创建一个新结点
	SListNode* newNode = CreateListNode(x);
	SListNode* cur = *pphead;
	// 1、当链表为空时
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		// 2、当链表不为空时
		newNode->next = cur;	// 让新创建的指针next指向cur
		*pphead = newNode;		// 让头指针指向newNode的地址
	}
}
// 头删
void SListNodePopFront(SListNode** pphead)
{
	SListNode* tail = *pphead;
	
	if (*pphead == NULL) {
		// 1、当链表为空时
		printf("链表为空\n");
		exit(0);
	}
	else {
		// 2、当链表不为空时
		SListNode* next = tail->next;
		*pphead = next;
		free(tail);
	}

}
// 按位查找
/**
	查找位序为x的元素结点
*/
SListNode* SListNodeFindByPos(SListNode** pphead, SListDatatype x)
{
	assert(*pphead);
	SListNode* tail = *pphead;
	int j = 1;	// 当前元素结点的位序
	if (x <= 0) {
		return NULL;
	}
	while(tail != NULL && j<x){
		tail = tail->next;
		j++;		
	}
	return tail;
}
// 按值查找
SListNode* SListNodeFindByValue(SListNode** pphead, SListDatatype x)
{
	assert(*pphead);
	SListNode* tail = *pphead;
	if (x < 0) {
		return NULL;	// 当结点为空
	}
	else {
		// 边界限定
		while (tail != NULL && tail->data != x) {
			tail = tail->next;
		}
		return tail;
	}
}

// 按位序插入
void SListNodeInsertByPos(SListNode**  pphead, SListDatatype x, SListDatatype y)
{

	SListNode* node = SListNodeFindByPos(&(*pphead), y-1);	// 在指定位序前插入
	if (node) {
		SListNode* node_next = node->next;
		SListNode* newNode = CreateListNode(x);		// 创建一个新结点
		newNode->next = node_next;
		node->next = newNode;
	}
	else {
		printf("位序输入非法\n");
	}
}

// 按位序删除
void SListNodeDelectByPos(SListNode** pphead, SListDatatype x)
{
	
	SListNode* node = SListNodeFindByPos(&(*pphead), x);		// 判断待删除的位序是否存在
	// 当待删除的节点为第一个元素结点时
	if (x == 1) {
		SListNode* node = SListNodeFindByPos(&(*pphead), x);
		SListNode* nodeNext = node->next;
		(*pphead)->next = nodeNext;
		free(node);
		*pphead = nodeNext;
	}
	else {
		if (node) {
			SListNode* node = SListNodeFindByPos(&(*pphead), x - 1);
			SListNode* delNode = node->next;
			node->next = delNode->next;
			delNode->next = NULL;
			free(delNode);
		}
		else {
			printf("位序输入非法\n");
		}
	}
}

SListNode* CreateListNode(SListDatatype x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));	// 动态申请一个结点
	newNode->data = x;
	newNode->next = NULL;	// 将newNode的next置为空，防止野指针

}
// 结果输出
void SListNodePrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
	
}