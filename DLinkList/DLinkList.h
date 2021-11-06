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

// ��ʼ��˫������
void DLinkListInit(DListNode** phead);
// ����˫������
void DLinkListDestroy(DListNode** phead);
// β��
void DLinkListPushBack(DListNode** phead,ElemType x);
// βɾ
void DLinkListPopBack(DListNode** phead);
// ͷ��
void DLinkListPushFront(DListNode** phead, ElemType x);
// ͷɾ
void DLinkListPopFront(DListNode** phead);
// ��̬����һ�����
DListNode* CreateByListNode(ElemType x);
// ����˫������
void DListNodePrint(DListNode* phead);
// ��λ����
DListNode* DLinkListSearchByLocation(int x);

