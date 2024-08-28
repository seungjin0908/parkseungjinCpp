#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void GotoXY(int x, int y);

void main()
{
	// GotoXY

	cout << "출력" << endl;

	GotoXY(40, 1);
	cout << "플레이어 골드 : 1000";

	GotoXY(40, 1);
	cout << "플레이어 골드 : 1000";
	int choice = 0;

	while (true)
	{
		GotoXY(3, 2);
		cout << "▶";

		if (_kbhit())
		{
			char inputkey = _getch();
			if (inputkey == 's')
			{
				choice++;
			}
		}
	}
}

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}