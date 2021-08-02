#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;
// 结点结构体
typedef struct QNode{
	QDataType data;		// 数据域
	QDataType next;		// 指针域

}QNode;

// 头指针和尾指针
typedef struct QLinkList {
	QNode* front;		// 头指针
	QNode* rear;		// 尾指针
}QLinkList;

// 初始化队列
void QueueInit(QLinkList* pq);
// 销毁
void QueueDestroy(QLinkList* pq);
// 入队
void QueuPush(QLinkList* pq, QDataType x);
// 出队
void QueuePop(QLinkList* pq);
// 获取队头元素
QDataType QueueGetFront(QLinkList* pq);
// 队空判断
int QueueEmpty(QLinkList* pq);
// 获取队列长度
int QueueSize(QLinkList* pq);
// 申请结点
QNode* QueueCreateQNode(QDataType x);