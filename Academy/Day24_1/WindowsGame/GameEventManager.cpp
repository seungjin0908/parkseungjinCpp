#include "pch.h"
#include "GameEventManager.h"
#include "GameEvent.h"

void GameEventManager::Init()
{

}

void GameEventManager::Release()
{
	ClearEvent();
}


void GameEventManager::RemoveEvent(wstring key)
{
	auto it = _gameEvents.find(key);
	if (it != _gameEvents.end())
	{
		delete static_cast<GameEvent<void*>*>(it->second);
		_gameEvents.erase(it);
	}
}

void GameEventManager::ClearEvent()
{
	for (auto& pair : _gameEvents)
	{
		delete static_cast<GameEvent<void*>*>(pair.second);
	}

	_gameEvents.clear();
}
