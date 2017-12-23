#include "DoubleLinkList.h"
#include <stdlib.h>
#include <stdio.h>
typedef		struct _tag_DoubleLinkList 
{
	DoubleLinkListNode	head_;
	int	length;
}TDoubleLinkList;

DoubleLinkList*			createLinkList()
{
	TDoubleLinkList*	list_ = (TDoubleLinkList*)malloc(sizeof(TDoubleLinkList));
	if (NULL == list_)
	{
		print("createLinkList:fail NULL == list_\n");
		return NULL;
	}
	memset(list_, 0, sizeof(TDoubleLinkList));

	list_->length = 0;
	list_->head_.last_ = NULL;
	list_->head_.next_ = NULL;
	return list_;
}

DoubleLinkListNode*		insertNodeToLinkList(DoubleLinkList* list_, DoubleLinkListNode*	node_, int pos_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL==list_||NULL==node_||pos_<0||pos_>tList->length)
	{
		print("insertNodeToLinkList fail:NULL==list_||NULL==node_||pos_<0||pos_>tList->length\n");
		return NULL;
	}
	
	DoubleLinkListNode*	current = &(tList->head_);
	for (int i = 0; i < pos_&&current->next_; i++)
	{
		current = current->next_;
	}

	DoubleLinkListNode*	last_ = current;

	current->last_ = node_;
	node_->last_ = last_->last_;
	node_->next_ = last_;
	return NULL;
}

DoubleLinkListNode*		getNodeByLinkList(DoubleLinkList*	list_, int pos_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL == list_ || pos_<0 || pos_>=tList->length)
	{
		print("insertNodeToLinkList fail:NULL == list_ || pos_<0 || pos_>=tList->length\n");
		return NULL;
	}

	DoubleLinkListNode*	current = &(tList->head_);
	for (int i = 0; i < pos_&&current->next_; i++)
	{
		current = current->next_;
	}
	return current->next_;
}

DoubleLinkListNode*		deleteNodeByLinkListNode(DoubleLinkList*	list_, DoubleLinkListNode*	node_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL == list_ || NULL== node_)
	{
		print("insertNodeToLinkList fail:NULL == list_ || NULL== node_\n");
		return NULL;
	}

	DoubleLinkListNode*	current = &(tList->head_);
	while (current->next_)
	{
		if (current->next_ ==node_)
		{
			current->next_ = current->next_->next_;

			current->next_->next_->last_ = current;
			return	node_;
		}
	}
	return NULL;
}

DoubleLinkListNode*		deleteNodeByLinkListPos(DoubleLinkList*	list_, int pos_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL == list_ || pos_ < 0 || pos_ >= tList->length)
	{
		print("insertNodeToLinkList fail:NULL == list_ || pos_<0 || pos_>=tList->length\n");
		return NULL;
	}

	DoubleLinkListNode*	current = &(tList->head_);
	for (int i = 0; i < pos_&&current->next_; i++)
	{
		current = current->next_;
	}
	current->next_ = current->next_->next_;

	current->next_->next_->last_ = current;
	return NULL;
}

int		getLengthLinkList(DoubleLinkList* list_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL == list_)
	{
		print("getLengthLinkList:fail NULL == list_\n");
		return -1;
	}
	return tList->length;
}
int		clearLinkList(DoubleLinkList*	list_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL == list_)
	{
		print("clearLinkList:fail NULL == list_\n");
		return -1;
	}
	tList->length = 0;
	tList->head_.last_ = NULL;
	tList->head_.next_ = NULL;
	return 0;
}


int		destoryLinkList(DoubleLinkList* list_)
{
	TDoubleLinkList*	tList = (TDoubleLinkList*)list_;
	if (NULL == list_)
	{
		print("destoryLinkList:fail NULL == list_\n");
		return -1;
	}
	free(tList);
	tList = NULL;
	return 0;
}
