#include <iostream>

using namespace std;

struct Moster
{
private: // 나만 접근할수 있게
public: // 모두가 접근할수 있게
	int Hp;
	int Attack;
};

class CMoster
{
	int Hp;
	int Attack;
};

void main()
{
	// 클래스-1

	// 클래스가 무엇이냐?
	// 클래스는 구조체랑 98% 동일함.(C++에서는)
	int iYear;

	iYear = 3;

	Moster a;
	a.Attack = 10;
	a.Hp = 20;

	// 접근제어자가 기본적으로
	// 구조체는 public이고
	// 클래스는 private 이다.

	// 최초의 설계자
	// 구조체를 뭐로생각하고
	// 클래스를 뭐로생각하고
	// 기본 접근 제어가 구조체는 public이고
	//                 클래스는 private일까를 한번쯤은 고민해주는 게 좋다.

	// C언어는 절차지향 프로그래밍
	// C++언어는 객체지향 프로그래밍
	
	// 절차지향 프로그래밍
	//   - 코드는 위에서부터 아래로 흐른다.
	//   - 객체라는 개념이 없다.

	// 객체지향 프로그래밍
	//   - 우리가 월드를 만드는 거임.
	//   Moster, Player, Camera, GameRule 등을 객체를 만들어서
	//   객체들끼리 알아서 상호작용하는 코드를 짜는 방식을 객체지향 프로그래밍

	//   이상향이다.
	//   그럴듯하게 요약하면
	//   [클래스를 많이써서 코드를 분할하자.]
	//   C언어는 너무 파일하나에 몰아져있다.
}