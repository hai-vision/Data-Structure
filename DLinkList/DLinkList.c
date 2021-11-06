#include "DLinkList.h"

// ��ʼ��˫������
void DLinkListInit(DListNode** phead)
{
	*phead = CreateByListNode(0);
	(*phead)->next = (*phead);
	(*phead)->prev = (*phead);

}

// ����˫������
void DLinkListDestroy(DListNode** phead)
{
	// ��˫������Ϊ��ʱ����������κδ���
	if ((*phead)->next == (*phead)->prev) {
		printf("������Ϊ�գ�");
		return;
	}

	// ���� cur ָ�룬���ڱ���ͷ����һλ���
	DListNode* cur = (*phead)->next;

	while (cur != NULL) {
		// ���������ͷ���Ϊ��ֻ��һ��Ԫ�ؽ��
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

// β��
void DLinkListPushBack(DListNode** phead,ElemType x)
{
	// ����CreateByListNode()����̬����һ���½��
	DListNode* newNode = CreateByListNode(x);

	// �ж�˫�������Ƿ�Ϊ�գ���Ϊ�գ�ֱ����ͷ��������µĽ��
	if ((*phead)->next == (*phead)->prev) {
		(*phead)->next = newNode;
		newNode->prev = (*phead);
	}
	else {
		// ����һ��βָ�룬ͬ�ڱ�����ָ���ָ��
		DListNode* tail = (*phead)->next;

		// ���������һ�����
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;		

	}
}

// βɾ
void DLinkListPopBack(DListNode** phead)
{
	// ����һ��βָ��
	DListNode* tail = (*phead)->next;
	// ����һ�� prev ָ�룬���ڱ���βָ���ǰһָ��
	DListNode* prev = NULL;

	// ������Ϊ��ʱ,�����κδ���
	if ((*phead)->next == (*phead)->prev) {
		printf("�����ѿ�\n");
		return;
	}
	// �������г�ͷ����⣬ֻ��һ��Ԫ�ؽ��
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

// ͷ��
void DLinkListPushFront(DListNode** phead, ElemType x)
{
	// ����CreateByListNode()����̬����һ���½��
	DListNode* newNode = CreateByListNode(x);
	// cur ָ��ָ����Ԫ�ؽ��
	DListNode* cur = (*phead)->next;

	// ������Ϊ���ǣ�ֱ�ӽ� newNode �����뵽ͷ���֮��
	if ((*phead)->next == (*phead)->prev) {
		(*phead)->next = newNode;
		newNode->prev = *phead;
	}
	// ������Ϊ��
	else {
		newNode->next = cur;
		newNode->prev = *phead;
		cur->prev = newNode;
		(*phead)->next = newNode;

	}
}

// ͷɾ
void DLinkListPopFront(DListNode** phead)
{
	// cur ָ��ָ����Ԫ�ؽ��
	DListNode* cur = (*phead)->next;

	// ������Ϊ��
	if ((*phead)->next == (*phead)->prev) {
		printf("������Ϊ�գ�\n");
		return;
	}
	// ���������ͷ����⣬ֻ��һ��Ԫ�ؽ��
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

// ��̬����һ�����
DListNode* CreateByListNode(ElemType x)
{
	// ����malloc ��̬����һ�����
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL) {
		printf("�������ʧ�ܣ�");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;

}

// ����˫������
void DListNodePrint(DListNode* phead)
{
	DListNode* cur = phead->next;
	// ������Ϊ���� cur ָ�벻Ϊ��
	while (phead->next !=phead->prev && cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}

// ��λ����
DListNode* DLinkListSearchByLocation(int x)
{

}