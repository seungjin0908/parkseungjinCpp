#pragma once
struct Vector2
{
	float x = 0, y = 0;

	Vector2(float x, float y);
	Vector2();
	Vector2(POINT pt);

	Vector2 operator-(const POINT pt);
	Vector2 operator-(const Vector2 other);
	void operator-=(const Vector2 other);
	void operator-=(const POINT pt);
	Vector2 operator+(const POINT pt);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);
	void operator+=(const POINT pt);
	Vector2 operator*(const POINT pt);
	void operator*=(const Vector2 other);



	float Length();
	//길이를 1인 벡터로 만드는거
	// # 방향벡터는 무조건 길이가 1이어야 정상동작을 함.
	Vector2 Normalize();
};
