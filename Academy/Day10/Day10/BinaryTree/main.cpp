#include <iostream>
#include "BinaryTree.h"
using namespace std;

void main()
{
	srand(time(NULL));

	BinaryTree bt;

	for (int i = 0; i < 1000; i++)
	{
		bt.AddData(rand());
	}

	bt.AddData(-1);

	Node<int>* a = bt.GetNode(-1);
	cout << "a : " << a << endl;
}