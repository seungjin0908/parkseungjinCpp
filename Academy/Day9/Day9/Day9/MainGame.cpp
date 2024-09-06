#include "MainGame.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void MainGame::Init()
{
	srand(time(NULL));

	cout << "스네이크 게임을 시작하겠습니다." << endl;

	for (int i = 5; i >= 0; i--)
	{
		Sleep(1000);

	}
}

void MainGame::Run()
{
	ShuffleCard();

	for (int i = 0; i < 52; i++)
	{
		cout << _card[i] << endl;
	}
}
void MainGame::Release()
{

}

bool IsGameEnd()
{
	return false;
}

// 실습 하이로우세븐 코드를 mainGame으로 이식시키기

// 숙제
// 섯다
// 1:1로 컴퓨터랑 섯다 진행
