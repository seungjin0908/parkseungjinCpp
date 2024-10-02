#include "pch.h"
#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(POINT pt)
{
	this->x = static_cast<float>(pt.x);
	this->y = static_cast<float>(pt.y);
}

float Vector2::Length()
{
	// 피타고라스 정의
	// ? * ? = x * x + y * y

	return static_cast<float>(::sqrt(x * x + y * y));
}

Vector2 Vector2::Noramlize()
{
	float lenght = this->Length();

	if (lenght <= 0.0000000000001f)
	{
		return *this;
	}

	return Vector2(x / lenght, y / lenght);
}
