#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SquList.h"

void test() {
	SqList L;
	SquListInit(&L);
	SquListPush(&L, 1);
	SquListPush(&L, 2);
	SquListPush(&L, 3);
	SquListPush(&L, 4);
	/*SquListPushFront(&L, 0);
	SquListPushFront(&L, 7);*/

	SquListPopFront(&L);
	SquListPrint(&L);

	/*SquListPop(&L);
	SquListPrint(&L);*/

}
int main(){
	
	
	test();

	return 0;
}
