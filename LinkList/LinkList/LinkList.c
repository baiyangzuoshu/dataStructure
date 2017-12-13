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
		printf("destoryLinkList fail!\n");
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
		printf("getLinkListLength fail!\n");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	return tList->len_;
}

LinkListNode*	insertToLinkList(LinkList*	list_, LinkListNode*	node_, int pos)
{
	if (NULL == list_|| NULL==node_)
	{
		printf("insertToLinkList fail!\n");
		return NULL;
	}

	
	TLinkList* tList = (TLinkList*)list_;
	//容错处理
	if (pos > tList->len_)
	{
		pos = tList->len_;
	}

	if (tList->len_==0)
	{
		//说明链表是空的
		tList->head = node_;
		tList->current = node_;
		tList->len_++;
		return tList->current;
	}
		
	LinkListNode* tLast = NULL;
	LinkListNode* tCur = tList->head;//指向第一个节点

	//头插法
	if (0 == pos)
	{
		tList->head = node_;
		node_->next_ = tCur;
		tList->current = node_;
		tList->len_++;
		return tList->current;
	}
	//
	for (int i = 0; i <= tList->len_;i++)
	{
		if (i == pos)
		{
			tLast->next_ = node_;
			node_->next_ = tCur;
			break;
		}
		tLast = tCur;//上一个节点
		tCur = tCur->next_;//当前节点
	}
	tList->current = node_;
	tList->len_++;
	return tList->current;
}

LinkListNode*	getNodeByLinkList(LinkList*	list_, int pos)
{
	if (NULL == list_)
	{
		printf("getNodeByLinkList fail!\n");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	if (0==pos)
	{
		return tList->head;
	}

	LinkListNode* node_ = tList->head;
	for (int i=0;i<tList->len_;i++)
	{
		if (i == pos)
			return node_;

		node_ = node_->next_;
	}
	return NULL;
}

LinkListNode*	deleteNodeByPos(LinkList*	list_, int pos)
{
	if (NULL == list_)
	{
		printf("deleteNodeByPos fail!\n");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	LinkListNode* cur_ = tList->head;
	LinkListNode* last_ = tList->head;
	for (int i = 0; i < tList->len_; i++)
	{
		if (i == pos)
		{
			last_->next_ = cur_->next_;
			tList->len_--;
			return cur_;
		}
		last_ = cur_;
		cur_ = cur_->next_;
	}
	return NULL;
}

LinkListNode*	deleteNodeByNode(LinkList*	list_, LinkListNode*	node_)
{
	if (NULL == list_||node_==NULL)
	{
		printf("deleteNodeByNode fail!\n");
		return -1;
	}
	TLinkList* tList = (TLinkList*)list_;
	if (tList->head==node_)
	{
		tList->head = tList->head->next_;
		return node_;
	}

	LinkListNode* cur_ = tList->head;
	LinkListNode* last_ = tList->head;
	while (cur_)
	{
		if (node_ == cur_)
		{
			last_->next_ = cur_->next_;
			tList->len_--;
			return node_;
		}
		last_ = cur_;
		cur_ = cur_->next_;
	}
	return NULL;
}

