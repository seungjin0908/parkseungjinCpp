#pragma once
#include "GameEvent.h"

class GameEventManager
{
	DECLARE_SINGLE(GameEventManager)

public:
	void Init();
	void Release();

public:
	template<typename... Args>
	GameEvent<Args...>* GetEvent(wstring key);

	template<typename... Args>
	void AddEvent(wstring key, GameEvent<Args...>* gameEvent);

	void RemoveEvent(wstring key);
	void ClearEvent();

	template<typename... Args>
	void Invoke(wstring key, Args... args);

private:
	map<wstring, void*> _gameEvents;
};


template<typename... Args>
GameEvent<Args...>* GameEventManager::GetEvent(wstring key)
{
	auto it = _gameEvents.find(key);
	if (it != _gameEvents.end())
	{
		return static_cast<GameEvent<Args...>*>(it->second);
	}

	return nullptr;
}

template<typename... Args>
void GameEventManager::AddEvent(wstring key, GameEvent<Args...>* gameEvent)
{
	_gameEvents[key] = static_cast<void*>(gameEvent);
}

template<typename... Args>
void GameEventManager::Invoke(wstring key, Args... args)
{
	auto it = _gameEvents.find(key);
	if (it != _gameEvents.end())
	{
		auto gameEvent = static_cast<GameEvent<Args...>*>(it->second);

		if (gameEvent != nullptr)
		{
			(*gameEvent)(args...);
		}
	}
}