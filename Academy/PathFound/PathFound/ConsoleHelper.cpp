#include "pch.h"
#include "ConsoleHelper.h"

void ConsoleHelper::SetCursorPosition(int32 x, int32 y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {
		static_cast<SHORT>(x),
		static_cast<SHORT>(y)
	};
	::SetConsoleCursorPosition(output, pos);
}

void ConsoleHelper::SetCursorColor(ConsoleColor color)
{
	HANDLE output=::SetCursorColor
}

void ConsoleHelper::ShowConsoleCursor(bool flag)
{
}
