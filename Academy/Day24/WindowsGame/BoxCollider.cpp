﻿#include "pch.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "GameObject.h"
#include "Scene.h"
void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

#ifdef _DEBUG
	CenterRect drawRect = this->GetCollision();
	Vector2 cameraPos = CurrentScene->GetCameraPos();
	
	drawRect.pos -= cameraPos;
	drawRect.Draw(hdc);
#endif
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
	// 부모의 CheckCollision =>  flag검사
	if (Super::CheckCollision(other) == false)
	{
		return false;
	}

	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
	{
		CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
		CenterRect myCollision = this->GetCollision();

		Vector2 circlePos1 = otherCollider->GetCollisionPos();
		float circleRadius1 = otherCollider->GetRadius();

		return Collision::RectInCircle(myCollision, circlePos1, circleRadius1);
	}
		break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();

		return Collision::RectInRect(this->GetCollision(), otherCollision);
	}
		break;
	default:
		return false;
		break;
	}

	return false;
}
CenterRect BoxCollider::GetCollision()
{
	// 실제 GameObject 기준으로 Collision을 찾아줘야한다.
	CenterRect rect;
	rect.pos.x = this->GetOwner()->GetPos().x + this->_collision.pos.x;
	rect.pos.y = this->GetOwner()->GetPos().y + this->_collision.pos.y;
	rect.width = this->_collision.width;
	rect.height = this->_collision.height;

	return rect;
}

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{

}