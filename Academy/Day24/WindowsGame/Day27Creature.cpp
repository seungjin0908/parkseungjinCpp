#include "pch.h"
#include "Day27Creature.h"
#include "BoxRenderer.h"
#include "FlipbookRenderer.h"
#include "Texture.h"
#include "Scene.h"
void Day27Creature::Init()
{
	Texture* textureDown = Resource->LoadTexture(L"T_PlayerDown", L"Day24/PlayerDown.bmp", RGB(128, 128, 128));
	Texture* textureUp = Resource->LoadTexture(L"T_PlayerUp", L"Day24/PlayerUp.bmp", RGB(128, 128, 128));
	Texture* textureLeft = Resource->LoadTexture(L"T_PlayerLeft", L"Day24/PlayerLeft.bmp", RGB(128, 128, 128));
	Texture* textureRight = Resource->LoadTexture(L"T_PlayerRight", L"Day24/PlayerRight.bmp", RGB(128, 128, 128));

	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_0_3", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_1_3", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_2_3", info);
	}

	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_0_0", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_1_0", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_2_0", info);
	}


	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_0_1", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_1_1", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_2_1", info);
	}


	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_0_2", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_1_2", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_2_2", info);
	}



	this->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 100));
	{
		FlipbookRenderer* component = new FlipbookRenderer();
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_0_3";
		component->SetInfo(info);
		this->AddComponent(component);
		_flipbookRenderer = component;
	}

	this->SetFlipbook();


	Super::Init();
}

void Day27Creature::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day27Creature::Update()
{
	Super::Update();
	switch (_state)
	{
	case Day27CreatureState::Idle:
		Update_Idle();
		break;
	case Day27CreatureState::Move:
		Update_Move();
		break;
	default:
		break;
	}
}

void Day27Creature::Release()
{
	Super::Release();
}

void Day27Creature::SetFlipbook()
{
	if (_flipbookRenderer == nullptr)
	{
		return;
	}

	FlipbookRendererInfo info;
	info.FlipbookKey = format(L"FB_character_{0}_{1}", (int)_state, (int)_dir);
	_flipbookRenderer->SetInfo(info);


	if (HasReachedDest())
	{
		_pathIndex++;
	}
	else
	{
		Vector2 dest = _paths[_pathIndex];
		Vector2 dir = dest - this->GetPos();
		
	}
}

void Day27Creature::SetPath(vector<Vector2Int> paths)
{

}

void Day27Creature::Update_Idle()
{

}

void Day27Creature::Update_Move()
{

}

bool Day27Creature::HasReachedDest()
{
	if (_pathIndex == _paths.size())
	{
		return true;
	}

	Vector2 dest = _paths[_pathIndex];

	// (도착지 - 내지점)거리의 제곱 < 8픽셀이하 라면
	if ((dest - this->GetPos()).LengthSqrt() < 8.0f)
	{

	}

	return false;
}


