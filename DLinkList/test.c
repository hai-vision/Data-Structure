#include "DLinkList.h"
/**
	二级指针实现带头结点的双向链表
*/

/*
	注意事项
	1、plist 是实参，c传给DLinkListInit()的参数是plist的临时拷贝
	2、phead的改变不会影响plist的变换，因此需要传二级指针，即plist的地址

*/
void test()
{
	// 定义一个结构体指针
	DListNode* plist = NULL;
	DLinkListInit(&plist);
	// 尾插元素
	DLinkListPushBack(&plist, 1);
	DLinkListPushBack(&plist, 2);
	DLinkListPushBack(&plist, 3);
	DLinkListPushBack(&plist, 4);
	// 遍历链表元素
	DListNodePrint(plist);

	// 尾删
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);

	// 头插
	//DLinkListPushFront(&plist, 5);
	//DLinkListPushFront(&plist, 6);
	//DLinkListPushFront(&plist, 7);

	// 头删
	//DLinkListPopFront(&plist);
	//DLinkListPopFront(&plist);
	//DLinkListPopFront(&plist);
	//DLinkListPopFront(&plist);
	//DLinkListPopFront(&plist);



	//DLinkListDestroy(&plist);
	DListNodePrint(plist);
}


int main()
{
	test();

	return 0;
}
