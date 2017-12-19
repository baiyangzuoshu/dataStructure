#include"CircleLinkList.h"
#include <stdio.h>

typedef		struct _CircleLinkList
{
	CircleLinkListNode	head_;
	int length_;
}TCircleLinkList;

CircleLinkList*		createCircleLink()
{
	TCircleLinkList* list_ = (TCircleLinkList*)malloc(sizeof(TCircleLinkList));
	memset(list_, 0, sizeof(TCircleLinkList));

	list_->head_.next = NULL;
	list_->length_ = 0;
	return list_;
}

int					destoryCircleLink(CircleLinkList* list_)
{
	if (NULL==list_)
	{
		printf("destoryCircleLink fail:NULL!=list_\n");
		return -1;
	}
	free(list_);
	list_ = NULL;
	return 0;
}

int					clearCircleLink(CircleLinkList*	list_)
{
	if (NULL == list_)
	{
		printf("clearCircleLink fail:NULL!=list_\n");
		return -1;
	}
	TCircleLinkList*	tList = (TCircleLinkList*)list_;
	tList->head_.next = NULL;
	tList->length_ = 0;
	return 0;
}

int					getLengthByCircleLink(CircleLinkList*	list_)
{
	if (NULL == list_)
	{
		printf("getLengthByCircleLink fail:NULL!=list_\n");
		return -1;
	}
	TCircleLinkList*	tList = (TCircleLinkList*)list_;
	return tList->length_;
}

CircleLinkListNode*		insertNodeByCircleLink(CircleLinkList*	list_, CircleLinkListNode*	node_, int pos_)
{
	if (NULL == list_|| NULL==node_|| pos_<0)
	{
		printf("getLengthByCircleLink fail:NULL!=list_\n");
		return -1;
	}
	TCircleLinkList*	tList = (TCircleLinkList*)list_;
	
	CircleLinkListNode* current_ = NULL;
	current_ = &tList->head_;
	for (int i=0;i<pos_&&current_->next;i++)
	{
		current_ = current_->next;
	}

	node_->next = current_->next;
	current_->next = node_;
	tList->length_++;
	//ͷ�巨
	if (list_ == current_)
	{
		CircleLinkListNode*	last_=getNodeByCircleLinkPos(list_, tList->length_-1);
		last_->next = current_->next;
	}
	return node_;
}

CircleLinkListNode*		getNodeByCircleLinkPos(CircleLinkList*	list_, int pos_)
{
	TCircleLinkList*	tList = (TCircleLinkList*)list_;
	if (NULL == tList || pos_<0)
	{
		printf("getLengthByCircleLink fail:NULL!=list_\n");
		return -1;
	}
	CircleLinkListNode* current_ = NULL;
	current_ = &tList->head_;
	for (int i = 0; i < pos_&&current_; i++)
	{
		current_ = current_->next;
	}
	return current_->next;
}

CircleLinkListNode*		deleteNodeByCircleLinkPos(CircleLinkList*	list_, int pos_)
{
	TCircleLinkList*	tList = (TCircleLinkList*)list_;
	if (NULL == list_ || pos_<0)
	{
		printf("deleteNodeByCircleLinkPos fail:NULL!=list_\n");
		return -1;
	}
	
	CircleLinkListNode* current_ = NULL;
	CircleLinkListNode* next_ = NULL;
	current_ = &tList->head_;
	for (int i = 0; i < pos_&&current_; i++)
	{
		current_ = current_->next;
	}
	next_ = current_->next;
	tList->length_--;
	current_->next = next_->next;
	if (list_ == current_)
	{
		CircleLinkListNode*	last_ = getNodeByCircleLinkPos(list_, tList->length_ - 1);
		last_->next = current_->next;
	}
	return next_;
}

CircleLinkListNode*		deleteNodeByCircleLinkNode(CircleLinkList*	list_, CircleLinkListNode*	node_)
{
	TCircleLinkList*	tList = (TCircleLinkList*)list_;
	if (NULL == list_ || NULL==node_)
	{
		printf("deleteNodeByCircleLinkNode fail:NULL!=list_\n");
		return -1;
	}

	CircleLinkListNode* current_ = NULL;
	CircleLinkListNode* next_ = NULL;
	current_ = &tList->head_;
	while (current_)
	{
		if (current_->next==node_)
		{
			next_ = current_->next;
			tList->length_--;
			current_->next = next_->next;
			if (list_ == current_)
			{
				CircleLinkListNode*	last_ = getNodeByCircleLinkPos(list_, tList->length_ - 1);
				last_->next = current_->next;
			}
			break;
		}
		current_ = current_->next;
	}
	
	return next_;
}
