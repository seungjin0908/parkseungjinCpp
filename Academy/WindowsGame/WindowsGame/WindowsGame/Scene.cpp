#include "pch.h"
#include "Scene.h"
#include "Day17Player.h"
#include "Day17Box.h"

void Scene::Init()
{
	_player = new Day17Player();
	_player->Init();

	_box = new Day17Box();
	_box->Init();


	_player->SetLinkBox(_box);
	// 2가지방법
	// 1. Player에서 Box를 가져와서 
	//    Box를 미는 방식

	// 2. Box에서 Player를 가져와서
	//    밀리는 방식
}
void Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"CurrentScene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
	_player->Render(hdc);
	_box->Render(hdc);
}
void Scene::Update()
{
	_player->Update();
	_box->Update();
}
void Scene::Release()
{

}