#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include"string.h"
typedef struct _Teacher
{
	int		age;
	char	name[32];
}Teacher;

int main()
{
	int ret = 0;
	Teacher t1, t2, t3, t4, t5, t6;
	t1.age = 10;
	t2.age = 340;
	t3.age = 50;
	t4.age = 70;
	t5.age = 80;
	t6.age = 110;
	SeqList*	list=createSeqList(10);

	ret = getSeqListCapacity(list);
	if (ret < 1)
	{
		printf("list Capacity < 1");
		return;
	}
	Teacher*	node=(Teacher*)insertToSeqList(list, (SeqListNode*)&t1, 0);
	if (NULL==node)
	{
		printf("insert fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	node = (Teacher*)insertToSeqList(list, (SeqListNode*)&t2, 2);
	if (NULL == node)
	{
		printf("insert fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	node = (Teacher*)insertToSeqList(list, (SeqListNode*)&t3, 8);
	if (NULL == node)
	{
		printf("insert fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	node = (Teacher*)insertToSeqList(list, (SeqListNode*)&t4, 0);
	if (NULL == node)
	{
		printf("insert fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	node = (Teacher*)insertToSeqList(list, (SeqListNode*)&t5, 0);
	if (NULL == node)
	{
		printf("insert fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	node = (Teacher*)insertToSeqList(list, (SeqListNode*)&t6, 0);
	if (NULL == node)
	{
		printf("insert fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	node=(Teacher*)getNodeBySeqList(list, 2);
	if (NULL == node)
	{
		printf("getNodeBySeqList fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	//node = (Teacher*)deleteBySeqList(list,  1);
	if (NULL == node)
	{
		printf("getNodeBySeqList fail\n");
	}
	else
	{
		printf("node->age:%d\n", node->age);
	}

	ret = getSeqListLength(list);
	if (ret < 1)
	{
		printf("list length < 1\n");
		return;
	}

	for (int i=0;i<ret;i++)
	{
		node = (Teacher*)getNodeBySeqList(list, i);
		if (NULL == node)
		{
			printf("getNodeBySeqList fail\n");
		}
		else
		{
			printf("node->age:%d\n",node->age);
		}
	}
	ret= destroySeqList(list);
	if (ret!=0)
	{
		printf("destorySeqList fail!\n");
	}
	system("pause");
	return 0;
}