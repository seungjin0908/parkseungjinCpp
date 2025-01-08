#pragma once
#include "Data.h"

class DataManager
{
	DECLARE_SINGLE(DataManager)

public:
	void Init();
	void Release();

public:
	MonsterData GetMonster(int64 id) { return _monsterDatas[id]; }

private:
	// <id, Data객체>
	map<int64, MonsterData> _monsterDatas = {};
};

