#pragma once
#include "Data.h"

class DataManager
{
	DECLARE_SINGLE(DataManager)

public:
	void Init();
	void Release();

public:
	MosterData GetMoster(int64 id) { return _mosterDatas[id]; }

private:
	// <id, Data객체>
	map<int64, IData> _mosterDatas = {};
};

