#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
#include "UI.h"
void Scene::Init()
{
	for (UI* ui : _uis)
	{
		ui->Init();
	}
}
void Scene::Render(HDC hdc)
{
	{
		for (int layer = 0; layer < static_cast<int>(LayerType::End); layer++)
		{
			
		}
	}

	/*for (GameObject* gameObject : _gameObjects)
	{
		if (gameObject == nullptr) continue;
		gameObject->Render(hdc);
	}*/
}
void Scene::Update()
{
	for (GameObject* gameObject : _gameObjects)
	{
		if (gameObject == nullptr) continue;
		gameObject->Update();
	}

	while (false == _despawnObjectList.empty())
	{
		GameObject* deleteGameObject = _despawnObjectList.front();
		_despawnObjectList.pop();

		auto findIt = find(_gameObjects.begin(), _gameObjects.end(), deleteGameObject);

		if (findIt != _gameObjects.end())
		{
			deleteGameObject->Release();
			SAFE_DELETE(deleteGameObject);
			_gameObjects.erase(findIt);
		}
	}
}
void Scene::Release()
{
	for (GameObject* gameObject : _gameObjects)
	{
		gameObject->Release();
		SAFE_DELETE(gameObject);
	}
	_gameObjects.clear();
}

void Scene::SpawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	_gameObjects.push_back(gameObject);
}
void Scene::DespawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	_despawnObjectList.push(gameObject);
}

GameObject* Scene::FindGameObject(string name)
{
	for (GameObject* gameObject : _gameObjects)
	{
		if (gameObject->GetName() == name)
		{
			return gameObject;
		}
	}

	return nullptr;
}

void Scene::AddUI(UI* ui)
{
	this->_uis.push_back(ui);
}
void Scene::RemoveUI(UI* ui)
{
	auto findIt = find(_uis.begin(), _uis.end(), ui);

	if (findIt != _uis.end())
	{
		(*findIt)->Release();
		UI* deleteUI - (*findIt);
		SAFE_DELETE(delegateUI);
		_uis.erase(findIt);
	}
}
