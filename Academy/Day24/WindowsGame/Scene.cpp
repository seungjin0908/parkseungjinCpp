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
			int size = _gameObjects[layer].size();
			for (int i = 0; i < size; i++)
			{
				GameObject* gameObject = _gameObjects[layer][i];
				if (gameObject == nullptr) continue;
				gameObject->Render(hdc);
			}
		}
	}

	//for (GameObject* gameObject : _gameObjects)
	//{
	//	if (gameObject == nullptr) continue;
	//	gameObject->Render(hdc);
	//}

	{
		for (UI* ui : _uis)
		{
			ui->Render(hdc);
		}
	}
}
void Scene::Update()
{
	{
		for (int layer = 0; layer < static_cast<int>(LayerType::End); layer++)
		{
			int size = _gameObjects[layer].size();
			for (int i = 0; i < size; i++)
			{
				GameObject* gameObject = _gameObjects[layer][i];
				if (gameObject == nullptr) continue;
				gameObject->Update();
			}
		}
	}
	//for (GameObject* gameObject : _gameObjects)
	//{
	//	if (gameObject == nullptr) continue;
	//	gameObject->Update();
	//}


	{
		for (UI* ui : _uis)
		{
			ui->Update();
		}
	}

	while (false == _despawnObjectList.empty())
	{
		GameObject* deleteGameObject = _despawnObjectList.front();
		_despawnObjectList.pop();

		int layerType = deleteGameObject->GetLayerTypeInt();

		auto findIt = find(_gameObjects[layerType].begin(), _gameObjects[layerType].end(), deleteGameObject);

		if (findIt != _gameObjects[layerType].end())
		{
			deleteGameObject->Release();
			SAFE_DELETE(deleteGameObject);
			_gameObjects[layerType].erase(findIt);
		}
	}
}
void Scene::Release()
{
	for (vector<GameObject*>& gameobjects : _gameObjects)
	{
		for (GameObject* gameObject : gameobjects)
		{
			gameObject->Release();
			SAFE_DELETE(gameObject);
		}
		gameobjects.clear();
	}

	{
		for (UI* ui : _uis)
		{
			ui->Release();
			SAFE_DELETE(ui);
		}
		_uis.clear();
	}
}

void Scene::SpawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	_gameObjects[gameObject->GetLayerTypeInt()].push_back(gameObject);
}
void Scene::DespawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	_despawnObjectList.push(gameObject);
}

GameObject* Scene::FindGameObject(string name)
{

	for (vector<GameObject*>& gameobjects : _gameObjects)
	{
		for (GameObject* gameObject : gameobjects)
		{
			if (gameObject->GetName() == name)
			{
				return gameObject;
			}
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
		UI* deleteUI = (*findIt);
		SAFE_DELETE(deleteUI);
		_uis.erase(findIt);
	}
}