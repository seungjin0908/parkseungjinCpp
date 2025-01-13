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

Vector2 Vector2::operator-(const POINT pt)
{
	return Vector2{ static_cast<float>(this->x - pt.x), static_cast<float>(this->y - pt.y) };
}
Vector2 Vector2::operator-(const Vector2 other)
{
	return Vector2{ static_cast<float>(this->x - other.x), static_cast<float>(this->y - other.y) };
}
void Vector2::operator-=(const Vector2 other)
{
	this->x -= other.x;
	this->y -= other.y;
}
void Vector2::operator-=(const POINT pt)
{
	this->x -= static_cast<float>(pt.x);
	this->y -= static_cast<float>(pt.y);
}
Vector2 Vector2::operator+(const POINT pt)
{
	return Vector2{ static_cast<float>(this->x + pt.x), static_cast<float>(this->y + pt.y) };
}
Vector2 Vector2::operator+(const Vector2 other)
{
	return Vector2{ static_cast<float>(this->x + other.x), static_cast<float>(this->y + other.y) };
}
void Vector2::operator+=(const Vector2 other)
{
	this->x += other.x;
	this->y += other.y;
}
void Vector2::operator+=(const POINT pt)
{
	this->x += static_cast<float>(pt.x);
	this->y += static_cast<float>(pt.y);
}
Vector2 Vector2::operator*(const float other)
{
	return Vector2{ static_cast<float>(this->x * other), static_cast<float>(this->y * other) };
}
void Vector2::operator*=(const float other)
{
	this->x *= other;
	this->y *= other;
}
Vector2 Vector2::operator/(const float other)
{
	return Vector2{ static_cast<float>(this->x / other), static_cast<float>(this->y / other) };
}
void Vector2::operator/=(const float other)
{
	this->x /= other;
	this->y /= other;
}
bool Vector2::operator==(const Vector2 other)
{
	if (EQUALS(this->x, other.x) && EQUALS(this->y, other.y))
	{
		return true;
	}

	return false;
}
bool Vector2::operator!=(const Vector2 other)
{
	if (EQUALS(this->x, other.x) && EQUALS(this->y, other.y))
	{
		return false;
	}

	return true;
}

float Vector2::Dot(Vector2 other)
{
	return x * other.x + y * other.y;
}
float Vector2::Dot(Vector2 vec1, Vector2 vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

Vector2 Vector2::Reflect(Vector2 normal)
{
	Vector2 normalizedNormalVector = normal.Normalize();
	Vector2 normalizedoriginVector = this->Normalize();

	Vector2 temp = normalizedNormalVector;
	float tempLength = normalizedoriginVector.Dot(normalizedNormalVector * -1);
	temp *= tempLength;

	return normalizedoriginVector + temp * 2;
}
Vector2 Vector2::Reflect(Vector2 origin, Vector2 normal)
{
	Vector2 normalizedNormalVector = normal.Normalize();
	Vector2 normalizedoriginVector = origin.Normalize();

	Vector2 temp = normalizedNormalVector;
	float tempLength = normalizedoriginVector.Dot(normalizedNormalVector * -1);
	temp *= tempLength;

	return normalizedoriginVector + temp * 2;
}

float Vector2::LengthSqrt()
{
	return static_cast<float>(x * x + y * y);
}
float Vector2::Length()
{
	return static_cast<float>(::sqrt(x * x + y * y));
}
Vector2 Vector2::Normalize()
{
	// 현재 벡터를 길이를 1로 만든다.
	float length = this->Length();

	if (length <= 0.0000000000001f)
	{
		return *this;
	}

	return Vector2(x / length, y / length);
}

float Vector2::SignedAngle(const Vector2 from, const Vector2 to)
{
	/*
	공식
		내적 = |A||B|cos(theta)
		외적 = |A||B|sin(theta)

		=> 방향벡터로 모두 빗변의 길이가 1이라고 가정하였을때,
		내적 = 밑변
		외적 = 높이

		tan(theta) = 외적 / 내적

		각도 = atan2(외적, 내적);

		여기서 나오는 각도는 라디안

		//라디안 : 파이(3.141592)를 180도라고 지정하였을때의 값
		//라디안기준으로 3.151592 ==> 180도

		//디그리 : 각도 (180도)
	*/

	Vector2 fromVec = from;
	Vector2 toVec = to;

	fromVec = fromVec.Normalize();
	toVec = toVec.Normalize();

	float dot = fromVec.Dot(toVec);
	//외적 = x1 * y2 - x2 * y1
	float det = fromVec.x * toVec.y - toVec.x * fromVec.y;

	float angle = atan2(det, dot);

	return Rad2Deg(angle);
}
float Vector2::SignedAngle(const Vector2 to)
{
	return Vector2::SignedAngle(*this, to);
}