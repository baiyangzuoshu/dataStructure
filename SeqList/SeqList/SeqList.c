#include "SeqList.h"
#include<stdlib.h>

typedef struct _tag_seqlist
{
	int length;
	int capacity;
	unsigned int	*node;
}TSeqList;

SeqList*	createSeqList(int capacity)
{
	return NULL;
}

int			destroySeqList(SeqList	*list)
{
	return 0;
}

int			getSeqListLength(SeqList	*list)
{
	return 0;
}

int			getSeqListCapacity(SeqList	*list)
{
	return 0;
}

SeqListNode*	insertToSeqList(SeqList	*list, SeqListNode	*node, int pos)
{
	return NULL;
}

SeqListNode*    getNodeBySeqList(SeqList	*list, int pos)
{
	return NULL;
}

SeqListNode*	deleteBySeqList(SeqList	*list, SeqListNode	*node, int pos)
{
	return NULL;
}