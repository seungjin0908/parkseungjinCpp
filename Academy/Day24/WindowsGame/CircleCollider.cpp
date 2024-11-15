#include "pch.h"
#include "CircleCollider.h"

void CircleCollider::Init()
{
	Super::Init();
}

void CircleCollider::Render(HDC hdc)
{
	Super::Render(hdc);
}

void CircleCollider::Update()
{
	Super::Update();
}

void CircleCollider::Release()
{
	Super::Release();
}

bool CircleCollider::CheckCollision(Collider* other)
{
	return false;
}

Vector2 CircleCollider::GetCollisionPos()
{
	Vector2 pos = this->_pos + this->_owner->GetPos();

	return pos;
}

CircleCollider::CircleCollider()
{
}