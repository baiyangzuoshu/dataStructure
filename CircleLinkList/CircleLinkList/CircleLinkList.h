#pragma once
typedef struct _tag_CircleLinkListNode
{
	struct _tag_CircleLinkListNode	*next;
}CircleLinkListNode;

typedef	void CircleLinkList;

CircleLinkList*		createCircleLink();
int					destoryCircleLink(CircleLinkList* list_);
int					clearCircleLink(CircleLinkList*	list_);
int					getLengthByCircleLink(CircleLinkList*	list_);
CircleLinkListNode*		insertNodeByCircleLink(CircleLinkList*	list_, CircleLinkListNode*	node_, int pos_);
CircleLinkListNode*		getNodeByCircleLinkPos(CircleLinkList*	list_, int pos_);
CircleLinkListNode*		deleteNodeByCircleLinkPos(CircleLinkList*	list_, int pos_);
CircleLinkListNode*		deleteNodeByCircleLinkNode(CircleLinkList*	list_, CircleLinkListNode*	node_);