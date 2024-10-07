#include <iostream>
using namespace std;

class PrintObject
{
public:
	// 추상함수 키워드 : abstract
	// abstract 키워드는
	// 추상함수로
	// 구현을 하지 않는다.
	virtual void Print() abstract;
};

class GameObject
{
protected:
	string _name;
	string _tag;
public:
	// 가상함수 키워드 : virtual
	virtual void Init()
	{
		cout << "GameObject Init" << endl;
	}
	virtual void Update()
	{
		cout << "GameObject Update" << endl;
	}
	virtual void Render()
	{
		cout << "GameObject Render" << endl;
	}
	virtual void Release()
	{
		cout << "GameObject Release" << endl;
	}

	// 소멸자도 가상함수가 있다.
	GameObject()
	{

	}
	virtual ~GameObject()
	{

	}
	 
};

class Creature : public GameObject
{
public:
	virtual void Init() override
	{
		cout << "Creture Init" << endl;
	}
	virtual void Update() override
	{
		cout << "Creture Update" << endl;
	}
	virtual void Render() override
	{
		cout << "Creturn Render" << endl;
	}
	virtual void Release() override
	{
		cout << "Creture Release" << endl;
	}
};

void main()
{
	GameObject* creature = new Creature();
	creature->Init();
	creature->Render();
	creature->Update();
	creature->Release();

	delete creature;
}

// 가상함수 상속 이런것들을 왜 배웠냐

// 씬을
// 들어갈 씬의 내용이
// 씬을 상속받아서
// DevScene
// Day18Scene
// Day19Scene이런식으로 만들예정임.