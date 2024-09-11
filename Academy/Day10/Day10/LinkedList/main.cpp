#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T Data;
	Node<T>* Prev = nullptr;
	Node<T>* Next = nullptr;
};


class LinkedList
{

public:
	void AddData(T data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->Data = data;

		if (_root == nullptr)
		{
			_root = newNode;
		}
		else
		{
			Node<T>* currentNode = _root;
			while (currentNode->Next != nullptr)
			{
				currentNode = currentNode->Next;
			}

			currentNode->Next = newNode;
			newNode->Prev = currentNode;
		}
	}

	void RemoveData(int data)
	{
		Node<T>* currentNode = _root;
		while (currentNode->Next != nullptr)
		{
			currentNode = currentNode->Next;

			if (currentNode->Data == data)
			{
				break;
			}
		}

		if (currentNode->Data != data)
		{
			cout << "데이터를 찾지 못하였습니다." << endl;
			return;
		}

		currentNode->Prev->Next = currentNode->Next;
		if (currentNode->Next != nullptr)
		{
			currentNode->Next->Prev = currentNode->Prev;
		}

		delete currentNode;
		currentNode = nullptr;
	}

	int GetDataBYIndex(int index)
	{
		for (int i = 0; i < index; i++)
		{
			
		}
	}

public:
	Node<T>* _root = nullptr;
};

void main()
{
	// Linked List

	LinkedList* linkedlist = new LinkedList();

	for (int i = 0; i < 10; i++)
	{
		linkedlist->AddData(i);
	}

	linkedlist->RemoveData(5);
	linkedlist->RemoveData(9);

	cout << "완료" << endl;
	delete linkedlist;

	Node<int> a;
	
	a.Data = 10;

	Node<float> b;
	b.Data = 0.4;
}