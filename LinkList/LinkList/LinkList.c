#include "LinkList.h"
#include<stdio.h>

typedef struct _tagLinkList 
{
	int				len_;
	LinkListNode	*node;
}TLinkList;

LinkList*	createLinkList()
{
	TLinkList	*list_ = (TLinkList*)malloc(sizeof(TLinkList));
	memset(list_, 0, sizeof(TLinkList));
	return list_;
}

int			destoryLinkList(LinkList* list_)
{
	return 0;
}

int			getLinkListLength(LinkList*	list_)
{
	return 0;
}

LinkListNode*	insertToLinkList(LinkList*	list_, LinkListNode*	node_, int pos)
{
	return NULL;
}

LinkListNode*	getNodeByLinkList(LinkList*	list_, int pos)
{
	return NULL;
}

LinkListNode*	deleteNodeByPos(LinkList*	list_, int pos)
{
	return NULL;
}

LinkListNode*	deleteNodeByNode(LinkList*	list_, LinkListNode*	node_)
{
	return NULL;
}

LinkListNode*	currentPosByLinkList(LinkList*	list_)
{
	return NULL;
}
