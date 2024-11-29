#include "pch.h"
#include "CommonFunction.h"

namespace Draw
{
	void Text(HDC hdc, int x, int y, wstring str)
	{
		::TextOut(hdc, x, y, str.c_str(), str.length());
	}
	void Rectangle(HDC hdc, int x, int y, int width, int height)
	{
		::Rectangle(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	}
	void Ellipse(HDC hdc, int x, int y, int width, int height)
	{
		::Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	}

	void Rectangle(HDC hdc, RECT rc)
	{
		::Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
}

namespace Collision
{
	bool PtInRect(POINT pt, RECT rc)
	{
		if (rc.left <= pt.x && pt.x <= rc.right)
		{
			if (rc.top <= pt.y && pt.y <= rc.bottom)
			{
				return true;
			}
		}

		return false;
	}

	bool RectInRect(RECT rc1, RECT rc2)
	{
		POINT pt1 = { rc1.left, rc1.top };
		POINT pt2 = { rc1.right, rc1.top };
		POINT pt3 = { rc1.left, rc1.bottom };
		POINT pt4 = { rc1.right, rc1.bottom };
		POINT pt5 = { rc2.left, rc2.top };
		POINT pt6 = { rc2.right, rc2.top };
		POINT pt7 = { rc2.left, rc2.bottom };
		POINT pt8 = { rc2.right, rc2.bottom };

		if (PtInRect(pt1, rc2) || PtInRect(pt2, rc2) || PtInRect(pt3, rc2) || PtInRect(pt4, rc2)
			|| PtInRect(pt5, rc1) || PtInRect(pt6, rc1) || PtInRect(pt7, rc1) || PtInRect(pt8, rc1))
		{
			return true;
		}

		return false;
	}

	bool RectInRect(CenterRect centerRect1, CenterRect centerRect2)
	{
		RECT rc1 = centerRect1.ToRect();
		RECT rc2 = centerRect2.ToRect();

		POINT pt1 = { rc1.left, rc1.top };
		POINT pt2 = { rc1.right, rc1.top };
		POINT pt3 = { rc1.left, rc1.bottom };
		POINT pt4 = { rc1.right, rc1.bottom };
		POINT pt5 = { rc2.left, rc2.top };
		POINT pt6 = { rc2.right, rc2.top };
		POINT pt7 = { rc2.left, rc2.bottom };
		POINT pt8 = { rc2.right, rc2.bottom };

		if (PtInRect(pt1, rc2) || PtInRect(pt2, rc2) || PtInRect(pt3, rc2) || PtInRect(pt4, rc2)
			|| PtInRect(pt5, rc1) || PtInRect(pt6, rc1) || PtInRect(pt7, rc1) || PtInRect(pt8, rc1))
		{
			return true;
		}

		return false;
	}


	bool CircleInCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2)
	{
		// Circle <-> Circle 충돌은
		// circle1 , circle2의 중심 좌표거리가
		// rad1 + rad2 거리보다 짧으면 충돌, 크면 충돌안함.

		Vector2 lengthVector = pos2 - pos1;
		float legnth_sqrt = lengthVector.LengthSqrt();

		if (legnth_sqrt <= (radius1 + radius2) * (radius1 + radius2))
		{
			return true;
		}

		return false;
	}

	bool RectInCircle(CenterRect centerRect, Vector2 pos, float radius)
	{
		// 코딩테스트에서도 물어보지않고
		// 면접에서도 물어보지않고
		// 그어디에서도 궁금해하질않습니다.

		// 사각형의 중심좌표와 원의 중신 좌표 사이의 거리를 구합니다 
		float dx = abs(centerRect.pos.x - pos.x);
		float dy = abs(centerRect.pos.y - pos.y);

		// 사각형과 원의 중심 사이의 거리를 계산
		float distX = dx - centerRect.width / 2;
		float distY = dy - centerRect.height / 2;

		//1. 원을 크게 사각형화 해도 충돌이 되지 않는 경우
		if (distX > radius || distY > radius)
		{
			return false;
		}

		//2. 사각형이 원의 중심점을 포함하고 있는 경우
		if (distX <= 0 || distY <= 0)
		{
			return true;
		}

		//3. 사각형의 꼭지점과 원의 중심 사이의 거리가 반지름보다 작은 경우
		float cornerDistanceSqrt = (distX * distX) + (distY * distY);

		return cornerDistanceSqrt <= (radius * radius);
	}
}