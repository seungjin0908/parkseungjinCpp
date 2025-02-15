﻿#pragma once
class Panel;
class UI
{
public:
	UI(){}
	virtual ~UI() {}

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	virtual void Show();
	virtual void Hide();

public:
	void SetPos(Vector2 pos) { _pos = pos; }
	Vector2 GetPos() { return _pos; }

	void SetSize(Vector2Int size) { _size = size; }
	Vector2Int GetSize() { return _size; }

	void SetParent(Panel* parent) { _parent = parent; }
	Panel* GetParent() { return _parent; }

	bool IsInMouse();

protected:
	Vector2 _pos = {};
	Vector2Int _size = {};
	bool _isShow = true;
	Panel* _parent = nullptr;
};