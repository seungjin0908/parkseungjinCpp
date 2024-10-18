#include "pch.h"
#include "BoxCollider.h"
#include "GameObject.h"
void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BoxCollider::Update()
{
	Super::Update();
}
void BoxCollider::Release()
{
	Super::Release();
}
bool BoxCollider::CheckCollision(Collider* other)
{
	if (Super::CheckCollision(other) == false)
	{
		return false;
	}

	switch (other)
	{
	default:
		break;
	}
}
