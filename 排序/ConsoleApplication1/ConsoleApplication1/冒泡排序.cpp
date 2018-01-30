#include<iostream>
using namespace std;
#define		MAXSIZE 10
static	int	_count = 0;
typedef  struct
{
	int  r[MAXSIZE + 1];
	int  length;
}SqList;

void	swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void	printList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		cout << L->r[i] << " ";
	}
	cout << endl;
}

void	BubbleSort0(SqList* L)
{
	_count = 0;
	for (int i = 0; i < L->length; i++)
	{
		_count++;
		for (int j = i + 1; j <= L->length; j++)
		{
			_count++;
			if (L->r[i] < L->r[j])
			{
				swap(L, i, j);
			}
		}
	}
}

void	BubbleSort(SqList* L)
{
	_count = 0;
	for (int i = 0; i < L->length; i++)
	{
		_count++;
		for (int j = L->length - 1; j >= i; j--)//�����ŷ�������뽻���������ʡȥ�Ƚ϶�Ľ���ʱ��
		{
			_count++;
			if (L->r[j] > L->r[j+1])
			{
				swap(L, j, j+1);
			}
		}
	}
}

void	BubbleSort2(SqList* L)
{
	bool	isFlag = true;
	for (int i = 0; i < L->length - 1&&isFlag; i++)
	{
		isFlag = false;
		_count++;
		for (int j = L->length - 1; j >= i; j--)
		{
			_count++;
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				isFlag = true;
			}
		}
	}
}

int  main02()
{
	SqList	_list;
	_list.length = MAXSIZE;
	for (int i = 0; i < _list.length + 1; i++)
	{
		_list.r[i] = rand() % 100;
	}
	printList(&_list);
	BubbleSort2(&_list);
	printList(&_list);
	cout << "count:" << _count << endl;
	system("pause");
	return 0;
}
/*
��������������ȣ����н���
ð������ÿѭ��һ�ˣ���ֵ���ڵ�iλ
�Ż�ð��������ð������Ļ����ϼ����жϣ�һ���ڶ���ѭ��û�н�����˵��������ɡ�
*/