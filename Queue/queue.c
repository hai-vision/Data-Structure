#include "queue.h"

// ��ʼ������
void QueueInit(QLinkList* pq)
{
	pq->front = pq->rear = NULL;
}
// ����
void QueueDestroy(QLinkList* pq)
{
	QNode* cur = pq->front;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;
}
// ���
void QueuPush(QLinkList* pq, QDataType x)
{
	// ������
	QNode* newNode = QueueCreateQNode(x);
	if (newNode==NULL) {
		printf("�������ʧ�ܣ�\n");
	}
	if (pq->rear == NULL) {// �������Ϊ��
		pq->front = pq->rear = newNode;
	}
	else {// ���в�Ϊ��
		pq->rear->next = newNode;
		pq->rear = newNode;		// ����βָ���λ��
	}

}
// ����
void QueuePop(QLinkList* pq)
{
	// �������Ϊ��
	if (pq->rear == NULL) {
		printf("����Ϊ��\n");
		exit(-1);
	}
	//�������ֻ��һ��Ԫ��
	if (pq->front->next == NULL) {
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	// ��������һ�����ϵ�Ԫ��
	else {
		QLinkList* next = pq->front->next;
		free(pq->front);
		pq->front = next;	// ����ͷָ��

	}
	
}
// ��ȡ��ͷԪ��
QDataType QueueGetFront(QLinkList* pq)
{
	assert(pq);
	assert(pq->front);
	return pq->front->data;
}
// �ӿ��ж�
int QueueEmpty(QLinkList* pq)
{
	return pq->front;
}
// ��ȡ���г���
int QueueSize(QLinkList* pq)
{
	int size = 0;
	QNode* cur = pq->front;
	while (cur) {
		size++;
		cur = cur->next;
	}
	return size;
}
// ������
QNode* QueueCreateQNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = x;
	newNode->next = NULL;
}