#include <iostream>

using namespace std;

int Add(int num1, int num2)
{
	return num1 + num2;
}

void VoidFunction()
{
	printf("Call Function\n");
}

// AI 행동패턴들
// (Move, Attack, SearchTarget)
//  이런함수들을 DoAI 라는 함수포인터안에 상황에맞게 넣어주기만하고
// 보스 Update문에서 DoAI(); 이렇게 실행만 시킴.

void main()
{
	// 함수포인터
	// 함수도 하나의 주솟값을 가진다.
	// 그렇기 때문에 포인터로 함수위치로 기억했다가 필요할때 사용하겠다.

	// 함수포인터 변수선언
	// 자료형 변수명 = 값;
	int (*function)(int, int) = &Add;
	
	// 그동안의 변수
	// 자료형 변수명 = 값;
	int myValue = 3;

	// 그동안 포인터라고하면
	// 어떤자료형을 가지고있었는지 유추할수있게끔 만들어줬다.
	// Sprite*
	// 이 변수는 Sprite 형태의 변수만 기억하는 포인터이다.

	int* c = nullptr;

	int(*d) = nullptr;


	int result = function(3, 5);
	printf("result : %d\n", result);


	printf("Add Function Address : %p\n", &Add);
	printf("VoidFunction Address : %p\n", &VoidFunction);

	void(*myFunction2)() = &VoidFunction;
	myFunction2();

}