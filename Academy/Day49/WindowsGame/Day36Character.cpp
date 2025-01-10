#include "pch.h"
#include "Day36Character.h"

void Day36Character::Init()
{
	Super::Init();
	_objectId = StaticObjectId++;
}
void Day36Character::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Day36Character::Update()
{
	Super::Update();


	if (Input->GetKeyDown(KeyCode::Z))
	{
		SetHp(GetHp() - 10);
	}
}
void Day36Character::Release()
{
	Super::Release();
}

void Day36Character::SetHp(int hp)
{
	printf("플레이어의 체력이 변했습니다: %d => %d\n", _hp, hp);
	_hp = hp;
	
	if (_hp <= 0)
	{
		GET_SINGLE(GameEventManager)->GetEvent<int>(L"CharacterDied")->Invoke(_objectId);
	}
}