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
		int	k = i;
		int _temp = L->r[k];

		for (int j = i - 1; j >= 0 && (L->r[j] > _temp); j--)
		{
			_count++;
			L->r[j + 1] = L->r[j];
			k = j;
		}

		L->r[k] = _temp;
	}
}
//跨区域的交换数据，直接插入排序的升级
void	shellSort(SqList* L)
{
	int		gap = L->length;
	do 
	{
		gap = gap / 3 + 1;

		for (int i = gap; i < L->length; i += gap)
		{
			_count++;
			int  k = i;
			int  _temp = L->r[k];
			//关键点在于退出循环的判断条件
			for (int j = i - gap; j >= 0 && (L->r[j] > _temp); j -= gap)
			{
				_count++;
				L->r[j + gap] = L->r[j];
				k = j;
			}
			L->r[k] = _temp;
		}
	} while (gap>1);
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
	shellSort(&_list);
	printList(&_list);
	cout<<"count:"<< _count<<endl;
	system("pause");
	return 0;
}