#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include "LinkList.h"

typedef	struct _tag_Teacher
{
	LinkListNode	node;//如果它是一指針,怎么分配内存？
	int		age;
	char	name[64];
}Teacher;

int main()
{
	int ret = 0;
	LinkList*	list_=createLinkList();
	Teacher *tArray[5];
	Teacher t1,t2,t3,t4,t5;
	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;
	tArray[3] = &t4;
	tArray[4] = &t5;
	for (int i = 0; i < 5; i++)
	{
		
		memset(tArray[i], 0, sizeof(Teacher));
		tArray[i]->age = 100 + i;
		printf("&t:%d,&node:%d", tArray[i], &(tArray[i]->node));
		LinkListNode*	node_ = insertToLinkList(list_, (LinkListNode*)(tArray[i]), i);
		if (NULL == node_)
		{
			printf("insertToLinkList fail\n");
		}
		else
		{
			Teacher*	object_ = (Teacher*)node_;
			printf("insertToLinkList Teacher:age %d\n", object_->age);
		}
	}
	
	int	listLen = getLinkListLength(list_);
	printf("list len:%d\n", listLen);
	for (int i=0;i<getLinkListLength(list_);i++)
	{
		LinkListNode*	node_ = getNodeByLinkList(list_, i);
		if (NULL == node_)
		{
			printf("getNodeByLinkList fail\n");
		}
		else
		{
			Teacher*	object_ = (Teacher*)node_;
			printf("getNodeByLinkList Teacher:age %d\n", object_->age);
		}
	}
	

	LinkListNode*	node_=deleteNodeByPos(list_, 4);
	if (NULL == node_)
	{
		printf("deleteNodeByPos fail\n");
	}
	else
	{
		Teacher*	object_ = (Teacher*)node_;
		printf("deleteNodeByPos Teacher:age %d\n", object_->age);
	}

	node_ = deleteNodeByNode(list_, (LinkListNode*)tArray[1]);
	for (int i = 0; i < getLinkListLength(list_); i++)
	{
		LinkListNode*	node_ = getNodeByLinkList(list_, i);
		if (NULL == node_)
		{
			printf("getNodeByLinkList fail\n");
		}
		else
		{
			Teacher*	object_ = (Teacher*)node_;
			printf("getNodeByLinkList Teacher:age %d\n", object_->age);
		}
	}

	ret = destoryLinkList(list_);
	if (ret!=0)
	{
		printf("destoryLinkList fail\n");
	}
	printf("hellowrold\n");
	system("pause");
	return 0;
}