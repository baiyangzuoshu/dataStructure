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

void	selectSort(SqList* L)
{
	for (int i = 0; i < L->length - 1; i++)
	{
		int	min = i;

		for (int j=i+1;j<L->length;j++)
		{
			if (L->r[j]<L->r[min])
			{
				min = j;
			}
		}

		if (i != min)
		{
			swap(L, i, min);
		}
	}
}

int  main()
{
	SqList	_list;
	_list.length = MAXSIZE + 1;
	for (int i = 0; i < _list.length; i++)
	{
		_list.r[i] = rand() % 100;
	}
	printList(&_list);
	selectSort(&_list);
	printList(&_list);
	system("pause");
	return 0;
}