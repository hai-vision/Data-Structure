#define _CRT_SECURE_NO_WARNINGS
#include "SLink.h"

void test() {

	SListNode* pList = NULL;	// ����һ��ͷָ�룬����Ϊ��
	SListNodePushBack(&pList, 1);
	SListNodePushBack(&pList, 2);
	SListNodePushBack(&pList, 3);
	SListNodePushBack(&pList, 4);
	SListNodePushBack(&pList, 5);


	SListNodePrint(pList);
	/*SListNodePushFront(&pList, 0);
	SListNodePushFront(&pList, -1);

	SListNodePushFront(&pList, -2);
	SListNodePushFront(&pList, -3);
	SListNodePushFront(&pList, -4);*/

	/*SListNodePopFront(&pList);
	SListNodePopFront(&pList);
	SListNodePopFront(&pList);
	SListNodePopFront(&pList);
	SListNodePopFront(&pList);
	SListNodePopFront(&pList);*/
	

	/*SListNodeInsertByPos(&pList, -1, 2);
	SListNodeInsertByPos(&pList, -1, 5);*/
	//SListNodeInsertByPos(&pList, -1, 6);
	//SListNodeInsertByPos(&pList, -1, 4);

	SListNodeDelectByPos(&pList, 1);


	/*SListNode* node = SListNodeFindByPos(&pList, 6);
	if (node) {
		printf("%d\n", node->data);
	}
	else {
		printf("�������Ƿ�\n");
	}*/



	SListNodePrint(pList);
}

int main(){
	
	test();
	return 0;
}