#include "pch.h"
#include "ProfileUIPanel.h"
#include "ProfileAreaPanel.h"
#include "Image.h"
void ProfileUIPanel::Init()
{
	Super::Init();
	Resource->LoadTexture(L"T_ImageText", L"Day34/Image_Text.bmp", RGB(255, 255, 255));
	Resource->CreateSprite(L"S_ImageText",Resource->GetTexture(L"T_ImageText"));

	this->SetSize({ 250,250 });

	{
		_profileAreaPanel = new ProfileAreaPanel();
		_profileAreaPanel->Init();
		this->AddChild(_profileAreaPanel);
	}

	{
		_nameImage = new Image();
		_nameImage->Init();
		_nameImage->SetSprite();
		this->AddChild(_nameImage);
	}
}
void ProfileUIPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ProfileUIPanel::Update()
{
	Super::Update();
}
void ProfileUIPanel::Release()
{
	Super::Release();
}
