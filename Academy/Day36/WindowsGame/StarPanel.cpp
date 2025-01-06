#include "pch.h"
#include "StarPanel.h"
#include "Image.h"
void StarPanel::Init()
{
	Resource->LoadTexture(L"T_Image_Star_Fill", L"Day35/Image_Star_Fill.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Image_Star_Fill", Resource->GetTexture(L"T_Image_Star_Fill"));

	Resource->LoadTexture(L"T_Image_Star_Empty", L"Day35/Image_Star_Empty.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Image_Star_Empty", Resource->GetTexture(L"T_Image_Star_Empty"));


	Super::Init();

	Vector2 starPos = { -67, 0 };
	{
		Image* image = new Image();
		image->Init();
		image->SetPos(starPos);
		image->SetSprite(Resource->GetSprite(L"S_Image_Star_Fill"));
		this->AddChild(image);
	}
	starPos.x += 67;

	{
		Image* image = new Image();
		image->Init();
		image->SetPos(starPos);
		image->SetSprite(Resource->GetSprite(L"S_Image_Star_Empty"));
		this->AddChild(image);
	}
	starPos.x += 67;

	{
		Image* image = new Image();
		image->Init();
		image->SetPos(starPos);
		image->SetSprite(Resource->GetSprite(L"S_Image_Star_Empty"));
		this->AddChild(image);
	}

}
void StarPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void StarPanel::Update()
{
	Super::Update();
}
void StarPanel::Release()
{
	Super::Release();
}