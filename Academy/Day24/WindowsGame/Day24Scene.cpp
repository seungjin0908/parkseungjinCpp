#include "pch.h"
#include "Day24Scene.h"
#include "GameObject.h"
#include "BoxRenderer.h"
#include "SpriteRenderer.h"
void Day24Scene::Init()
{
	Super::Init();
	{
		Texture* texture = Resource->LoadTexture(L"T_Ball", L"Day24/playerDown.bmp");
		Resource->CreateSprite(L"S_Ball", texture,0,0,200,200);
	}

	{
		GameObject* gameObject = new GameObject();
		CenterRect rect = CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 100);
		gameObject->SetBody(rect);
		{
			SpriteRenderer* component = new SpriteRenderer();
			SpriteRendererInfo info;
			info.SpriteKey = L"S_Ball";
			component->SetInfo(info);

			gameObject->AddComponent(component);
		}
		_gameObject = gameObject;
		this->SpawnGameObject(gameObject);
	}
}
void Day24Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day24Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day24Scene::Update()
{
	Super::Update();

	

	if (Input->GetKey(KeyCode::W))
	{
		//this->_body.pos += dir * _speed * Time->GetDeltaTime();
		//this->_body.pos = this->_body.pos + dir * _speed * Time->GetDeltaTime();
		
		int a;
		a = 5;
		Vector2 dir;
		dir = Vector2(0, -1);
		_gameObject->SetPos(_gameObject->GetPos() + dir * 100 * Time->GetDeltaTime()); //위쪽방향


	}

	if (Input->GetKey(KeyCode::S))
	{
		Vector2 dir;
		dir = Vector2(0,1);
		_gameObject->SetPos(_gameObject->GetPos() + dir * 100 * Time->GetDeltaTime()); //아래방향
	}

	if (Input->GetKey(KeyCode::D))
	{
		Vector2 dir;
		dir = Vector2(1, 0);
		_gameObject->SetPos(_gameObject->GetPos() + dir * 100 * Time->GetDeltaTime()); // 오른쪽방향
	}

	if (Input->GetKey(KeyCode::A))
	{
		Vector2 dir;
		dir = Vector2(-1, 0);
		_gameObject->SetPos(_gameObject->GetPos() + dir * 100 * Time->GetDeltaTime()); // 왼쪽방향
	}

}
void Day24Scene::Release()
{
	Super::Release();
}