#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
typedef struct _tag_Linklist_node
{
	struct _tag_Linklist_node*	next_;
}LinkListNode;

typedef	void	LinkList;

LinkList*	createLinkList();
int			destoryLinkList(LinkList* list_);
int			getLinkListLength(LinkList*	list_);
LinkListNode*	insertToLinkList(LinkList*	list_, LinkListNode*	node_, int pos);
LinkListNode*	getNodeByLinkList(LinkList*	list_, int pos);
LinkListNode*	deleteNodeByPos(LinkList*	list_, int pos);
LinkListNode*	deleteNodeByNode(LinkList*	list_, LinkListNode*	node_);
#endif//LINKLIST_H
