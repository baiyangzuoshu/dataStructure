#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include "LinkList.h"
typedef	struct _tag_Teacher
{
	LinkListNode	node;
	int		age;
	char	name[64];
}Teacher;

int main()
{
	int ret = 0;
	LinkList*	list_=createLinkList();
	
	int	listLen=getLinkListLength(list_);
	printf("list len:%d", listLen);
	for (int i = 0; i < 5; i++)
	{
		Teacher t;
		t.age = 100 + i;

		LinkListNode*	node_ = insertToLinkList(list_, (LinkListNode*)(&t), 0);
		if (NULL == node_)
		{
			printf("insertToLinkList fail\n");
		}
		else
		{
			Teacher*	object_ = (Teacher*)node_;
			printf("insertToLinkList Teacher:age %d", object_->age);
		}
	}
	
	LinkListNode*	node_=getNodeByLinkList(list_, 0);
	if (NULL == node_)
	{
		printf("getNodeByLinkList fail\n");
	}
	else
	{
		Teacher*	object_ = (Teacher*)node_;
		printf("getNodeByLinkList Teacher:age %d", object_->age);
	}

	node_=deleteNodeByPos(list_, 0);
	if (NULL == node_)
	{
		printf("deleteNodeByPos fail\n");
	}
	else
	{
		Teacher*	object_ = (Teacher*)node_;
		printf("deleteNodeByPos Teacher:age %d", object_->age);
	}
	
	node_=currentPosByLinkList(list_);
	if (NULL == node_)
	{
		printf("deleteNodeByPos fail\n");
	}
	else
	{
		Teacher*	object_ = (Teacher*)node_;
		printf("deleteNodeByPos Teacher:age %d", object_->age);
	}

	ret = destoryLinkList(list_);
	if (ret==0)
	{
		printf("destoryLinkList fail\n");
	}
	printf("hellowrold\n");
	system("pause");
	return 0;
}