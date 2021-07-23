#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SquList.h"

// ��ʼ��˳���
void SquListInit(SqList* ps)
{
	// Ϊ˳���̬����һ�������Ĵ洢�ռ�
	ps->data = (SqList*)malloc(4* sizeof(DataType));
	ps->length = 0;	// ��ǰ˳���ĳ���
	ps->capacity = 4;	// ˳���ĵ�ǰ����
}
// ˳��������
void SquListDestroy(SqList* ps);

// ˳���β��
void SquListPush(SqList* ps, DataType x)
{
	assert(ps);		// ���Ժ���
	// �������������Ҫ����
	if (ps->length >= ps->capacity) {
		ps->capacity *= 2;		// ��������
		ps->data = (DataType*)realloc(ps->data, sizeof(DataType)*ps->capacity);
		if (ps->data == NULL)
		{
			printf("����ʧ�ܣ�\n");
			exit(0);
		}
	}
	ps->data[ps->length] = x;
	ps->length++;

}
// ˳����βɾ
void SquListPop(SqList* ps);

// ˳����ͷɾ��ͷ��
void SquListPushFront(SqList* ps, DataType x);
void SquListPopFront(SqList* ps);

// �����ӡ
void SquListPrint(SqList* ps)
{
	for (int i = 0; i < ps->length; i++) {
		printf("%d\n", ps->data[i]);
	}
}