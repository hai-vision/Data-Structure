#include  "Stack.h"

// 初始化栈
void StackInit(Stack* st)
{
	st->data = (Stack*)malloc(sizeof(STDatatype) * 4);
	st->capacity = 4;		// 栈的初始容量
	st->top = 0;				// 始终指向栈顶元素的上一个
}
void StackDestroy(Stack* st)
{
	free(st->data);
	st->data = NULL;
	st->top = st->capacity = 0;
}
// 入栈
void StackPush(Stack* st, STDatatype x)
{
	// 如果栈满
	if (st->top == st->capacity) {
		st->capacity *= 2;
		st->data = (Stack*)realloc(st->data, sizeof(STDatatype) * st->capacity);
	}
	st->data[st->top] = x;
	st->top++;
}
// 出栈
void StackPop(Stack* st)
{
	// 如果栈为空
	if (!StackEmpty(&st)) {// 栈空
		printf("栈为空\n");
	}
	else {
		st->top--;
	}
}
// 判断栈是否为空
int StackEmpty(Stack* st) {
	return st->top;
}
// 获取栈的长度
int StackSize(Stack* st)
{
	return st->top;
}
// 获取栈顶元素
STDatatype StackFront(Stack* st)
{
	return st->data[st->top - 1];
}