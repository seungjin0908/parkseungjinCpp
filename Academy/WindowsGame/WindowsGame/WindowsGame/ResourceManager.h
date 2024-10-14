#pragma once
class ResourceBase;
class Texture;
class Sprite;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);
public:
	void Init();
	void Release();

public:
	Texture* LoadTexure(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));
	Texture* GetTexture(const wstring& key);

	Sprite* CreateSprite(const wstring& key, Texture* texture, int x = 0, int cx = 0, int cy = 0);
	Sprite* GetSprite(const wstring& key);

private:
	wstring _resourcePath;

	map<wstring, ResourceBase*>_resources = {};
};

#define Resource GET_SINGLE(ResourceManager)

