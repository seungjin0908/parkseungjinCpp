﻿#pragma once

namespace Draw
{
	void Text(HDC hdc, int x, int y, wstring str);
	void Rectangle(HDC hdc, int x, int y, int width, int height);
	void Rectangle(HDC hdc, RECT rc);
	void Ellipse(HDC hdc, int x, int y, int width, int height);
}

namespace Collision
{
	bool PtInRect(POINT pt, RECT rc);
	bool RectInRect(RECT rc1, RECT rc2);
	bool RectInRect(CenterRect centerRect1, CenterRect centerRect2);
	bool CircleInCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2);
	bool RectInCircle(CenterRect centerRect, Vector2 pos, float radius);
}