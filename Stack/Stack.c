#include  "Stack.h"

// ��ʼ��ջ
void StackInit(Stack* st)
{
	st->data = (Stack*)malloc(sizeof(STDatatype) * 4);
	st->capacity = 4;		// ջ�ĳ�ʼ����
	st->top = 0;				// ʼ��ָ��ջ��Ԫ�ص���һ��
}
void StackDestroy(Stack* st)
{
	free(st->data);
	st->data = NULL;
	st->top = st->capacity = 0;
}
// ��ջ
void StackPush(Stack* st, STDatatype x)
{
	// ���ջ��
	if (st->top == st->capacity) {
		st->capacity *= 2;
		st->data = (Stack*)realloc(st->data, sizeof(STDatatype) * st->capacity);
	}
	st->data[st->top] = x;
	st->top++;
}
// ��ջ
void StackPop(Stack* st)
{
	// ���ջΪ��
	if (!StackEmpty(&st)) {// ջ��
		printf("ջΪ��\n");
	}
	else {
		st->top--;
	}
}
// �ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* st) {
	return st->top;
}
// ��ȡջ�ĳ���
int StackSize(Stack* st)
{
	return st->top;
}
// ��ȡջ��Ԫ��
STDatatype StackFront(Stack* st)
{
	return st->data[st->top - 1];
}