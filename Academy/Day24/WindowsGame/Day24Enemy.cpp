#include "pch.h"
#include "Day24Enemy.h"
#include "BoxRenderer.h"
#include "BoxCollider.h"
#include "Day24Bullet.h"
#include "Scene.h"
void Day24Enemy::Init()
{
	Super::Init();

	Vector2 pos = this->GetPos();

	{
		BoxRenderer* component = new BoxRenderer();
		BoxRendererInfo info;
		info.Brush = GRAY_BRUSH;
		component->SetInfo(info);
		this->AddComponent(component);
	}
}

void Day24Enemy::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day24Enemy::Update()
{
	Super::Update();
	switch (_state)
	{
	case EDay24EnemyState::Idle:
		Update_Idle();
		break;
	case EDay24EnemyState::Dead:
		Update_Dead();
		break;
	default:
		break;
	}
}

void Day24Enemy::Release()
{
	Super::Release();
}

void Day24Enemy::Update_Idle()
{
}

void Day24Enemy::Update_Dead()
{
}

void Day24Enemy::SetState(EDay24EnemyState state)
{
	if (_state == state)
		return;

		_state = state;
	
}

void Day24Enemy::OnTriggerEnter(Collider* collider, Collider* other)
{
	GameObject* otherOwner = other->GetOwner();

	Day24Bullet* otherBullet = dynamic_cast<Day24Bullet*>(otherOwner);
	if (otherBullet != nullptr)
	{
		this->OnDamaged(otherBullet);

		CurrentScene->DespawnGameObject()
	}
}

void Day24Enemy::OnDamaged(Day24Bullet* bullet)
{
	_info.Hp--;

	if (_info.Hp <= 0)
	{

	}
}
