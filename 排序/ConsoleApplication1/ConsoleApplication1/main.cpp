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
//ѡ��
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
//��������2��Ԫ���ó�����3������������Ԫ�غ���
void	sortInertion(int	*_array, int _len)
{
	for (int i = 1; i < _len; i++)
	{
		int k = i;
		int _temp = _array[i];
		
		for (int j = i - 1; j >=0 && (_array[j] > _temp); j--)
		{
			_array[j + 1] = _array[j];//Ԫ�غ���
			k = j;//�����λ��
		}

		_array[k] = _temp;
	}
}
//ð������:����Ԫ�رȽ�
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
//ϣ�����򣺷�������
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

//���ֹ��̣���һ��Ԫ�ص����ᣬ�ֳ�2����Ч������
int		partition(int _array[], int low, int high)
{
	int	_pv = _array[low];
	
	while (low<high)
	{
		while ((low<high)&&(_array[high]>=_pv))
		{
			high--;//�Ȼ�׼�󣬱��������ұߣ�����highǰ�ƶ�
		}
		swap(_array,low,high);
		while ((low<high)&&(_array[low]<=_pv))
		{
			low++;
		}
		swap(_array, low, high);
	}
	return	low;//���������λ��
}

void	QSort(int	_array[], int low, int high)
{
	if (low<high)
	{
		//ѡһ��pvֵ�������ݷֱ����pvֵ���������ߣ�����pivotλ�÷��س���
		int	pivot = partition(_array, low, high);
		//��������1����
		QSort(_array, low, pivot - 1);
		//��������2����
		QSort(_array, pivot + 1, high);
	}
}
//�������������ݷֳ������֣�partition  n(logn)
void	QuickSort(int	_array[], int len)
{
	QSort(_array, 0, len - 1);
}

void	Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i<=mid)&&(j<=high))//��С�ķŵ�Ŀ�ĵ���
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

	while (i<=mid)//����ʣ����β��Ԫ��
	{
		des[k++] = src[i++];
	}

	while (j<=high)
	{
		des[k++] = src[j++];
	}
}
//ÿ�η�Ϊ��·����ֻʣ��һ��Ԫ��ʱ���Ͳ���Ҫ�ٻ���
void	MSort(int	src[], int	des[], int low, int high, int max)
{
	if (low==high)//ֻ��һ��Ԫ�أ�����Ҫ�鲢���������des[low]
	{
		des[low] = src[low];
	}
	else
	{
		int		mid = (low + high) / 2;
		int*	space = (int*)malloc(sizeof(int)*max);

		//�ݹ������·����·�Ļ���
		//��ʣ��һ��Ԫ��ʱ���ݹ黮�ֽ�����Ȼ��ʼmerge�鲢����
		if (space!=NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high);//���ù鲢�������й鲢
		}

		free(space);
	}
}
//�鲢���������ռ任ȡʱ�� nlogn
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

	cout<<"����"<<endl;
	system("pause");
	return 0;
}
#if 0
�ȶ���
��ؼ�������
�������������
�����ʱ�������������������Ҫԭ��
#endif