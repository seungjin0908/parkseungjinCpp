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
		info.Offest = { 0, -20 };
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


	SetFlipbook();
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

	wstring newFlipbookName = format(L"FB_character_{0}_{1}", (int)_state, (int)_dir);

	if (newFlipbookName == _currentFilpbookName)
	{
		return;
	}

	_currentFilpbookName = newFlipbookName;
	FlipbookRendererInfo info;
	info = _flipbookRenderer->GetInfo();
	info.FlipbookKey = _currentFilpbookName;
	_flipbookRenderer->SetInfo(info);
}

void Day27Creature::SetPath(vector<Vector2> paths)
{
	_paths = paths;
	_pathIndex = 0;
}

void Day27Creature::Update_Idle()
{
	if (_pathIndex < _paths.size())
	{
		_state = Day27CreatureState::Move;
		return;
	}


}

void Day27Creature::Update_Move()
{
	if (_pathIndex == _paths.size())
	{
		_state = Day27CreatureState::Idle;
		return;
	}

	//1. 목적지에 다왔는지 체크한다
	//2. 목적지에 다왔으면 _pathIndex를 하나 증가시킨다.
	//3. 목적지에 다 못왔으면
	//4. 다음 이동경로에 대한 dir을 구하고
	//5. 캐릭터를 해당방향 이미지로 변경시키고
	//6. 캐릭터를 움직인다.

	if (HasReachedDest())
	{
		printf("도착지 옴 다음 인덱스로 이동 [%d]\n", _pathIndex);
		_pathIndex++;
	}
	else
	{
		Vector2 dest = _paths[_pathIndex];
		Vector2 dir = dest - this->GetPos();
		dir = dir.Normalize();

		Vector2 v1 = Vector2::Up();
		Vector2 v2 = dir.Normalize();
		float angle = Vector2::SignedAngle(v1, v2);
		if (angle < 0)
		{
			angle += 360;
		}

		//위쪽 계산
		if (315 <= angle || angle < 45)
		{
			_dir = Day27CreatureDir::Up;
		}
		else if (45 <= angle && angle < 135)
		{
			_dir = Day27CreatureDir::Right;
		}
		else if (135 <= angle && angle < 225)
		{
			_dir = Day27CreatureDir::Down;
		}
		else if (225 <= angle && angle < 315)
		{
			_dir = Day27CreatureDir::Left;
		}


		this->SetPos(this->GetPos() + dir * _speed * Time->GetDeltaTime());

	}


}

bool Day27Creature::HasReachedDest()
{
	if (_pathIndex == _paths.size())
		return true;

	Vector2 dest = _paths[_pathIndex];

	// (도착지 - 내지점)거리의 제곱 < 8픽셀이하 라면
	if ((dest - this->GetPos()).LengthSqrt() < 8.0f)
	{
		return true;
	}

	return false;
}