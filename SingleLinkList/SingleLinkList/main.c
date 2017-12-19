#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include"SingleLinkList.h"

typedef struct _Teacher
{
	SingleLinkListNode	node;
	int		age;
	char	name[32];
}Teacher;

int main()
{
	int ret_ = 0;
	int len_ = 0;
	SingleLinkListNode*	node_ = NULL;
	SingleLinkList*	list_ = createLinkList();

	Teacher *tArray[5];
	Teacher t1, t2, t3, t4, t5;
	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;
	tArray[3] = &t4;
	tArray[4] = &t5;
	printf("insert doing............................................\n");
	for (int i = 0; i < 5; i++)
	{
		tArray[i]->age = 100 + i;
		node_ = insertNodeByLinkList(list_, (SingleLinkListNode*)tArray[i], i);
		if (NULL!=node_)
		{
			Teacher*	teacher_ = (Teacher*)node_;
			printf("insert info age:%d\n", teacher_->age);
		}
	}

	printf("insert last...........................................................\n");
	len_=getLinkListLength(list_);

	for (int i=0;i<len_;i++)
	{
		node_ = getNodeByLinkListPos(list_, i);
		if (NULL != node_)
		{
			Teacher*	teacher_ = (Teacher*)node_;
			printf("insert info age:%d\n", teacher_->age);
		}
		else
		{
			printf("getNodeByLinkListPos fail\n");
		}
	}
	node_=deleteNodeByLinkListPos(list_, 3);
	if (NULL != node_)
	{
		Teacher*	teacher_ = (Teacher*)node_;
		printf("delete info age:%d\n", teacher_->age);
	}
	else
	{
		printf("deleteNodeByLinkListPos fail\n");
	}

	node_=deleteNodeByLinkListNode(list_, (SingleLinkListNode*)tArray[2]);
	if (NULL != node_)
	{
		Teacher*	teacher_ = (Teacher*)node_;
		printf("delete info age:%d\n", teacher_->age);
	}
	else
	{
		printf("deleteNodeByLinkListNode fail\n");
	}
	printf("delete last.................................................\n");
	len_ = getLinkListLength(list_);

	for (int i = 0; i < len_; i++)
	{
		node_ = getNodeByLinkListPos(list_, i);
		if (NULL != node_)
		{
			Teacher*	teacher_ = (Teacher*)node_;
			printf("insert info age:%d\n", teacher_->age);
		}
		else
		{
			printf("getNodeByLinkListPos fail\n");
		}
	}
	clearLinkList(list_);
	destoryLinkList(list_);

	system("pause");
	return 0;
}