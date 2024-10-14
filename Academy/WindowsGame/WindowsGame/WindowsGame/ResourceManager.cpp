#include "pch.h"
#include "ResourceManager.h"

void ResourceManager::Init()
{
	_resources.clear();
	_resourcePath = L"../Resources/";
}

void ResourceManager::Release()
{
	for (auto& item : _resources)
	{
		SAFE_DELETE(item.second);
	}
	_resources.clear();
}

Texture* ResourceManager::LoadTexure(const wstring& key, const wstring& path, uint32 transparent)
{
	if (_resources.contains(key))
	{
		return GetTexture(key);
	}

	wstring fullPath = _resourcePath + path;
	Texture* texture = new Texture();
	texture->LoadBmp(fullPath);

	return texture;
}

Texture* ResourceManager::GetTexture(const wstring& key)
{
	return dynamic_cast<Texture*>(_resources[key]);
}

Sprite* ResourceManager::CreateSprite(const wstring& key, Texture* texture, int x, int cx, int cy)
{
	if (_resources.contains(key))
	{
		return GetSprite(key);
	}

	if (cy == 0)
	{
		
	}
}

Sprite* ResourceManager::GetSprite(const wstring& key)
{
	return dynamic_cast<Sprite*>(_resources[key]);
}
