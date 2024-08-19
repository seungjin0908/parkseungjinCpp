#include <iostream>

using namespace std;

void main()
{
	// 숙제풀이

	// 항상 프로그램을 만들때에는 수도코드를 짜야함.

	// 수도코드
	// [선언] 플레이어레벨 = 1
	// [출력] 플레이어는 [플레이어레벨]레벨 이다.
	srand(time(NULL));
	int playerLevel = 1;
	cout << "플레이어는 " << playerLevel << "레벨 입니다." << endl;
	cout << "던전에 입장하였습니다." << endl;
	cout << "1레벨 고블린과 조우하였습니다. (1: 싸우기, 2: 도망가기)" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		cout << "싸우기를 선택하였습니다." << endl;
		float diePoint = (float)1 / (float)(1 + playerLevel * 2) * 100;
		int random = rand() % 100;
		if (random < diePoint)
		{
			cout << "플레이어는 사망하였습니다." << endl;
			exit(0);
		}
		else
		{
			cout << "전투에서 승리하였습니다." << endl;
			cout << "플레이어가 레벨이 올랐습니다. 현재 레벨 : " << endl;
		}
	}
	else if (choice == 2)
	{
		int random = rand() % 100;

		if (random < 10)
		{
			cout << "플레이어가 사망하였습니다." << endl;
			exit(0);
		}
		else
		{
			cout << "플레이어가 도망에 성공하였습니다. " << endl;
		}
	}

	cout << "플레이어는 " << playerLevel << "레벨로 던전에 탈출하였습니다," << endl;
	cout << "축하드립니다. 게임을 클리어하였습니다." << endl;


}