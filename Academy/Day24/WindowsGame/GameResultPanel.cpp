﻿#include "pch.h"
#include "GameResultPanel.h"
#include "Image.h"
<<<<<<< HEAD
#include "GameResultCardPanel.h"
=======
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
void GameResultPanel::Init()
{
	Super::Init();

<<<<<<< HEAD
	Resource->LoadTexture(L"T_Image_Background", L"Day35/Image_Background.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Image_Background", Resource->GetTexture(L"T_Image_Background"));

	this->SetSize({ WIN_SIZE_X, WIN_SIZE_Y });

	{
		Image * image = new Image();
		image->Init();
		image->SetPos({ WIN_SIZE_X / 2 , WIN_SIZE_Y / 2});
		image->SetSprite(Resource->GetSprite(L"S_Image_Background"));
		this->AddChild(image);
	}

	{
		GameResultCardPanel* panel = new GameResultCardPanel();
		panel->Init();
		this->AddChild(panel);
	}

=======
	Resource->LoadTexture(L"T_Image_Background",L"Day35/Image_")
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
}
void GameResultPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void GameResultPanel::Update()
{
	Super::Update();
}
void GameResultPanel::Release()
{
	Super::Release();
<<<<<<< HEAD
}
=======
}
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
