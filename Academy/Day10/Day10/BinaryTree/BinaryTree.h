#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	Node<T>* parent;
	Node<T>* Left;
	Node<T>* Right;
	T Data;
};

class BinaryTree
{
public:
	void AddData(int data);
	void RemoveData(int data);
	Node<T>* GetNode(int data);

private:
	void RemoveNode(Node<T>* data);
private:
	Node<T>* _root = nullptr;
};


void BinaryTree::AddData(int data)
{
	Node<T>* newNode = new Node<T>();
	newNode->Data = data;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	newNode->parent = nullptr;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	if (this->GetNode(data) != nullptr)
	{
		cout << "중복된 데이터는 추가할 수 없습니다." << data << endl;
		return;
	}

	Node<T>* current = _root;
	while (true)
	{
		if (current->Data < data)
		{
			if (current->Right == nullptr)
			{
				newNode->parent = current;
				
			}
			else
			{

			}
			current = current->Right;
		}
		else if (data < current->Data)
		{
			current = current->Left;
		}
	}


}

void BinaryTree::RemoveData(int data)
{
	// 1. 둘다 없을때 삭제하는 방법
	// -1) 삭제하려는 노드를 찾는다.
	// -2) 부모와의 연을 끊은 다음에
	// -3) 삭제하려는 노드를 삭제한다.

	Node<T>* findNode = this->GetNode(data);

	if (findNode == nullptr)
	{
		cout << "없는 데이터입니다." << endl;
		return;
	}

	if (findNode->Left == nullptr && findNode->Right == nullptr)
	{
		if (findNode->parent->Left == findNode)
		{
			findNode->parent->Left == nullptr;
		}
		if (findNode->parent->Right == findNode)
		{
			findNode->parent->Right = nullptr;
		}
		delete findNode;
		findNode = nullptr;
	}
	else if (findNode->Left != nullptr && findNode->Right == nullptr)
	{

	}

	else if (findNode->Left == nullptr && findNode->Right != nullptr)
	{

	}
	else
	{
		Node<T>* swapNode = findNode->Right;

		while (swapNode->Left != nullptr)
		{
			swapNode = swapNode->Left;
		}

		findNode->Data = swapNode->Data;

		
	}
}

Node<T>* BinaryTree::GetNode(int data)
{
	Node<T>* current = _root;
	while (current != nullptr && current->Data != data)
	{
		if (current->Data < data)
		{
			current = current->Right;
		}
		else if (data < current->Data)
		{
			current = current->Left;
		}
	}

	return current;
}