#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void GotoXY(int x, int y);

void main()
{
	// 과제1
	// GotoXY를 활용해서 꾸미기 (플레이어와 몬스터가 가위바위보 하는 과제를 꾸며봤습니다.)

	GotoXY(0, 0); cout << "┌────────────────────────────────────────────────────┐";
	GotoXY(0, 1); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 1); cout << "│ㅤㅤㅤ▶ PlayerㅤHPㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 2); cout << "│ㅤㅤㅤ▶ Moster	 HPㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 4); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 5); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 6); cout << "└────────────────────────────────────────────────────┘";

	GotoXY(20, 1); cout << "플레이어가 이겼습니다.";
	GotoXY(20, 0); cout << "몬스터가 이겼습니다.";

	GotoXY(3, 2);
	cout << "▶▷";
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}