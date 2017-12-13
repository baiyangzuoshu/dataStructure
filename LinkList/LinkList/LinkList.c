#include "LinkList.h"
#include<stdio.h>

typedef struct _tagLinkList 
{
	int				len_;
	LinkListNode	*head;
	LinkListNode	*current;
}TLinkList;

LinkList*	createLinkList()
{
	TLinkList	*list_ = (TLinkList*)malloc(sizeof(TLinkList));
	memset(list_, 0, sizeof(TLinkList));
	return list_;
}

int			destoryLinkList(LinkList* list_)
{
	if (NULL==list_)
	{
		printf("destoryLinkList fail!");
		return -1;
	}

	free(list_);
	list_ = NULL;
	return 0;
}

int			getLinkListLength(LinkList*	list_)
{
	if (NULL == list_)
	{
		printf("getLinkListLength fail!");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	return tList->len_;
}

LinkListNode*	insertToLinkList(LinkList*	list_, LinkListNode*	node_, int pos)
{
	if (NULL == list_)
	{
		printf("insertToLinkList fail!");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	
	if (tList->current==tList->head)
	{
		//说明链表是空的
		tList->head = node_;
	}

	LinkListNode* tNext = tList->head;//指向第一个节点
	LinkListNode* current = tNext;
	for (int i = 1; i < tList->len_;i++)
	{
		
		tNext = tNext->node;
		if (i == pos)
		{
			tNext->node = node_;
			break;
		}
	}
	tList->current = node_;
	tList->len_++;
	return tList->current;
}

LinkListNode*	getNodeByLinkList(LinkList*	list_, int pos)
{
	if (NULL == list_)
	{
		printf("getNodeByLinkList fail!");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	return NULL;
}

LinkListNode*	deleteNodeByPos(LinkList*	list_, int pos)
{
	if (NULL == list_)
	{
		printf("deleteNodeByPos fail!");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	return NULL;
}

LinkListNode*	deleteNodeByNode(LinkList*	list_, LinkListNode*	node_)
{
	if (NULL == list_)
	{
		printf("deleteNodeByNode fail!");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	return NULL;
}

LinkListNode*	currentPosByLinkList(LinkList*	list_)
{
	if (NULL == list_)
	{
		printf("currentPosByLinkList fail!");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	return NULL;
}
