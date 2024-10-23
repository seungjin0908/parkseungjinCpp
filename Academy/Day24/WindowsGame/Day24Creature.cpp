#include "pch.h"
#include "Day24Scene.h"
#include "Day24Creature.h"
#include "BoxRenderer.h"
#include "FlipbookRenderer.h"
#include "Texture.h"
void Day24Creature::Init()
{
	Super::Init();

	this->SetBody()
	{
		BoxRenderer* component = new BoxRenderer();
		component->SetInfo({ DKGRAY_BRUSH });
		this->AddComponent(component);
	}
}

void Day24Creature::Render(HDC hdc)
{
}

void Day24Creature::Update()
{
	Super::Update();
}

void Day24Creature::Release()
{
	Super::Release();
}

void Day24Creature::SetState(Day24CreatureState state)
{
}

void Day24Creature::SetDir(Day24CreatureDir dir)
{
}

void Day24Creature::SetFlipbook()
{
}
