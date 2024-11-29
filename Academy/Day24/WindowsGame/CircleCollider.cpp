#include "pch.h"
#include "CircleCollider.h"
#include "BoxCollider.h"
#include "GameObject.h"
#include "Scene.h"
void CircleCollider::Init()
{
	Super::Init();
}
void CircleCollider::Render(HDC hdc)
{
	Super::Render(hdc);

#ifdef _DEBUG
	Vector2 cameraPos = CurrentScene->GetCameraPos();

	CenterRect drawRect;
	drawRect.pos = this->GetCollisionPos();
	drawRect.width = this->GetRadius() * 2;
	drawRect.height = this->GetRadius() * 2;
	drawRect.pos -= cameraPos;
	drawRect.Draw(hdc, DRAWTYPE_ELIPSE);
#endif
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

		Vector2 circlePos1 = this->GetCollisionPos();
		float circleRadius1 = this->GetRadius();

		Vector2 circlePos2 = otherCollider->GetCollisionPos();
		float circleRadius2 = otherCollider->GetRadius();

		return Collision::CircleInCircle(circlePos1, circleRadius1, circlePos2, circleRadius2);
	}
	break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();

		Vector2 circlePos1 = this->GetCollisionPos();
		float circleRadius1 = this->GetRadius();

		return Collision::RectInCircle(otherCollider->GetCollision(), circlePos1, circleRadius1);
	}
	break;
	default:
		return false;
		break;
	}

	return false;
}


Vector2 CircleCollider::GetCollisionPos()
{
	Vector2 pos = this->_pos + this->_owner->GetPos();

	return pos;
}

CircleCollider::CircleCollider() : Collider(ColliderType::Box)
{

}