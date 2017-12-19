#include"SingleLinkList.h"
#include "stdio.h"
#include <assert.h>

typedef	struct _SingleLinkList
{
	int length;
	SingleLinkListNode	head;
}TSingleLinkList;

SingleLinkList*	createLinkList()
{
	TSingleLinkList	*list_ = (TSingleLinkList*)malloc(sizeof(TSingleLinkList));
	memset(list_, 0, sizeof(TSingleLinkList));

	list_->length = 0;
	list_->head.next = NULL;
	return list_;
}

int				destoryLinkList(SingleLinkList* list_)
{
	if (NULL==list_)
	{
		printf("destoryLinkList fail:list_!=NULL");
		return -1;
	}

	free(list_);
	list_ = NULL;
	return 0;
}

int				getLinkListLength(SingleLinkList* list_)
{
	if (NULL == list_)
	{
		printf("getLinkListLength fail:list_!=NULL");
		return -1;
	}
	TSingleLinkList	*tList = (TSingleLinkList*)list_;
	return tList->length;
}

int				clearLinkList(SingleLinkList* list_)
{
	if (NULL == list_)
	{
		printf("clearLinkList fail:list_!=NULL");
		return -1;
	}
	TSingleLinkList	*tList = (TSingleLinkList*)list_;
	tList->head.next = NULL;
	tList->length = 0;
	return 0;
}

SingleLinkListNode* deleteNodeByLinkListPos(SingleLinkList* list_, int pos)
{
	TSingleLinkList	*tList = (TSingleLinkList*)list_;
	if (NULL == tList||pos>=tList->length||pos<0)
	{
		printf("deleteNodeByLinkListPos fail:list_!=NULL");
		return -1;
	}
	
	SingleLinkListNode	*current_ = NULL;
	current_ = &(tList->head);
	for (int i=0;i<pos&&current_->next;i++)
	{
		current_ = current_->next;
	}
	tList->length--;
	SingleLinkListNode	*delete_ = current_->next;
	current_->next = delete_->next;
	return delete_;
}

SingleLinkListNode* insertNodeByLinkList(SingleLinkList* list_, SingleLinkListNode* node_, int pos)
{
	if (NULL == list_||NULL==node_)
	{
		printf("insertNodeByLinkList fail:list_!=NULL");
		return NULL;
	}
	SingleLinkListNode	*current = NULL;
	TSingleLinkList		*tList = (TSingleLinkList*)list_;
	if (pos<0||pos>=tList->length)
		pos = 0;

	current = &(tList->head);

	for (int i=0;i<pos&&current->next;i++)
	{
		current = current->next;
	}

	node_->next = current->next;
	current->next = node_;
	tList->length++;
	return node_;
}

SingleLinkListNode* getNodeByLinkListPos(SingleLinkList* list_, int pos)
{
	TSingleLinkList		*tList = (TSingleLinkList*)list_;
	if (NULL == tList||pos>=tList->length)
	{
		printf("getNodeByLinkListPos fail:list_!=NULL");
		return -1;
	}
	
	SingleLinkListNode	*current = NULL;
	current = &(tList->head);
	for (int i=0;i<=pos&&current->next;i++)
	{
		current = current->next;
	}
	return current;
}

SingleLinkListNode* deleteNodeByLinkListNode(SingleLinkList* list_, SingleLinkListNode* node_)
{
	if (NULL == list_||NULL==node_)
	{
		printf("deleteNodeByLinkListNode fail:list_!=NULL");
		return -1;
	}
	TSingleLinkList	*tList = (TSingleLinkList*)list_;
	SingleLinkListNode* current_ = NULL;
	SingleLinkListNode* last_ = NULL;
	current_ = &(tList->head);

	while (current_)
	{
		if (current_ ==node_)
		{
			last_->next= current_->next;
			tList->length--;
			return node_;
		}
		last_ = current_;
		current_ = current_->next;
	}
	return NULL;
}
