#include <iostream>



using namespace std;

class Singleton
{
	static Singleton* GetInstance()
	{
		static Singleton instance;
		return &instance;
	}
private:
	Singleton() {}
	~Singleton() {}
};

class StaticMemory
{
public:
	static int a;
	int b = 0;
};
Singleton Singleton::GetInstance = {};
int StaticMemory::a = 0;
void main()
{
	// 싱글톤

	// 싱글톤은 프로그램 내에 객체를 1개만 두는 디자인 패턴

	// static 변수를 활용해서 만들어준다.
	// static 변수는 객체내에 존재하는게 아니라,
	// 클래스에 1개만 존재하는거라 계속 기억을 할수있다.

	/*StaticMemory::a = 0;

	StaticMemory memory;
	memory.a++;

	cout << memory.a << endl;
	cout << StaticMemory::a << endl;

	cout << &memory.a << endl;
	cout << &StaticMemory::a << endl;*/

	cout << &Singleton::GetInstance() << endl;

	// #define의 비밀
	// 상수라고 안하고
	// 매크로라고 언급했음.
}