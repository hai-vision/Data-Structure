#include "DLinkList.h"

// 初始化双向链表
void DLinkListInit(DListNode** phead)
{
	*phead = CreateByListNode(0);
	(*phead)->next = (*phead);
	(*phead)->prev = (*phead);

}

// 销毁双向链表
void DLinkListDestroy(DListNode** phead)
{
	// 当双向链表为空时，不需进行任何处理
	if ((*phead)->next == (*phead)->prev) {
		printf("链表已为空！");
		return;
	}

	// 定义 cur 指针，用于保存头结点后一位结点
	DListNode* cur = (*phead)->next;

	while (cur != NULL) {
		// 当链表除了头结点为，只有一个元素结点
		if (cur->next == NULL) {
			free(cur);
			(*phead)->next = NULL;
			cur = NULL;
		}
		else {
			(*phead)->next = cur->next;
			cur->next->prev = (*phead);
			free(cur);
			cur = (*phead)->next;
		}
	}
	
}

// 尾插
void DLinkListPushBack(DListNode** phead,ElemType x)
{
	// 调用CreateByListNode()，动态申请一个新结点
	DListNode* newNode = CreateByListNode(x);

	// 判断双向链表是否为空，若为空，直接在头结点后插入新的结点
	if ((*phead)->next == (*phead)->prev) {
		(*phead)->next = newNode;
		newNode->prev = (*phead);
	}
	else {
		// 定义一个尾指针，同于遍历和指针的指向
		DListNode* tail = (*phead)->next;

		// 遍历到最后一个结点
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;		

	}
}

// 尾删
void DLinkListPopBack(DListNode** phead)
{
	// 定义一个尾指针
	DListNode* tail = (*phead)->next;
	// 定义一个 prev 指针，用于保存尾指针的前一指针
	DListNode* prev = NULL;

	// 当链表为空时,不做任何处理
	if ((*phead)->next == (*phead)->prev) {
		printf("链表已空\n");
		return;
	}
	// 当链表中出头结点外，只有一个元素结点
	if (tail->next == NULL) {
		(*phead)->next = (*phead)->prev;
		return;
	}
	else {
		while (tail->next != NULL) {
			tail = tail->next;
		}
		prev = tail->prev;
		prev->next = NULL;
		free(tail);
	}

}

// 头插
void DLinkListPushFront(DListNode** phead, ElemType x)
{
	// 调用CreateByListNode()，动态申请一个新结点
	DListNode* newNode = CreateByListNode(x);
	// cur 指针指向首元素结点
	DListNode* cur = (*phead)->next;

	// 当链表为空是，直接将 newNode 结点插入到头结点之后
	if ((*phead)->next == (*phead)->prev) {
		(*phead)->next = newNode;
		newNode->prev = *phead;
	}
	// 当链表不为空
	else {
		newNode->next = cur;
		newNode->prev = *phead;
		cur->prev = newNode;
		(*phead)->next = newNode;

	}
}

// 头删
void DLinkListPopFront(DListNode** phead)
{
	// cur 指针指向首元素结点
	DListNode* cur = (*phead)->next;

	// 当链表为空
	if ((*phead)->next == (*phead)->prev) {
		printf("链表已为空！\n");
		return;
	}
	// 当链表除了头结点外，只有一个元素结点
	if (cur->next == NULL) {
		(*phead)->next = (*phead)->prev;
		free(cur);
	}
	else {
		(*phead)->next = cur->next;
		cur->next->prev = *phead;
		free(cur);

	}
}

// 动态申请一个结点
DListNode* CreateByListNode(ElemType x)
{
	// 利用malloc 动态申请一个结点
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL) {
		printf("结点申请失败！");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;

}

// 遍历双向链表
void DListNodePrint(DListNode* phead)
{
	DListNode* cur = phead->next;
	// 当链表不为空且 cur 指针不为空
	while (phead->next !=phead->prev && cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}

// 按位查找
DListNode* DLinkListSearchByLocation(int x)
{

}