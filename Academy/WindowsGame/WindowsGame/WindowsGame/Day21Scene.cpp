#include "pch.h"
#include "Day21Scene.h"
#include "Day21Pannel.h"
#include "Texture.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
void Day21Scene::Init()
{
	Super::Init();

	{
		Texture* texture = Resource->LoadTexure(L"T_Paddle" L"Day21/paddle");
		Resource->CreateSprite(L"S_Paddle", texture);
	}

	{
		Day21Pannel* gameObject = new Day21Pannel();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 150, 200, 50));
		{
			SpriteRenderer* component = new SpriteRenderer();
			SpriteRendererInfo info;
			info.SpriteKey = L"S_Paddle";
			component->SetInfo(info);
			gameObject->AddComponent(component);
		}

		this->SpaqnGameObject(gameObject);
	}
}

void Day21Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	{
		wstring nameStr = ::format(L"Day21Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}

void Day21Scene::Update()
{
	Super::Update();
}

void Day21Scene::Release()
{
	Super::Release();
}
