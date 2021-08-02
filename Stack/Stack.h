#pragma once
#include <stdio.h>
#include <stdlib.h>


// ˳���ʵ��ջ�ṹ
typedef int STDatatype;

typedef struct StackNode {
	STDatatype* data;	// ջ�Ļ�ַ��ַ
	STDatatype top;		// ջ��
	STDatatype capacity;	// ջ������
}Stack;

void StackInit(Stack* st);	// ��ʼ��ջ
void StackDestroy(Stack* st);
// ��ջ
void StackPush(Stack* st, STDatatype x);	
// ��ջ
void StackPop(Stack* st);
// �ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* st);
// ��ȡջ�ĳ���
int StackSize(Stack* st);
// ��ȡջ��Ԫ��
STDatatype StackFront(Stack* st);
