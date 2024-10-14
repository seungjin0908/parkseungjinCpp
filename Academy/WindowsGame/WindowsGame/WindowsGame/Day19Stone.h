#pragma once
class Day19Stone
{
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
public:
	void SetInfo(Vector2Int pos, int type);
private:
	Vector2Int _pos = {};
	int _type = 0;
	Texture* _texture = nullptr;
	Sprite* _sprite = nullptr;
};

