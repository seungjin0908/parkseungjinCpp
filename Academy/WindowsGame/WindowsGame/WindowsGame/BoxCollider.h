#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
	DELARE_CHILD(BoxCollider, Collider);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	virtual bool CheckCollision(Collider* other);

public:
	void SetCollision(CenterRect collision) { _collision = collision; }
	CenterRect GetCollision();

private:
	CenterRect _collision;
};

