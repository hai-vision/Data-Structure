#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;
// ���ṹ��
typedef struct QNode{
	QDataType data;		// ������
	QDataType next;		// ָ����

}QNode;

// ͷָ���βָ��
typedef struct QLinkList {
	QNode* front;		// ͷָ��
	QNode* rear;		// βָ��
}QLinkList;

// ��ʼ������
void QueueInit(QLinkList* pq);
// ����
void QueueDestroy(QLinkList* pq);
// ���
void QueuPush(QLinkList* pq, QDataType x);
// ����
void QueuePop(QLinkList* pq);
// ��ȡ��ͷԪ��
QDataType QueueGetFront(QLinkList* pq);
// �ӿ��ж�
int QueueEmpty(QLinkList* pq);
// ��ȡ���г���
int QueueSize(QLinkList* pq);
// ������
QNode* QueueCreateQNode(QDataType x);