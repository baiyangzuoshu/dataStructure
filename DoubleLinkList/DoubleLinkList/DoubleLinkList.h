#pragma once
#ifdef  DOUBLE_LINKLIST_H
#define DOUBLE_LINKLIST_H
typedef	struct _tag_DoubleLinkListNode 
{
	struct _tag_DoubleLinkListNode*	next_;
	struct _tag_DoubleLinkListNode* last_;
}DoubleLinkListNode;

typedef	void DoubleLinkList;

#endif//DOUBLE_LINKLIST_H
