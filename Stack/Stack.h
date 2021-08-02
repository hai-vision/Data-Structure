#pragma once
#include <stdio.h>
#include <stdlib.h>


// 顺序表实现栈结构
typedef int STDatatype;

typedef struct StackNode {
	STDatatype* data;	// 栈的基址地址
	STDatatype top;		// 栈顶
	STDatatype capacity;	// 栈的容量
}Stack;

void StackInit(Stack* st);	// 初始化栈
void StackDestroy(Stack* st);
// 入栈
void StackPush(Stack* st, STDatatype x);	
// 出栈
void StackPop(Stack* st);
// 判断栈是否为空
int StackEmpty(Stack* st);
// 获取栈的长度
int StackSize(Stack* st);
// 获取栈顶元素
STDatatype StackFront(Stack* st);
