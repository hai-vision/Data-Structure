#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SquList.h"

void test() {
	SqList L;
	SquListInit(&L);
	SquListPush(&L, 1);
	SquListPush(&L, 1);
	SquListPush(&L, 1);
	SquListPush(&L, 1);
	SquListPush(&L, 1);
	SquListPush(&L, 1);
	printf("%d\t%d\n", L.capacity, L.length);

	
	SquListPrint(&L);


}
int main(){
	
	
	test();

	return 0;
}