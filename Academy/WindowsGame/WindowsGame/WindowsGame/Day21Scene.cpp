﻿#include "pch.h"
#include "Day21Scene.h"
#include "Day21Paddle.h"
#include "Texture.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "Day21Ball.h"
void Day21Scene::Init()
{
	Super::Init();

	{
		Texture* texture = Resource->LoadTexture(L"T_Paddle", L"Day21/paddle.bmp");
		Resource->CreateSprite(L"S_Paddle", texture);
	}
	{
		Texture* texture = Resource->LoadTexture(L"T_Ball", L"Day21/ball.bmp");
		Resource->CreateSprite(L"S_Ball", texture);
	}


	{
		Day21Paddle* gameObject = new Day21Paddle();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 150, 172, 45));
		{
			SpriteRenderer* component = new SpriteRenderer();
			SpriteRendererInfo info;
			info.SpriteKey = L"S_Paddle";
			component->SetInfo(info);
			gameObject->AddComponent(component);
		}
		_paddle = gameObject;
		this->SpawnGameObject(gameObject);
	}

	{
		Day21Ball* gameObject = new Day21Ball();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 40, 40));
		{
			SpriteRenderer* component = new SpriteRenderer();
			SpriteRendererInfo info;
			info.SpriteKey = L"S_Ball";
			component->SetInfo(info);
			gameObject->AddComponent(component);
		}

		_ball = gameObject;

		this->SpawnGameObject(gameObject);
	}

}
void Day21Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day21Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day21Scene::Update()
{
	Super::Update();


	if (Input->GetKeyDown(KeyCode::J))
	{
		printf(_ball->ToString().c_str());
	}
}
void Day21Scene::Release()
{
	Super::Release();
}