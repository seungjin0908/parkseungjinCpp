#pragma once
#include "Collider.h"
class CircleCollider : public Collider
{
	using Super = Collider;
public:
	CircleCollider();
	virtual ~CircleCollider() {}

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	virtual bool CheckCollision(Collider* other);

public:
	Vector2 GetCollisionPos();
	float GetRadius() { return _radius; }
	void SetCollision(Vector2 pos, float radius) { _pos = pos; _radius = radius; }

private:
	Vector2 _pos;
	float _radius;
};

