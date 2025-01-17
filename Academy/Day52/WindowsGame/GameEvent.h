#pragma once
template<typename... Args>
class GameEvent
{
public:
	GameEvent() {}
	~GameEvent() {}

public:
	//------------------------------------------------
	//	# 이벤트 설정 (변수)
	//------------------------------------------------
	vector<function<void(Args...)>> _onEvents = {};

public:
	//------------------------------------------------
	//	# 이벤트 설정 (함수)
	//------------------------------------------------
	template<typename T>
	void AddListen(T* owner, void(T::* func)(Args...))
	{
		_onEvents.push_back([=](Args... args) {
			(owner->*func)(args...);
			});

		//_onEvents.push_back(bind(func, owner, this));
	}

public:
	virtual void Init() {} 
	virtual void Release() {}
	virtual void Update() {}

	void Invoke(Args... args);
};

template<typename... Args>
void GameEvent<Args...>::Invoke(Args... args)
{
	for (function<void(Args...)> onEvent : _onEvents)
	{
		onEvent(std::forward<Args>(args)...);
	}
}