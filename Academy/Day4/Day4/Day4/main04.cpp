#include <iostream>

using namespace std;

// enum (옛날 문법, 최근 문법)
enum eRockScissorPaper
{
	RSP_SCISSOR = 0,
	RSP_ROCK,
	RSP_PAPER,
	RSP_END
};

// C++ 의 enum
enum class RockScissorPaper
{
	Scissor,
	Rock,
	Paper,
	End
};

// 변수선언
// [자료형] 변수병 = 값;

// 기본 자료형 : int, flaot, char, bool
// 사용자 정의 자료형 : enum(정수형)

void main()
{
	// 수도코드
	// [출력] 가위(0), 바위(1), 보(2) 중에서 선택해주세요
	// [입력] playerHand
	// [로직] comHand = rand()%3
	// [출력] [playerHand]를 선택하였습니다.
	// [출력] 컴퓨터는 [comHand]를 선택하였습니다.
	// [IF] (playerHand == comHand)

	srand(time(NULL));
	printf("가위(0), 바위(1), 보(2) 중에서 선택해주세요\n");
	int playerHand = 0;
	int comHand = 0;
	
	// 상수로 써주는 값은 모두 대문자로 써주기! (혹은 파스칼)
	int SCISSOR = 0;
	int ROCK = 1;
	int PAPER = 2;
	int ROCKSCISSORPAPER_END = 3;

	scanf_s("%d", &playerHand);
	comHand = rand() % ROCKSCISSORPAPER_END;

	if (playerHand == 0)
	{
		printf("플레이어는 가위를 선택하였습니다.\n");
	}
	else if (playerHand == 1)
	{
		printf("플레이어는 바위를 선택하였습니다.\n");
	}
	else if (playerHand == 2)
	{
		printf("플레이어는 보를 선택하였습니다.\n");
	}
	else if (comHand == 0)
	{
		printf("컴퓨터는 가위를 선택하였습니다.\n");
	}
	else if (comHand == 1)
	{
		printf("컴퓨터는 바위를 선택하였습니다.\n");
	}
	else if (comHand == 2)
	{
		printf("컴퓨터는 보를 선택하였습니다.\n");
	}

	if (playerHand == comHand)
	{
		printf("비겼습니다.\n");
	}
	else if (playerHand == 0 && comHand == 1)
	{
		printf("졌습니다.\n");
	}
	else if (playerHand == 1 && comHand == 2)
	{
		printf("졌습니다.\n");
	}
	else if (playerHand == 2 && comHand == 0)
	{
		printf("졌습니다.\n");
	}
	else
	{
		printf("이겼습니다.\n");
	}
}

// 0,1,2 코드 중간에 나오는 일반적인 숫자
// 매직넘버라고 부르는 되게 안좋은 숫자

// 매직넘버 << 작성자말고는 그 누구도 알아볼수없는 위험한 숫자