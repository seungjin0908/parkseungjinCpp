#include "pch.h"
#include "CompletePanel.h"
#include "Image.h"
void CompletePanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Text_Complete", L"Day35/Text_Complete.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Text_Complete", Resource->GetTexture(L"T_Text_Complete"));

	Resource->LoadTexture(L"T_Image_CompleteIcon", L"Day35/Image_CompleteIcon.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Image_CompleteIcon", Resource->GetTexture(L"T_Image_CompleteIcon"));


	{
		Image* image = new Image();
		image->Init();
		image->SetPos({ 0, 150 });
		image->SetSprite(Resource->GetSprite(L"S_Image_CompleteIcon"));
		this->AddChild(image);
	}


	{
		Image* image = new Image();
		image->Init();
		image->SetPos({0, 0});
		image->SetSprite(Resource->GetSprite(L"S_Text_Complete"));
		this->AddChild(image);
	}



}
void CompletePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CompletePanel::Update()
{
	Super::Update();
}
void CompletePanel::Release()
{
	Super::Release();
}