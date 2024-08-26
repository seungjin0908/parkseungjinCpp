#include <iostream>

using namespace std;

void Function1(int a);

void main()
{
	//함수-2

	// 전방선언
	// 간단하게 사용하는 방법

	int value = 0;
	Function1(value);
	cout << "value : " << value << endl;

	// 2번째 래퍼런스 형태를 사용해서 값을 바꾸는 방법
	// 이거를 조금 더 추천함.
}

void Function1(int a)
{
	cout << "Function1" << endl;
	cout << "a : " << a << endl;
	a = 10;
}