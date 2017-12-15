#include"SingleLinkList.h"
#include "stdio.h"

typedef	struct _SingleLinkList
{
	int length;
	SingleLinkListNode	*head;
}TSingleLinkList;

SingleLinkList*	createLinkList()
{
	TSingleLinkList	*list_ = (TSingleLinkList*)malloc(sizeof(TSingleLinkList));
	memset(list_, 0, sizeof(TSingleLinkList));

	list_->length = 0;
	list_->head->next = NULL;
	return list_;
}

int				destoryLinkList(SingleLinkList* list_)
{
	assert(NULL == list_, "destoryLinkList fail:list_!=NULL\n");

	return 0;
}

int				getLinkListLength(SingleLinkList* list_)
{
	return 0;
}

int				clearLinkList(SingleLinkList* list_)
{
	return 0;
}

SingleLinkListNode* deleteNodeByLinkListPos(SingleLinkList* list_, int pos)
{
	return NULL;
}

SingleLinkListNode* insertNodeByLinkList(SingleLinkList* list_, SingleLinkListNode* node_, int pos)
{
	return NULL;
}

SingleLinkListNode* deleteNodeByLinkListNode(SingleLinkList* list_, SingleLinkListNode* node_)
{
	return NULL;
}
