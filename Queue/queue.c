#include "queue.h"

// 初始化队列
void QueueInit(QLinkList* pq)
{
	pq->front = pq->rear = NULL;
}
// 销毁
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
// 入队
void QueuPush(QLinkList* pq, QDataType x)
{
	// 申请结点
	QNode* newNode = QueueCreateQNode(x);
	if (newNode==NULL) {
		printf("结点申请失败！\n");
	}
	if (pq->rear == NULL) {// 如果队列为空
		pq->front = pq->rear = newNode;
	}
	else {// 队列不为空
		pq->rear->next = newNode;
		pq->rear = newNode;		// 更新尾指针的位置
	}

}
// 出队
void QueuePop(QLinkList* pq)
{
	// 如果队列为空
	if (pq->rear == NULL) {
		printf("队列为空\n");
		exit(-1);
	}
	//如果队中只有一个元素
	if (pq->front->next == NULL) {
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	// 队列中有一个以上的元素
	else {
		QLinkList* next = pq->front->next;
		free(pq->front);
		pq->front = next;	// 更新头指针

	}
	
}
// 获取队头元素
QDataType QueueGetFront(QLinkList* pq)
{
	assert(pq);
	assert(pq->front);
	return pq->front->data;
}
// 队空判断
int QueueEmpty(QLinkList* pq)
{
	return pq->front;
}
// 获取队列长度
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
// 申请结点
QNode* QueueCreateQNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = x;
	newNode->next = NULL;
}