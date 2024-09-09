#pragma once
class Player
{
public:
	int _card[2] = {};
	int _gold;

public:
	int GetJokboValue()
	{
		return ((_card[0] + 1) + (_card[1] + 1)) % 10;
	}
};

class MainGame
{
public:
	void Init();
	void Run();
	void Release();

public:
	// 화투카드 정의
	void IntiCard();
	// 플레이어 초기화
	void IntiPlayerData();
	void ShuffleCard();
	void HandOutCardsToPlayers();

public:
	int _card[24] = {};
	Player _player[2] = {};
};

