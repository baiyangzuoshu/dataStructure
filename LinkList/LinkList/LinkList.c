#include "LinkList.h"
#include<stdio.h>

typedef struct _tagLinkList 
{
	int				len_;
	LinkListNode	*head;
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

		node_->last_ = tList->head;
		node_->next_ = NULL;
		
		tList->len_++;
		return node_;
	}
		
	LinkListNode* tCur = tList->head;//指向第一个节点
	//头插法
	if (0 == pos)
	{
		tList->head = node_;

		node_->last_ = tList->head;
		node_->next_ = tCur;
		
		tCur->last_ = node_;
		tList->len_++;
		return node_;
	}
	//
	for (int i = 0; i <= tList->len_;i++)
	{
		if (i == pos)
		{
			tCur->last_->next_ = node_;

			node_->last_ = tCur->last_;
			node_->next_ = tCur;

			tCur->last_ = node_;
			break;
		}
		
		
		if (NULL== tCur->next_)
		{
			//尾部插入
			tCur->next_ = node_;

			node_->last_ = tCur;
			node_->next_ = NULL;

			tCur->last_ = node_;
			break;
		}
		else
		{
			tCur = tCur->next_;//当前节点
		}
	}
	tList->len_++;
	return node_;
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
	if (pos>=tList->len_)
	{
		printf("deleteNodeByPos fail!\n");
		return -1;
	}

	for (int i = 0; i < tList->len_; i++)
	{
		if (i == pos)
		{
			cur_->next_->last_ = cur_->last_;
			cur_->last_->next_ = cur_->next_;
			tList->len_--;
			return cur_;
		}
		cur_ = cur_->next_;
		if (NULL == cur_->next_)
		{
			//尾部删除
			cur_->last_->next_ = NULL;
			tList->len_--;
			return cur_;
		}
		
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
		tList->len_--;
		return node_;
	}

	LinkListNode* cur_ = tList->head;
	while (cur_)
	{
		if (node_ == cur_)
		{
			cur_->next_->last_ = cur_->last_;
			cur_->last_->next_ = cur_->next_;
			tList->len_--;
			return node_;
		}

		cur_ = cur_->next_;//当前节点
		if (NULL==cur_->next_)
		{
			//尾部删除
			cur_->last_->next_ = NULL;
			tList->len_--;
			return cur_;
		}
	}
	return NULL;
}

