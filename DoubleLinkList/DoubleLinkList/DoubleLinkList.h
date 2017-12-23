#ifndef  DOUBLE_LINKLIST_H
#define	 DOUBLE_LINKLIST_H
typedef	struct _tag_DoubleLinkListNode
{
	struct _tag_DoubleLinkListNode*	next_;
	struct _tag_DoubleLinkListNode* last_;
}DoubleLinkListNode;

typedef	void DoubleLinkList;
DoubleLinkList*			createLinkList();
DoubleLinkListNode*		insertNodeToLinkList(DoubleLinkList* list_, DoubleLinkListNode*	node_, int pos_);
DoubleLinkListNode*		getNodeByLinkList(DoubleLinkList*	list_, int pos_);
DoubleLinkListNode*		deleteNodeByLinkListNode(DoubleLinkList*	list_, DoubleLinkListNode*	node_);
DoubleLinkListNode*		deleteNodeByLinkListPos(DoubleLinkList*	list_, int pos_);
int		getLengthLinkList(DoubleLinkList* list_);
int		clearLinkList(DoubleLinkList*	list_);
int		destoryLinkList(DoubleLinkList* list_);
#endif//DOUBLE_LINKLIST_H
