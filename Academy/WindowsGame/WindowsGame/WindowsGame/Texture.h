﻿#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{	
	DELARE_CHILD(Texture, ResourceBase);
protected:
	HDC _hdc = {};
	HBITMAP _bitmap = {};
	Vector2Int _size = {};
	uint32 _transparent = RGB(255, 0, 255);

public:
	Texture* LoadBmp(const wstring& path);
	void SetSize(Vector2Int size);

	void SetTransparent(uint32 transparent) { _transparent };
	uint32 GetTransparent() {return _transparent;}
	
};

