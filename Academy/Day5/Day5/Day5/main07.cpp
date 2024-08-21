#include <iostream>
using namespace std;
//------------------
//ENUM문
//-------------------
enum class ERockScissorPaper
{
	Rock,
	Scissor,
	Paper,
	End
};

//--------------------
// 변수선언
//--------------------
int myHand = 0;

void PrintRockScissorPaper()
{
	if (myHand == (int)ERockScissorPaper::Rock)
	{
		cout << "바위" << endl;
	}
	else if (myHand == (int)ERockScissorPaper::Scissor)
	{
		cout << "가위" << endl;
	}
	else if (myHand == (int)ERockScissorPaper::Paper)
	{
		cout << "보" << endl;
	}
}

void main()
{
	// 함수
	// void main()
	// {
	// }

	// void 함수명()
	// {
	//		함수내용
	// }

	// 함수는 여러줄있는거에 이름을 붙여준다고 생각하면됨.

	// 함수명 컨벤션
	// 동사로 이름을 짓고
	// 파스칼케이스 (대문자로 시작해서 띄어쓰기부분마다 대문자로)
}