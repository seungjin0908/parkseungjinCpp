#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	Super::Init();
	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Collider::Update()
{
	Super::Update();
}
void Collider::Release()
{
	Super::Release();
	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}

bool Collider::CheckCollision(Collider* other)
{
	uint32 myFlag = this->_collisionFlag;
	uint8 otherLayer = other->GetCollisionLayer();

	uint32 checkOtherFlag = 1 << otherLayer;

	if (0 < (myFlag & checkOtherFlag))
	{
		uint32 checkMyFlag = 1 << this->GetCollisionLayer();
		if (0 < (other->GetCollisionFlag() & checkMyFlag))
		{
			return true;
		}
	}

	return false;
	
}
