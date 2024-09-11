#pragma once
#include <iostream>
using namespace std;

class Vector
{
// 함수는 public
public:
	// 데이터 추가
	void push_back(int data);
	// 데이터 삭제
	void pop_back(int data);
	// 데이터 접근
	int operator[](int index);

	int Size() { return _size; }
	int capacity() { return _capacity; }

// 변수는 private
private:
	int* _arr = nullptr;
	int _size = 0;
	int _capacity = 0;
};

// 데이터 추가
void Vector::push_back(int data)
{
	// 데이터 추가하는 방법
	if (_arr == nullptr)
	{
		_arr = new int[1];
	}
	else
	{
		if (_capacity == _size)
		{
			// 새롭게 공간을 만들고
			int* newArr = new int[_size + 1];

			// 새롭게 만든 공간에 현재데이터를 넣어주고
			for (int i = 0; i < _size; i++)
			{
				newArr[i] = _arr[i];
			}

			// 기존공간 파괴
			delete[] _arr;
			_arr = newArr;
		}
	}

	_arr[_size] = data;

	_size++;
}
// 데이터 삭제
void Vector::pop_back(int data)
{
	_size--;
}
// 데이터 접근
int Vector::operator[](int index)
{
	assert(index <= _size);

	return _arr[index];
}