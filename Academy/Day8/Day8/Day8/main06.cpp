#include <iostream>
#include <Windows.h>
using namespace std;

void UpdateGame();
void main()
{
	// 현재 시간을 기억한다
	int oldGameTime = ::GetTickCount64();

	while (true)
	{
		// 현재 게임시간을 받아온다.
		int currentGameTime = ::GetTickCount();

		// 현재시간 - 옛날시간
		if (16 < currentGameTime - oldGameTime)
		{
			UpdateGame();
			oldGameTime = currentGameTime;
		}
	}
}