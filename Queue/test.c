#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void test()
{
	QLinkList s;
	QueueInit(&s);
	QueuPush(&s, 1);
	QueuPush(&s, 2);
	QueuPush(&s, 3);
	QueuPush(&s, 4);
	QueuPush(&s, 5);
	QueuPush(&s, 6);
	QueuPush(&s, 7);


	//QueueDestroy(&s);
	while (QueueEmpty(&s)) {
		printf("%d ", QueueGetFront(&s));
		QueuePop(&s);
	}

}


int main(){
	//不带头结点的链队
	test();
	return 0;
}