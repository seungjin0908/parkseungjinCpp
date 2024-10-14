#pragma once
#include "Scene.h"

class Texture;
class Sprite;
class Day19Stone;

enum class Day19State
{
	BlackTurn,
	WhiteTurn,
	None
};

enum class Day19ErrorCode
{
	ERR_ALREADY_STONE_POS
};

class Day19Scene : public Scene
{
	DELARE_CHILD(Day19Scene, Scene);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void Update_BlackTurn();
	void Update_WhiteTurn();

	bool MakeStoneWithMousePos(int type);

private:
	Texture* _backgroundTex = nullptr;
	Sprite* _background = nullptr;

	Day19Stone* _board[15][15];

	Vector2 _boardStartPos = { 24,20 };
	Vector2 _board = { 38.1f,38.1f };
};

