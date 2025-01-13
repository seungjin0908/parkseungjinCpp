﻿#include "pch.h"
#include "GameResultCardPanel.h"
#include "ButtonPanel.h"
#include "ScorePanel.h"
#include "CompletePanel.h"
#include "StarPanel.h"
void GameResultCardPanel::Init()
{
	Super::Init();

	{
		ButtonPanel* panel = new ButtonPanel();
		panel->Init();
		panel->SetPos({ WIN_SIZE_X / 2, 650 });
		this->AddChild(panel);
	}
	{
		ScorePanel* panel = new ScorePanel();
		panel->Init();
		panel->SetPos({ WIN_SIZE_X / 2, 500 });
		this->AddChild(panel);
	}
	{
		CompletePanel* panel = new CompletePanel();
		panel->Init();
		panel->SetPos({ WIN_SIZE_X / 2, 200 });
		this->AddChild(panel);
	}
	{
		StarPanel* panel = new StarPanel();
		panel->Init();
		panel->SetPos({ WIN_SIZE_X/2, 100 });
		this->AddChild(panel);
	}

}
void GameResultCardPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void GameResultCardPanel::Update()
{
	Super::Update();
}
void GameResultCardPanel::Release()
{
	Super::Release();
}