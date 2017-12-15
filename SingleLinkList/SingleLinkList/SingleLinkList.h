#pragma once
typedef struct _tag_SingleLinkList
{
	struct _tag_SingleLinkList* next;
}SingleLinkListNode;

typedef  void	SingleLinkList;

SingleLinkList*	createLinkList();
int				destoryLinkList(SingleLinkList* list_);
int				getLinkListLength(SingleLinkList* list_);
int				clearLinkList(SingleLinkList* list_);
SingleLinkListNode* getNodeByLinkListPos(SingleLinkList* list_, int pos);
SingleLinkListNode* deleteNodeByLinkListPos(SingleLinkList* list_, int pos);
SingleLinkListNode* insertNodeByLinkList(SingleLinkList* list_, SingleLinkListNode* node_, int pos);
SingleLinkListNode* deleteNodeByLinkListNode(SingleLinkList* list_, SingleLinkListNode* node_);
