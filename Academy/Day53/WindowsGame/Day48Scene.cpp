#include "pch.h"
#include "Day48Scene.h"
#include "GameObject.h"
#include "DXTextRenderer.h"
#include "DXText.h"
#include "DXSpriteRenderer.h"
#include "DXSprite.h"
#include "DXFlipbook.h"
#include "DXFlipbookRenderer.h"

void Day48Scene::Init()
{
	{
		DXTextInfo info;
		info.FontName = L"Arial";
		info.FontSize = 20;
		Resource->CreateDXText(L"TXT_Default", info);
	}

	{
		DXSprite* sprite = Resource->CreateDXSprite(L"S_CharacterDown", L"Day48/SpriteSheet/PlayerDown.png");
		DXFlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Sprite = sprite;

		Resource->CreateDXFlipbook(L"FB_CharacterDown", info);
	}


	Super::Init();

	{
		GameObject* gameObject = new GameObject();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 200, 200));

		{
			DXTextRenderer* textRenderer = new DXTextRenderer();
			textRenderer->SetInfo(Resource->GetDXText(L"TXT_Default"));
			textRenderer->SetText(L"Hello World!");
			gameObject->AddComponent(textRenderer);
		}

		this->SpawnGameObject(gameObject);
	}


	{
		GameObject* gameObject = new GameObject();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 200, 200));

		{
			DXSpriteRenderer* spriteRenderer = new DXSpriteRenderer();
			spriteRenderer->SetSprite(Resource->GetDXSprite(L"S_CharacterDown"));
			gameObject->AddComponent(spriteRenderer);
		}

		this->SpawnGameObject(gameObject);
	}

	{
		GameObject* gameObject = new GameObject();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 200, 200));

		{
			DXFlipbookRenderer* flipbookRenderer = new DXFlipbookRenderer();
			DXFlipbookRendererInfo info;
			info.FlipbookKey = L"FB_CharacterDown";

			flipbookRenderer->SetInfo(info);
			gameObject->AddComponent(flipbookRenderer);
		}

		this->SpawnGameObject(gameObject);
	}

	_cameraPosition = Vector2(100, 100);
}

void Day48Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day48Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}

void Day48Scene::D2DRender()
{
	Super::D2DRender();
}
void Day48Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Left))
	{
		_cameraPosition.x -= 100 * Time->GetDeltaTime();
	}
	if (Input->GetKey(KeyCode::Right))
	{
		_cameraPosition.x += 100 * Time->GetDeltaTime();
	}
	if (Input->GetKey(KeyCode::Up))
	{
		_cameraPosition.y -= 100 * Time->GetDeltaTime();
	}
	if (Input->GetKey(KeyCode::Down))
	{
		_cameraPosition.y += 100 * Time->GetDeltaTime();
	}
}
void Day48Scene::Release()
{
	Super::Release();
}