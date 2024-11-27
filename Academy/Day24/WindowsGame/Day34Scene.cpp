#include "pch.h"
#include "Day34Scene.h"
#include "Image.h"
#include "Texture.h"
#include "ProfileUIPanel.h"
void Day34Scene::Init()
{
	Super::Init();

	Texture* texture = Resource->LoadTexture(L"T_Image", L"")
	{
		UI* ui = new Image();
		ui
	}
}

void Day34Scene::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day34Scene::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::S))
	{
		_image->Show();
	}
	if (Input->GetKeyDown(KeyCode::D))
	{
		_image->Hide();
	}
}

void Day34Scene::Release()
{
	Super::Release();
}
