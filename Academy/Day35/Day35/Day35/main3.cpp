#include <iostream>
#include <functional>
using namespace std;

int Add(int num1, int num2)
{
	return num1 + num2;
}

class Object
{
public:
	void Attack()
	{
		printf("Attack!\n");
	}

	void Move()
	{
		printf("Move!\n");
	}

	void Update()
	{
		int rnd = rand() % 2;
		switch (rnd)
		{
		case 0:
			_doAI
		default:
			break;
		}
	}

public:
	void (Object::* _doAI)() = &Object::Attack;
};

void main()
{
	// callback function
	function<void()>onclick = nullptr;
	// void에 parameter void 인 함수를 함수포인터처럼 기억할 수 있게 하겠다.


	function<int(int, int)>myFunction = nullptr;
	myFunction = Add;


	int result = myFunction(1, 3);
	printf("result = %d\n", result);

	// 클래스의 함수는 어떻게 실행시킬것인가?

	function<void()>objectAi = nullptr;

	// 그래서 이 함수를 누가 쓸건데?
	// 객체까지 항상 필요하다.
	Object myObject;
	objectAi = bind(&Object::Attack, myObject);

	objectAi();

}