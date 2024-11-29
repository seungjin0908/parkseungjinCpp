#include "pch.h"
#include "GameResultCardPanel.h"
<<<<<<< HEAD
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
		this->AddChild(panel);
	}
	{
		ScorePanel* panel = new ScorePanel();
		panel->Init();
		this->AddChild(panel);
	}
	{
		CompletePanel* panel = new CompletePanel();
		panel->Init();
		this->AddChild(panel);
	}
	{
		StarPanel* panel = new StarPanel();
		panel->Init();
		panel->SetPos({ WIN_SIZE_X/2, 200 });
		this->AddChild(panel);
	}

=======

void GameResultCardPanel::Init()
{
	Super::Init();
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
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
<<<<<<< HEAD
}
=======
}
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
