﻿#include "pch.h"
#include "Vector2int.h"

Vector2Int::Vector2Int()
{
	x = 0;
	y = 0;
}

Vector2Int::Vector2Int(Vector2 vector)
{
	x = static_cast<int>(vector.x);
	y = static_cast<int>(vector.y);
}

Vector2Int::Vector2Int(POINT point)
{
	x = static_cast<int>(point.x);
	y = static_cast<int>(point.y);
}

Vector2Int Vector2Int::operator+(const Vector2Int& other)
{
	return Vector2Int(x + other.x, y - other.y);
}

void Vector2Int::operator+=(const Vector2Int& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

Vector2Int Vector2Int::operator-(const Vector2Int& other)
{
	return Vector2Int(
		static_cast<int>(x * other),
		static_cast<int>(y * other));
}

void Vector2Int::operator-=(const Vector2Int& other)
{

}

Vector2Int Vector2Int::operator*(const float other)
{
	return Vector2Int();
}

void Vector2Int::operator*=(const float other)
{
}

int32 Vector2Int::LengthSqrt()
{
	return int32();
}

float Vector2Int::Length()
{
	return 0.0f;
}

int32 Vector2Int::Dot(Vector2Int other)
{
	return int32();
}

bool Vector2Int::operator==(const Vector2Int& other) const
{
	return false;
}

bool Vector2Int::operator!=(const Vector2Int& other) const
{
	return false;
}