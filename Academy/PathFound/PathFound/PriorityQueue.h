#pragma once
#include <vector>
#include <assert.h>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	vector<T> _arr;

public:
	T& Peek()
	{
		assert(0 < _arr.size());
		return _arr[0];
	}

	bool Empty()
	{
		return _arr.size() == 0;
	}

	void Pop()
	{
		::swap(_arr[0], _arr[_arr.size() - 1]);

		_arr.pop_back();

		int index = 0;
		if (_arr.size() == 0)
			return;

		while (true)
		{
			//왼쪽인덱스가 없다면 (왼쪽 인덱스가 사이즈보다 더 크다면)
			//  -> 자식이 더이상 없다면
			if (_arr.size() - 1 < GetLeftChildIndex(index))
			{
				break;
			}

			// 1. 왼쪽노드만 있을때
			//  -> 오른쪽 인덱스가 사이즈보다 더크면
			if (_arr.size() - 1 < GetRightChildIndex(index))
			{
				// 왼쪽이랑만 비교하면됨.
				T& leftNode = _arr[GetLeftChildIndex(index)];

				if (_arr[index] < leftNode)
				{
					// 스왑을 해준다.
					::swap(leftNode, _arr[index]);

					// 인덱스를 그에 맞게 세팅해준다.
					index = GetLeftChildIndex(index);
				}
			}
			else
			{
				break;
			}
			// 2. 오른쪽노드도 있을때
			else
			{
				T& leftNode = _arr[GetLeftChildIndex(index)];
				T& rightNode = _arr[GetRightChildIndex(index)];

				if (rightNode < leftNode)
				{
					// 스왑을 해준다.
					::swap(leftNode, leftNode);

					// 인덱스를 그에 맞게 세팅해준다.
					index = GetRightChildIndex(index);
				}
				else
				{
					break;
				}
			}
			else
			{
				if (_arr[index] < rightNode)
				{
					// 스왑을 해준다.
					::swap(rightNode, _arr[index]);

					// 인덱스를 그에 맞게 세팅해준다.
					index = GetRightChildIndex(index);
				}
				else
				{
					break;
				}
			}
		}
	}

	void Push(T data)
	{
		_arr.push_back(data);

		int index = _arr.size() - 1;

		while (true)
		{
			if (index <= 0)break;

			T& parentNode = _arr[GetParentIndex(index)];
			T& currentNode = _arr[index];

			if (parentNode < currentNode)
			{
				::swap(parentNode, currentNode);

				index = GetParentIndex(index);
			}
			else
			{
				break;
			}
		}
	}


private:
	int GetParentIndex(int index)
	{
		int rv = (index - 1) / 2;

		return rv;
	}

	int GetLeftChildIndex(int index)
	{
		int rv = (index * 2) + 1;
		return rv;
	}

	int GetRightChildIndex(int index)
	{
		int rv = (index * 2) + 2;
		return rv;
	}
};

