#include <iostream>
#include "MainGame.h"
using namespace std;

void main()
{
	// 룰 세팅
	// 1. 두명의 플레이어가 화투카드 1장씩 나눠갖는다.
	// 2. 두명의 플레이어가 서로 베팅한다.
	// 3. 한장씩 더 나눠갖는다.
	// 4. 두명의 플레이어가 서로 베팅한다.
	// 5. 족보가 높은사람이 판돈을 모두 가져간다.

	// 수도코드
	// 1. 화투카드 24장을 정의한다.
	// 2. 화투카드를 섞는다.
	// 3. 두플레이어한테 한장씩 나눠준다.
	// 4. 두플레이어가 각각 베팅한다.
	// 5. 두플레이어한테 한장씩 나눠준다.
	// 6. 두플레이어가 각각 베팅한다.
	// 7. 족보가 높은 사람한데 판돈을 모두 준다.


	MainGame* mainGame = new MainGame();
	mainGame->Init();

	mainGame->Run();

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}