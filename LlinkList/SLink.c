#include "SLink.h"

// β��
void SListNodePushBack(SListNode** pphead, SListDatatype x)
{
	SListNode* tail = *pphead;		// ����һ��βָ��
	// 1��������Ϊ��ʱ
	if (*pphead == NULL) {
		*pphead = CreateListNode(x);	// ����һ���½�㣬����ͷָ��ָ���´����Ľڵ�
	}
	else {	// ������Ϊ��
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = CreateListNode(x);
	}
}
// βɾ
void SListNodePopBack(SListNode** pphead)
{
	SListNode* tail = *pphead;		// ����һ��βָ��
	SListNode* prev = NULL;		// ����һ��ָ�룬���ڴ��tailָ��ָ�����ֱ��ǰ��
	//1��������Ϊ��ʱ
	if (*pphead == NULL) {
		printf("����Ϊ��\n");
		exit(0);
	}
	else if ((*pphead)->next == NULL) {
		// 2����ֻ��һ��Ԫ�ؽ��
		*pphead = NULL;
	}
	else {
		// 3����������1�����ϵ�Ԫ�ؽ��
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		// �ҵ�β
		free(tail);
		prev->next = NULL;	// ��prevָ��ָ�����һ��ַ��Ϊ�գ���ֹҰָ��
	}
}

// ͷ��
void SListNodePushFront(SListNode** pphead, SListDatatype x)
{
	// ����һ���½��
	SListNode* newNode = CreateListNode(x);
	SListNode* cur = *pphead;
	// 1��������Ϊ��ʱ
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		// 2��������Ϊ��ʱ
		newNode->next = cur;	// ���´�����ָ��nextָ��cur
		*pphead = newNode;		// ��ͷָ��ָ��newNode�ĵ�ַ
	}
}
// ͷɾ
void SListNodePopFront(SListNode** pphead)
{
	SListNode* tail = *pphead;
	
	if (*pphead == NULL) {
		// 1��������Ϊ��ʱ
		printf("����Ϊ��\n");
		exit(0);
	}
	else {
		// 2��������Ϊ��ʱ
		SListNode* next = tail->next;
		*pphead = next;
		free(tail);
	}

}
// ��λ����
/**
	����λ��Ϊx��Ԫ�ؽ��
*/
SListNode* SListNodeFindByPos(SListNode** pphead, SListDatatype x)
{
	assert(*pphead);
	SListNode* tail = *pphead;
	int j = 1;	// ��ǰԪ�ؽ���λ��
	if (x <= 0) {
		return NULL;
	}
	while(tail != NULL && j<x){
		tail = tail->next;
		j++;		
	}
	return tail;
}
// ��ֵ����
SListNode* SListNodeFindByValue(SListNode** pphead, SListDatatype x)
{
	assert(*pphead);
	SListNode* tail = *pphead;
	if (x < 0) {
		return NULL;	// �����Ϊ��
	}
	else {
		// �߽��޶�
		while (tail != NULL && tail->data != x) {
			tail = tail->next;
		}
		return tail;
	}
}

// ��λ�����
void SListNodeInsertByPos(SListNode**  pphead, SListDatatype x, SListDatatype y)
{

	SListNode* node = SListNodeFindByPos(&(*pphead), y-1);	// ��ָ��λ��ǰ����
	if (node) {
		SListNode* node_next = node->next;
		SListNode* newNode = CreateListNode(x);		// ����һ���½��
		newNode->next = node_next;
		node->next = newNode;
	}
	else {
		printf("λ������Ƿ�\n");
	}
}

// ��λ��ɾ��
void SListNodeDelectByPos(SListNode** pphead, SListDatatype x)
{
	
	SListNode* node = SListNodeFindByPos(&(*pphead), x);		// �жϴ�ɾ����λ���Ƿ����
	// ����ɾ���Ľڵ�Ϊ��һ��Ԫ�ؽ��ʱ
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
			printf("λ������Ƿ�\n");
		}
	}
}

SListNode* CreateListNode(SListDatatype x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));	// ��̬����һ�����
	newNode->data = x;
	newNode->next = NULL;	// ��newNode��next��Ϊ�գ���ֹҰָ��

}
// ������
void SListNodePrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
	
}