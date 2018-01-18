#include<iostream>
using namespace std;

void	swap(int*	_array, int _left, int _right)
{
	int	_temp = _array[_left];
	_array[_left] = _array[_right];
	_array[_right] = _temp;
}

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

//划分过程，第一个元素当枢轴，分成2个有效子序列
int		partition(int _array[], int low, int high)
{
	int	_pv = _array[low];
	
	while (low<high)
	{
		while ((low<high)&&(_array[high]>=_pv))
		{
			high--;//比基准大，本来就在右边，所以high前移动
		}
		swap(_array,low,high);
		while ((low<high)&&(_array[low]<=_pv))
		{
			low++;
		}
		swap(_array, low, high);
	}
	return	low;//返回枢轴的位置
}

void	QSort(int	_array[], int low, int high)
{
	if (low<high)
	{
		//选一个pv值，把数据分别放在pv值的左右两边，并把pivot位置返回出来
		int	pivot = partition(_array, low, high);
		//对子序列1排序
		QSort(_array, low, pivot - 1);
		//对子序列2排序
		QSort(_array, pivot + 1, high);
	}
}
//快速排序：让数据分成两部分；partition  n(logn)
void	QuickSort(int	_array[], int len)
{
	QSort(_array, 0, len - 1);
}

void	Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i<=mid)&&(j<=high))//将小的放到目的地中
	{
		if (src[i]<src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i<=mid)//若还剩几个尾部元素
	{
		des[k++] = src[i++];
	}

	while (j<=high)
	{
		des[k++] = src[j++];
	}
}
//每次分为两路，当只剩下一个元素时，就不需要再划分
void	MSort(int	src[], int	des[], int low, int high, int max)
{
	if (low==high)//只有一个元素，不需要归并，结果赋给des[low]
	{
		des[low] = src[low];
	}
	else
	{
		int		mid = (low + high) / 2;
		int*	space = (int*)malloc(sizeof(int)*max);

		//递归进行两路，两路的划分
		//当剩下一个元素时，递归划分结束，然后开始merge归并操作
		if (space!=NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high);//调用归并函数进行归并
		}

		free(space);
	}
}
//归并排序：牺牲空间换取时间 nlogn
void	MergeSort(int	_array[], int len)
{
	MSort(_array, _array, 0, len - 1, len);
}
int  main01()
{

	int	_array[] = {3,56,9,0,5,5,3};
	int	_len = sizeof(_array) / sizeof(*_array);
	printArray(_array, _len);
	MergeSort(_array, _len);
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