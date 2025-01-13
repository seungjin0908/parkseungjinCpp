﻿#include "pch.h"
#include "Day48Scene.h"
#include "GameObject.h"
#include "DXTextRenderer.h"
#include "DXText.h"

void Day48Scene::Init()
{
	{
		DXTextInfo info;
		info.FontName = L"Arial";
		info.FontSize = 20;
		Resource->CreateDXText(L"TXT_Default", info);
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

	//실습 : 구구단 만들기
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
}
void Day48Scene::Release()
{
	Super::Release();
}