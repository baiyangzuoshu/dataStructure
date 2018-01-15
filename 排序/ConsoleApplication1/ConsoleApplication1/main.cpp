#include<iostream>
using namespace std;

void	printArray(int*	_array, int _len)
{
	for (int i = 0; i < _len; i++)
	{
		cout << "  " << _array[i];
	}
	cout << endl;
}
//选择法
void	sortSelect(int*	_array,int _len)
{
	for (int i = 0; i < _len; i++)
	{
		for (int j = i + 1; j < _len; j++)
		{
			if (_array[i]>_array[j])
			{
				int	_temp = _array[i];
				_array[i] = _array[j];
				_array[j] = _temp;
			}
		}
	}

}
//插入排序（2）元素拿出来（3）符合条件的元素后移
void	sortInertion(int	*_array, int _len)
{
	for (int i = 1; i < _len; i++)
	{
		int k = i;
		int _temp = _array[i];
		
		for (int j = i - 1; j >=0 && (_array[j] > _temp); j--)
		{
			_array[j + 1] = _array[j];//元素后移
			k = j;//插入的位置
		}

		_array[k] = _temp;
	}
}
//冒泡排序:相邻元素比较
void	sortBubble(int	*_array, int _len)
{
	int	_exchange = 1;
	for (int i = 0; (i < _len)&&_exchange; i++)
	{
		for (int j = _len - 1; j > i; j--)
		{
			_exchange = 0;
			if (_array[j]<_array[j-1])
			{
				int	_temp = _array[j];
				_array[j] = _array[j - 1]; 
				_array[j - 1] = _temp;
				_exchange = 1;
			}
		}
	}
}
//希尔排序：分组排序
void	sortShell(int	*_array, int _len)
{
	int gap = _len;
	do 
	{
		gap = gap / 3 + 1;

		for (int i = gap; i < _len; i += gap)
		{
			int k = i;
			int _temp = _array[k];

			for (int j = i - gap; (j >= 0) && (_array[j] > _temp); j -= gap)
			{
				_array[j + gap] = _array[j];
				k = j;
			}
			_array[k] = _temp;
		}
	} while (gap > 1);
}

 int  main()
{

	int	_array[] = {3,56,9,0,5,5,3};
	int	_len = sizeof(_array) / sizeof(*_array);
	printArray(_array, _len);
	sortShell(_array, _len);
	printArray(_array, _len);

	cout<<"排序"<<endl;
	system("pause");
	return 0;
}
#if 0
稳定性
多关键字排序
内排序和外排序
排序的时间性能是评判排序的主要原因
#endif