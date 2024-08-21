#include <iostream>

using namespace std;


enum class RockScissorPaper1 // 플레이어 핸드
{
	Scissor1,
	Rock1,
	Paper1,
	End
};

enum class RockScissorPaper2 // 컴퓨터 핸드
{
	Scissor2,
	Rock2,
	Paper2,
	End
};

void main()
{
	// 1번 숙제 : 로또번호 생성기
	//	힌트 : 로또 통 lotto[45] 배열을 선언
	//	이거를 섞어준후에, 7개를 뽑으면 돼요.
	// 
	// 2번 숙제 : 가위바위보 하나빼기

	int lotto[45] = {}; // 로또 배열
	
	for (int i = 0; i < 45; i++) // 초기화
	{
		lotto[i] = i;
	}

	srand(time(NULL));
	for (int i = 0; i < 45; i++) // 출력
	{
		int lotto1 = rand() % 45;
		int lotto2 = rand() % 45;

		int temp = lotto[lotto1];
		lotto[lotto1] = lotto[lotto2];
		lotto[lotto2] = temp;
	}

	for (int i = 0; i < 45; i++)
	{
		printf("lotto[%d] = %d\n", i, lotto[i]);
	}

	printf("====================================\n");

	int playerLeftHand = 0; // 플레이어 왼손
	int playerRightHand = 0; // 플레이어 오른손

	int computerLeftHand = 0; // 컴퓨터 왼손
	int computerRightHand = 0; // 컴퓨터 오른손

	srand(time(NULL));
	printf("가위(0) 바위(1) 보(2) 중 하나를 선택해주세요.\n");
	scanf_s("%d", &playerLeftHand);
	printf("가위(0) 바위(1) 보(2) 중 하나를 선택해주세요.\n");
	scanf_s("%d", &playerRightHand);

	computerLeftHand = rand() % (int)RockScissorPaper2::End;
	computerRightHand = rand() % (int)RockScissorPaper2::End;

	if (playerLeftHand == (int)RockScissorPaper1::Scissor1) // 플레이어 왼손
	{
		printf("플레이어는 가위를 선택했습니다.\n");
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Rock1)
	{
		printf("플레이어는 바위를 선택했습니다.\n");
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Paper1);
	{
		printf("플레이어는 보를 선택했습니다.\n");
	}

	if (playerRightHand == (int)RockScissorPaper1::Scissor1) // 플레이어 오른손
	{
		printf("플레이어는 가위를 선택했습니다.\n");
	}
	else if (playerRightHand == (int)RockScissorPaper1::Rock1)
	{
		printf("플레이어는 바위를 선택했습니다.\n");
	}
	else if (playerRightHand == (int)RockScissorPaper1::Paper1)
	{
		printf("플레이어는 보를 선택했습니다.\n");
	}

	if (computerLeftHand == (int)RockScissorPaper2::Scissor2) // 컴퓨터 왼손
	{
		printf("컴퓨터는 가위를 선택했습니다.\n");
	}
	else if (computerLeftHand == (int)RockScissorPaper2::Rock2)
	{
		printf("컴퓨터는 바위를 선택했습니다.\n");
	}
	else if (computerLeftHand == (int)RockScissorPaper2::Paper2)
	{
		printf("컴퓨터는 보를 선택했습니다.\n");
	}

	if (computerRightHand == (int)RockScissorPaper2::Scissor2)
	{
		printf("컴퓨터는 가위를 선택했습니다.\n");
	}
	else if (computerRightHand == (int)RockScissorPaper2::Rock2)
	{
		printf("컴퓨터는 바위를 선택했습니다.\n");
	}
	else if (computerRightHand == (int)RockScissorPaper2::Paper2)
	{
		printf("컴퓨터는 보를 선택했습니다.\n");
	}

	if (playerLeftHand == computerRightHand) // 결과 출력
	{
		printf("비겼습니다.\n");
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Scissor1 && computerRightHand == (int)RockScissorPaper2::Rock2)
	{
		printf("졌습니다.\n"); // 가위가 졌을 경우
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Scissor1 && computerRightHand == (int)RockScissorPaper2::Paper2)
	{
		printf("이겼습니다.\n"); // 가위가 이겼을 경우
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Rock1 && computerRightHand == (int)RockScissorPaper2::Paper2)
	{
		printf("졌습니다.\n"); // 바위가 졌을 경우
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Rock1 && computerRightHand == (int)RockScissorPaper2::Scissor2)
	{
		printf("이겼습니다.\n"); // 바위가 이겼을 경우
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Paper1 && computerRightHand == (int)RockScissorPaper2::Scissor2)
	{
		 printf("졌습니다.\n"); // 보가 졌을 경우
	}
	else if (playerLeftHand == (int)RockScissorPaper1::Paper1 && computerRightHand == (int)RockScissorPaper2::Rock2)
	{
		printf("이겼습니다.\n"); // 보가 이겼을 경우
	}
	
	if (playerRightHand == (int)RockScissorPaper1::Scissor1 && computerLeftHand == (int)RockScissorPaper2::Rock2)
	{
		printf("졌습니다.\n"); // 가위가 졌을 경우
	}
	else if (playerRightHand == (int)RockScissorPaper1::Scissor1 && computerLeftHand == (int)RockScissorPaper2::Paper2)
	{
		printf("이겼습니다.\n"); // 가위가 이겼을 경우
	}
	else if (playerRightHand == (int)RockScissorPaper1::Rock1 && computerLeftHand == (int)RockScissorPaper2::Paper2)
	{
		printf("졌습니다.\n"); // 바위가 졌을 경우
	}
	else if (playerRightHand == (int)RockScissorPaper1::Rock1 && computerLeftHand == (int)RockScissorPaper2::Scissor2)
	{
		printf("이겼습니다.\n"); // 바위가 이겼을 경우
	}
	else if (playerRightHand == (int)RockScissorPaper1::Paper1 && computerLeftHand == (int)RockScissorPaper2::Scissor2)
	{
		printf("졌습니다.\n"); // 보가 졌을 경우
	}
	else if (playerRightHand == (int)RockScissorPaper1::Paper1 && computerLeftHand == (int)RockScissorPaper2::Rock2)
	{
		printf("이겼습니다.\n"); // 보가 이겼을 경우
	}
	else
	{
		printf("이겼습니다.\n");
	}
}