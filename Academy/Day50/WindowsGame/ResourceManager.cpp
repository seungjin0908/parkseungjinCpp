﻿#include "pch.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"
#include "ResourceBase.h"
#include "Flipbook.h"
#include "Tilemap.h"
#include "Sound.h"
#include "DXText.h"
void ResourceManager::Init()
{
	_resources.clear();
	_resourcePath = L"../Resources/";
}

void ResourceManager::Release()
{
	for (auto& item : _resources)
	{
		//item.first => 키값 (wstring)
		//item.second => 본체 (ResourceBase*)
		SAFE_DELETE(item.second);
	}
	_resources.clear();
}

Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path, uint32 transparent)
{
	if (_resources.contains(key))
	{
		return GetTexture(key);
	}

	wstring fullPath = _resourcePath + path;
	Texture* texture = new Texture();
	texture->LoadBmp(fullPath);
	texture->SetTransparent(transparent);

	_resources[key] = texture;

	return texture;
}

Texture* ResourceManager::GetTexture(const wstring& key)
{
	return dynamic_cast<Texture*>(_resources[key]);
}

Sprite* ResourceManager::CreateSprite(const wstring& key, Texture* texture, int x, int y, int cx, int cy)
{
	if (_resources.contains(key))
	{
		return GetSprite(key);
	}

	// Default 값이 들어오면 전체 사이즈를 말하는것.
	if (cx == 0)
	{
		cx = texture->GetSize().x;
	}

	if (cy == 0)
	{
		cy = texture->GetSize().y;
	}

	Sprite* sprite = new Sprite(texture, x, y , cx, cy);
	_resources[key] = sprite;

	return sprite;
}
Sprite* ResourceManager::GetSprite(const wstring& key)
{
	return dynamic_cast<Sprite*>(_resources[key]);
}


Flipbook* ResourceManager::CreateFlipbook(const wstring& key, FlipbookInfo info)
{
	if (_resources.contains(key))
	{
		return GetFlipbook(key);
	}

	Flipbook* flipbook = new Flipbook();
	flipbook->SetInfo(info);
	_resources[key] = flipbook;
	return flipbook;
}
Flipbook* ResourceManager::GetFlipbook(const wstring& key)
{
	return dynamic_cast<Flipbook*>(_resources[key]);
}

Tilemap* ResourceManager::LoadTilemap(const wstring& key, const wstring& path, vector<Sprite*> sprites)
{
	if (_resources.contains(key))
	{
		return GetTilemap(key);
	}

	wstring fullPath = _resourcePath + path;
	Tilemap* tilemap = new Tilemap();
	tilemap->LoadFile(fullPath);
	tilemap->SetSprites(sprites);
	_resources[key] = tilemap;

	return tilemap;
}
Tilemap* ResourceManager::GetTilemap(const wstring& key)
{
	return dynamic_cast<Tilemap*>(_resources[key]);
}


Sound* ResourceManager::LoadSound(const wstring& key, const wstring& path)
{
	if (_resources.contains(key))
	{
		return GetSound(key);
	}

	wstring fullPath = _resourcePath + path;
	Sound* sound = new Sound();
	sound->LoadWave(fullPath);
	_resources[key] = sound;
	return sound;
}

Sound* ResourceManager::GetSound(const wstring& key)
{
	return dynamic_cast<Sound*>(_resources[key]);
}


DXText* ResourceManager::CreateDXText(const wstring& key, DXTextInfo info)
{
	if (_resources.contains(key))
	{
		return GetDXText(key);
	}

	DXText* dxText = new DXText();
	dxText->SetInfo(info);
	_resources[key] = dxText;

	return dxText;
}
DXText* ResourceManager::GetDXText(const wstring& key)
{
	return dynamic_cast<DXText*>(_resources[key]);
}