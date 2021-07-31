#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDatatype;
// ����һ��������ṹ��
typedef struct SListNode{
	SListDatatype data;		// ������
	struct SListNode* next;	// ָ����
}SListNode;

// β��
void SListNodePushBack(SListNode** pphead, SListDatatype x);
// βɾ
void SListNodePopBack(SListNode** pphead);

// ͷ��
void SListNodePushFront(SListNode** pphead, SListDatatype x);
// ͷɾ
void SListNodePopFront(SListNode** pphead);

// ��λ����
SListNode* SListNodeFindByPos(SListNode** pphead, SListDatatype x);
// ��ֵ����
SListNode* SListNodeFindByValue(SListNode** pphead, SListDatatype x);
// ��λ�����
void SListNodeInsertByPos(SListNode** pphead, SListDatatype x, SListDatatype y);
// ��λ��ɾ��
void SListNodeDelectByPos(SListNode** pphead, SListDatatype x);

// �ڵ㴴��
SListNode* CreateListNode(SListDatatype x);


// ������
void SListNodePrint(SListNode* phead);
