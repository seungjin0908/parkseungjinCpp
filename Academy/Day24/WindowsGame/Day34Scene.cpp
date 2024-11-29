#include "pch.h"
#include "Day34Scene.h"
#include "Image.h"
#include "Texture.h"
#include "ProfileUIPanel.h"
void Day34Scene::Init()
{

	Texture* texture = Resource->LoadTexture(L"T_Image", L"Day34/image.bmp");
	Resource->CreateSprite(L"S_Image", texture);


	/*{
		Image* ui = new Image();
		ui->SetSprite(Resource->GetSprite(L"S_Image"));
		ui->SetPos({ WIN_SIZE_X / 2 , WIN_SIZE_Y / 2 });
		this->AddUI(ui);
		_image = ui;
	}*/

	{
		ProfileUIPanel* ui = new ProfileUIPanel();
		ui->SetPos({ 100 , WIN_SIZE_Y / 2 });
		this->AddUI(ui);
	}
	Super::Init();
}
void Day34Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day34Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
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