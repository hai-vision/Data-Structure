#include "DLinkList.h"
/**
	����ָ��ʵ�ִ�ͷ����˫������
*/

/*
	ע������
	1��plist ��ʵ�Σ�c����DLinkListInit()�Ĳ�����plist����ʱ����
	2��phead�ĸı䲻��Ӱ��plist�ı任�������Ҫ������ָ�룬��plist�ĵ�ַ

*/
void test()
{
	// ����һ���ṹ��ָ��
	DListNode* plist = NULL;
	DLinkListInit(&plist);
	// β��Ԫ��
	DLinkListPushBack(&plist, 1);
	DLinkListPushBack(&plist, 2);
	DLinkListPushBack(&plist, 3);
	DLinkListPushBack(&plist, 4);
	// ��������Ԫ��
	DListNodePrint(plist);

	// βɾ
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);
	//DLinkListPopBack(&plist);

	// ͷ��
	//DLinkListPushFront(&plist, 5);
	//DLinkListPushFront(&plist, 6);
	//DLinkListPushFront(&plist, 7);

	// ͷɾ
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
