﻿#include "pch.h"
#include "CommonFunction.h"

namespace Draw
{
	void Text(HDC hdc, int x, int y, wstring str)
	{
		::TextOut(hdc, x, y, str.c_str(), str.length());
	}
	void Rectangle(HDC hdc, int x, int y, int width, int height)
	{
		::Rectangle(hdc, x - width / 2, y - );
	}
}