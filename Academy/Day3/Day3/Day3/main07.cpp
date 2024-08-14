#include <iostream>

using namespace std;

void main()
{
	// 연산자
	// 남은시간 동안 숙제할 시간
	// 
	// 연산자
	// 대입연산자, 비교연산자, 산술연산자, 논리연산자, 증감연산자, 비트연산자

	// 증감연산자
	int number1 = 7;

	number1 = number1 + 3;
	number1 = number1 - 3;

	number1 = number1 + 3;
	number1 += 3;

	number1 *= 3;
	number1 -= 3;
	number1 /= 3;
	number1 %= 3;

	number1++;
	number1--;
	++number1;
	--number1;

	//논리연산자
	// &&, ||
	// and -> &&
	// or -> ||

	int hp = 100;
	bool haveResurrection = true;

	if (hp <= 0 && haveResurrection)
	{
		printf("부활한다\n");
	}

	if (hp <= 0)
	{
		if (haveResurrection)
		{
			printf("부활한다\n");
		}
	}

	// 가위바위보 팁
	// 승패판정
	// hand => 0 가위 1 바위 2 보 

	// 과제
	// 텍스트 알피지 만들기
	
	// 던전에 입장을 했습니다.
	// 앞에 고블린이 있습니다.
	// 플레이어가 공격을 했습니다.
	// 고블린이 피해를 입었습니다.
	// 플레이어의 레벨이 1올랐습니다.
	// 이어서 계속 탐험을 계속합니다.
	// 고블린이 나타났습니다.
	// 고블린이 먼저 공격했습니다.
	// 플레이어가 막았습니다.
	// 플레이어가 고블린을 공격했습니다.
	// 고블린이 쓰러졌습니다.
	// 플레이어의 레벨이 올랐습니다.
	// 플레이어가 계속 탐험을 계속합니다.



}