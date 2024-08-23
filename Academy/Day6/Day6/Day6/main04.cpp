#include <iostream>

using namespace std;
enum class ERockScissorPaper
{
	Scissor,
	Rock,
	Paper,
	End
};

void main()
{
	// 3. switch 문법
	//  - 안배워도 되는 문법
	//  - if문으로 완벽하게 대체가능

	// 그런데 왜쓰냐??
	// 가독성 때문

	// while 문 배운이유랑 같음
	// for문이 더 상위호환이지만
	// 가독성측면에서 달라짐.

	// switch 문
	int hand = (int)ERockScissorPaper::Rock;
	switch (hand)
	{
	case (int)ERockScissorPaper::Rock:
		cout << "바위" << endl;
		break;
	case (int)ERockScissorPaper::Scissor:
		cout << "가위" << endl;
		break;
	case (int)ERockScissorPaper::Paper:
		cout << "보" << endl;
		break;

	default:
		cout << "잘못된값" << endl;
		break;
	}

	if (hand == (int)ERockScissorPaper::Rock)
	{
		cout << "바위" << endl;
	}
	else if (hand == (int)ERockScissorPaper::Scissor)
	{
		cout << "가위" << endl;
	}
	else if (hand == (int)ERockScissorPaper::Paper)
	{
		cout << "보" << endl;
	}
	else
	{
		cout << "잘못된 값" << endl;
	}

	// if문과 switch문의 차이점
	// if문은 조건식을 적는거라
	// 정수가 아니라 다른값이 들어올수있음
	// switch문은 정수만 적을 수 있음.
	// case 정수:

	// 그렇기때문에 제약사항이 더 붙음 switch문은
	// 다만, 그 제약사항이 더 좋게 작용할때가 많아서 사용함.
	// + 가독성

	// 굳이 왜??
}