#include "pch.h"
#include "Day24Bullet.h"
#include "BoxRenderer.h"
void Day24Bullet::Init()
{
	Super::Init();

	this->SetBody(CenterRect(0, 0, 30, 30));
	{
		BoxRenderer* component = new BoxRenderer();
		component->SetInfo({ DKGRAY_BRUSH });
		this->AddComponent(component);
	}
}

void Day24Bullet::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day24Bullet::Update()
{
	Super::Update();

	switch (_state)
	{
	case EDay24BulletState::None:
		break;
	case EDay24BulletState::Move:
		break;
	case EDay24BulletState::Fire:
		break;
	default:
		break;
	}
}

void Day24Bullet::Release()
{
}

void Day24Bullet::Update_Move()
{
}

void Day24Bullet::Update_Fire()
{
}

void Day24Bullet::SetState(EDay24BulletState state)
{
}
