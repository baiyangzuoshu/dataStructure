#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include "CircleLinkList.h"

typedef		struct _Teacher 
{
	CircleLinkListNode node_;
	int		age;
	char	name[32];
}Teacher;

int main()
{
	int ret_ = 0;
	int len_ = 0;
	CircleLinkListNode* node_ = NULL;
	Teacher* tArray[6];
	Teacher t0,t1, t2, t3, t4, t5;
	tArray[0] = &t0;
	tArray[1] = &t1;
	tArray[2] = &t2;
	tArray[3] = &t3;
	tArray[4] = &t4;
	tArray[5] = &t5;
	for (int i = 0; i < 6; i++)
	{
		tArray[i]->age = 100 + i;
	}
	
	CircleLinkList*		list_=createCircleLink();
	if (NULL==list_)
	{
		printf("createCircleLink fail!\n");
	}
	
	for (int i = 0; i < 6; i++)
	{
		node_ = insertNodeByCircleLink(list_, (CircleLinkListNode*)tArray[i], 0);
		if (NULL == node_)
		{
			printf("insertNodeByCircleLink fail\n");
		}
		else
		{
			Teacher*	t_ = (Teacher*)node_;
			printf("insertNodeByCircleLink success age:%d\n", t_->age);
		}
	}
	printf("insert alter...................................\n");
	len_ = getLengthByCircleLink(list_);
	if (len_ < 0)
	{
		printf("getLengthByCircleLink fail!\n");
		return -1;
	}

	for (int i = 0; i < 3*len_; i++)
	{
		node_ = getNodeByCircleLinkPos(list_, i);
		if (NULL == node_)
		{
			printf("getNodeByCircleLinkPos fail\n");
		}
		else
		{
			Teacher*	t_ = (Teacher*)node_;
			printf("getNodeByCircleLinkPos success age:%d\n", t_->age);
		}
	}

	node_ = deleteNodeByCircleLinkPos(list_, 2);
	if (NULL == node_)
	{
		printf("deleteNodeByCircleLinkPos fail\n");
	}
	else
	{
		Teacher*	t_ = (Teacher*)node_;
		printf("deleteNodeByCircleLinkPos success age:%d\n", t_->age);
	}
	
	node_ = deleteNodeByCircleLinkNode(list_, (CircleLinkListNode*)tArray[5]);
	if (NULL == node_)
	{
		printf("deleteNodeByCircleLinkNode fail\n");
	}
	else
	{
		Teacher*	t_ = (Teacher*)node_;
		printf("deleteNodeByCircleLinkNode success age:%d\n", t_->age);
	}
	printf("delete after........................\n");
	len_ = getLengthByCircleLink(list_);
	if (len_ < 0)
	{
		printf("getLengthByCircleLink fail!\n");
		return -1;
	}
	else
	{
		printf("getLengthByCircleLink success len:%d\n", len_);
	}
	for (int i = 0; i < 3*len_; i++)
	{
		node_ = getNodeByCircleLinkPos(list_, i);
		if (NULL == node_)
		{
			printf("getNodeByCircleLinkPos fail\n");
		}
		else
		{
			Teacher*	t_ = (Teacher*)node_;
			printf("getNodeByCircleLinkPos success age:%d\n", t_->age);
		}
	}

	ret_ = clearCircleLink(list_);
	if (0 != ret_)
	{
		printf("clearCircleLink fail!\n");
		return -1;
	}

	ret_ = destoryCircleLink(list_);
	if (0 != ret_)
	{
		printf("destoryCircleLink fail!\n");
		return -1;
	}
	
	system("pause");
	return 0;
}