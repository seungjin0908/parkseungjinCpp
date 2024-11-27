#include <iostream>

using namespace std;

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
	// 함수포인터 2
	// 그래서 클래스의 함수는 어떻게 실행시킬것인가?

	void(Object::*myFunction)() = &Object::Attack;
	
	Object a;
	(a.*myFunction)();
	// a라는 객체로 안에 들어가서
	// myFunction이 가르키고있는 내용을 실행시킨다.
	// myFunction은 함수포인터이니까 함수를 실행시킨다.

	
	

}