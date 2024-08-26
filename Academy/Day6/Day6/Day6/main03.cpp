#include <iostream>

using namespace std;


void main()
{
	// 2. 숙제풀이 - 별찍기

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "[" << i << " " << j << "]";
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++) // 1번
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++) // 2번
	{
		for (int j = 0; j < 5; j++)
		{
			if ( i + j <= 4)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++) // 3번
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= 4 - j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++) // 4번
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++) // 4번
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}