#include<iostream>
#include<iomanip>
using namespace std;

//广度优先算法
bool	findValue(int (*array)[5], int _width, int _value)
{
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(array[i][j]==_value)return true;
		}
	}
	return false;
}

int		main01()
{
	int	_data[5][5];
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			int _value = rand() / 100;
			_data[i][j] = _value;
		}
	}
	_data[3][3] = 1000;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << " "<<setw(3) << setfill('0') << _data[i][j];
		}
		cout << endl;
	}

	bool	_isFind = findValue(_data, 5, 1000);
	
	system("pause");
	return 0;
}