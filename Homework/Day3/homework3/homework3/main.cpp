#include <iostream>
using namespace std;

/*
1. 텍스트 알피지 만들기
 - 내용은 마음대로 수정하세요!
 - 선택과, 랜덤만 들어가면 뭐든 ok입니다!
 - 아스키아트를 활용하면 재미붙일 수 있을거에요.

출력예시)

플레이어는 1레벨 입니다.
던전에 입장하였습니다.

1레벨 고블린과 조우하였습니다.
(1: 싸우기, 2: 도망가기)

 -> 싸우기 선택시, (고블린 레벨)/(1+플레이어레벨*2) 확률로 사망
 -> 사망하면 게임 종료, 전투에서 승리시, 레벨업

 -> 도망가기 선택시, 10% 확률로 사망
 -> 사망하면 게임 종료


2레벨 고블린과 조우하였습니다.
(1: 싸우기, 2: 도망가기)

 -> 싸우기 선택시, (고블린 레벨)/(1+플레이어레벨*2) 확률로 사망
 -> 사망하면 게임 종료, 전투에서 승리시, 레벨업

 -> 도망가기 선택시, 10% 확률로 사망
 -> 사망하면 게임 종료

3레벨 고블린과 조우하였습니다.
(1: 싸우기, 2: 도망가기)

 -> 싸우기 선택시, (고블린 레벨)/(1+플레이어레벨*2) 확률로 사망
 -> 사망하면 게임 종료, 전투에서 승리시, 레벨업

 -> 도망가기 선택시, 10% 확률로 사망
 -> 사망하면 게임 종료

플레이어는 몇레벨로 던전에 탈출하였습니다.
축하드립니다 게임을 클리어하셨습니다.

*/

// 2. 가위바위보게임 만들기
/*
출력예시)
가위(0), 바위(1), 보(2) 중에서 선택해주세요
가위를 선택하셨습니다.

컴퓨터는 보를 선택하였습니다.

승리하였습니다.
*/

void main()
{
	int player = 0; // 플레이어
	int moster = 0; // 고블린
	int win = 0; // 이김
	int lose = 0; // 짐

	int number1 = 0; // 싸우기
	int number2 = 0; // 도망치기

	int random1 = rand(); // 몬스터가 확률적으로 사망
	int random2 = rand(); // 플레이어가 확률적으로 사망
	int runRandom = rand() % 10; // 플레이어가 도망칠 확률

	printf("플레이어는 레벨 1입니다.\n");
	printf("던전에 입장하였습니다.\n");

	printf("1레벨의 고블린을 만났습니다.\n");
	scanf_s("%d", &number1);

	if (player == number1)
	{
		printf("싸움을 시작합니다.\n");
		scanf_s("%d %d", &player, &moster);
	}
	else if (player == win) // 플레이어가 이겼을때
	{
		printf("플레이어가 이겼습니다.\n");
		scanf_s("%d", &player);
		random1 = rand();
		player = (moster + 1) % (1 + player * 2);
	}
	else if (player == lose) // 플레이어가 졌을때
	{
		printf("고블린이 이겼습니다.\n");
		scanf_s("%d", &moster);
		random2 = rand();

	}
	else if (player == number2)
	{
		printf("플레이어가 도망을 칩니다.\n");
		scanf_s("%d", &runRandom);
		printf("플레이어가 도망을 치다가 죽었습니다.\n");
	}
	printf("1레벨의 고블린을 만났습니다.\n");
	scanf_s("%d", &number2);

	player = (moster + 1) % (1 + player * 2); // 확률로 사망
	moster = (player + 1) % (1 + moster * 2); // 확률로 사망
	runRandom = rand() / 10; // 확률로 도망

	printf("====================================\n");

	int playerHand = 0; // 플레이어
	int computerHand = 0; // 컴퓨터
	int Rock = 0; // 바위
	int Paper = 0; // 보
	int Scissors = 0; // 가위

	int computerHand1 = rand() % 3;
	int playerHand1 = rand() % 3;
	Rock == 1;
	Paper == 2;
	Scissors == 0;

	printf("가위(0) 바위(1) 보(2) 중 하나를 선택하세요\n");
	scanf_s("%d", &playerHand);
	scanf_s("%d", &computerHand);

	if (playerHand == 1) // 플레이어가 바위를 선택
	{
		printf("플레이어가 바위를 냈습니다.\n");
		scanf_s("%d", &computerHand1);
		computerHand1 = rand() % 3;
	}
	else if (playerHand == 0) // 플레이어가 가위를 선택
	{
		printf("플레이어가 가위를 냈습니다.\n");
		scanf_s("%d", &computerHand1);
		computerHand1 = rand() % 3;
	}
	else if (playerHand == 2) // 플레이어가 보를 선택
	{
		printf("플레이어가 보를 냈습니다.\n");
		scanf_s("%d", &computerHand1);
		computerHand1 = rand() % 3;
	}
	else if (computerHand == 1) // 컴퓨터가 바위를 선택
	{
		printf("컴퓨터가 바위를 선택하였습니다.\n");
		playerHand1 = rand() % 3;
	}
	else if (computerHand == 0) // 컴퓨터가 가위를 선택
	{
		printf("컴퓨터가 가위를 선택하였습니다.\n");
		playerHand1 = rand() % 3;
	}
	else if (computerHand == 2) // 컴퓨터가 보를 선택
	{
		printf("컴퓨터가 보를 선택하였습니다.\n");
		playerHand1 = rand() % 3;
	}
	
}