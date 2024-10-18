#pragma once
#include "Component.h"
class Collider : public Component
{
	DELARE_CHILD(Collider, Component);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	virtual bool CheckCollision(Collider* other) { return false; }

public:
	Collider(ColliderType type) { _colliderType = type; }

public:
	CollisionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollisionLayerType collisionLayerType) { _collisionLayer = _collisionLayer; }

	uint32 GetCollisionFlag() { return _collisionFlag; }

	void SetCollisonFlag(uint32){_collisionFlag}
protected:
	ColliderType _colliderType = ColliderType::None;
	// 내 CollisionLayer
	ColliderType _collisionLayer = CLT_DEFAULT;

	// 내가 충돌할 CollisionLayerType은 무엇인지
	uint8 _collisionFlag = ~0;

public:
	// 현재 충돌중인 Collider 모음집
	unordered_set<Collider*> _collisionMap;
	//unordered_set => Map이라고 생각하면됨.
};

