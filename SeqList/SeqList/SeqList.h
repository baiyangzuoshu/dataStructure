#ifndef MYSEQLIST_H
#define MYSEQLIST_H

typedef void	SeqList;
typedef void	SeqListNode;

SeqList*	createSeqList(int capacity);
int			destroySeqList(SeqList	*list);
int			getSeqListLength(SeqList	*list);
int			getSeqListCapacity(SeqList	*list);
SeqListNode*	insertToSeqList(SeqList	*list,SeqListNode	*node,int pos);
SeqListNode*    getNodeBySeqList(SeqList	*list,int pos);
SeqListNode*	deleteBySeqList(SeqList	*list,int pos);
#endif//MYSEQLIST_H