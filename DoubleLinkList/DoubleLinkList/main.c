#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include "DoubleLinkList.h"

int main()
{
	int	ret = 0;
	int	length = 0;
	DoubleLinkListNode*		node_ = NULL;
	DoubleLinkList*			list_=createLinkList();
	node_ = insertNodeToLinkList(list_, node_, 0);
	node_ = getNodeByLinkList(list_, 0);
	node_ = deleteNodeByLinkListNode(list_, node_);
	node_ = deleteNodeByLinkListPos(list_, 0);
	length = getLengthLinkList(list_);
	ret = clearLinkList(list_);
	ret = destoryLinkList(list_);
	system("pause");
	return 0;
}