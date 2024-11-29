#include "pch.h"
#include "ProfileAreaPanel.h"
#include "Image.h"
void ProfileAreaPanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_ProfileImage", L"Day34/Image_Profile.bmp", RGB(255, 255, 255));
	Resource->CreateSprite(L"S_ProfileImage", Resource->GetTexture(L"T_ProfileImage"));
	Resource->LoadTexture(L"T_PlusImage", L"Day34/Image_Plus.bmp", RGB(255, 255, 255));
	Resource->CreateSprite(L"S_PlusImage", Resource->GetTexture(L"T_PlusImage"));


	{
		_profileImage = new Image();
		_profileImage->Init();
		_profileImage->SetSprite(Resource->GetSprite(L"S_ProfileImage"));
		this->AddChild(_profileImage);
	}

	{
		_plusImage = new Image();
		_plusImage->Init();
		_plusImage->SetSprite(Resource->GetSprite(L"S_PlusImage"));
		_plusImage->SetPos({ 70, 80 });
		this->AddChild(_plusImage);
	}
}
void ProfileAreaPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ProfileAreaPanel::Update()
{
	Super::Update();
}
void ProfileAreaPanel::Release()
{
	Super::Release();
}