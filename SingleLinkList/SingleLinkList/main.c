#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include"SingleLinkList.h"

int main()
{
	int ret_ = 0;
	int len_ = 0;
	SingleLinkListNode*	node_ = NULL;
	SingleLinkList*	list_ = createLinkList();

	ret_ =destoryLinkList(list_);
	len_=getLinkListLength(list_);
	ret_=clearLinkList(list_);
	node_=deleteNodeByLinkListPos(list_, 0);
	node_=insertNodeByLinkList(list_, node_, 0);
	node_=deleteNodeByLinkListNode(list_, node_);

	system("pause");
	return 0;
}