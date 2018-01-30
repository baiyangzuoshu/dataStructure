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

void	insertSort(SqList* L)
{
	for (int i = 1; i < L->length; i++)
	{
		_count++;
		int  k = i;
		int  temp = L->r[k];

		for (int j = i - 1; j >= 0 && (L->r[j] > temp); j--)
		{
			_count++;

			L->r[j + 1] = L->r[j];
			k = j;
		}

		L->r[k] = temp;
	}
}

int  main()
{
	SqList	_list;
	_list.length = MAXSIZE + 1;
	for (int i = 0; i < _list.length; i++)
	{
		_list.r[i] = rand() % 10000;
	}
	printList(&_list);
	insertSort(&_list);
	printList(&_list);
	cout << "count:" << _count << endl;
	system("pause");
	return 0;
}