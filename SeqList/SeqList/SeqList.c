#include "SeqList.h"
#include"string.h"

typedef struct _tag_seqlist
{
	int length;
	int capacity;
	unsigned int	*node;
}TSeqList;

SeqList*	createSeqList(int capacity)
{
	if (capacity<1)
	{
		printf("createSeqList fail capacity<1");
		return NULL;
	}

	TSeqList* list = (TSeqList*)malloc(sizeof(TSeqList));
	if (NULL==list)
	{
		list = (TSeqList*)malloc(sizeof(TSeqList));
	}
	memset(list, 0, sizeof(TSeqList));

	list->capacity = capacity;
	list->length = 0;
	list->node = (unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	memset(list->node, 0, sizeof(unsigned int)*capacity);

	return list;
}

int			destroySeqList(SeqList	*list)
{
	TSeqList* tList = (TSeqList*)list;

	if (NULL== tList)
	{
		printf("destroySeqlist fail");
		return -1;
	}

	if (NULL!= tList->node)
	{
		free(tList->node);
		tList->node = NULL;
	}
	free(tList);
	tList = NULL;
	return 0;
}

int			getSeqListLength(SeqList	*list)
{
	TSeqList* tList = (TSeqList*)list;

	if (NULL == tList)
	{
		printf("destroySeqlist fail");
		return -1;
	}
	return tList->length;
}

int			getSeqListCapacity(SeqList	*list)
{
	TSeqList* tList = (TSeqList*)list;

	if (NULL == tList)
	{
		printf("destroySeqlist fail");
		return -1;
	}
	return tList->capacity;
}

SeqListNode*	insertToSeqList(SeqList	*list, SeqListNode	*node, int pos)
{
	TSeqList* tList = (TSeqList*)list;

	if (NULL == tList||pos>tList->capacity)
	{
		printf("insertToSeqList fail");
		return NULL;
	}
	//ÈÝ´í´¦Àí
	if (pos > tList->length)
		pos = tList->length;
	else if (pos < 1)
		pos = 0;

	//a[i+1]=a[i]
	for (int i= tList->length;i>pos;i--)
	{
		tList->node[i] = tList->node[i-1];
	}
	tList->node[pos] = (unsigned int*)node;
	tList->length++;
	return (SeqListNode	*)tList->node[pos];
}

SeqListNode*    getNodeBySeqList(SeqList	*list, int pos)
{
	TSeqList* tList = (TSeqList*)list;

	if (NULL == tList||tList->length<pos)
	{
		printf("getNodeBySeqList fail");
		return NULL;
	}
	SeqListNode* node = (SeqListNode*)tList->node[pos];
	return node;
}

SeqListNode*	deleteBySeqList(SeqList	*list,  int pos)
{
	TSeqList* tList = (TSeqList*)list;

	if (NULL == tList||pos>tList->length)
	{
		printf("deleteBySeqList fail");
		return NULL;
	}
	SeqListNode* tmp = (SeqListNode*)tList->node[pos];
	//a[i]=a[i+1]
	for (int i=pos;i<tList->length;i++)
	{
		tList->node[i] = tList->node[i+1];
	}
	tList->length--;
	return tmp;
}