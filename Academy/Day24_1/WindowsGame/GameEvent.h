#pragma once
// 이벤트를 보낼때
// 매게변수가 있어야할 경우가 되게많다.

// 예를 들어
// [보스가 등장했다.]
// => 그래서 어떤 보스?

// [보스가 등장했다.] (10001)
// 10001 => 자쿰이구나

template<typename... Args>
class GameEvent
{
public:
	GameEvent() {}
	~GameEvent() {}

public:
	//-------------------------------------
	// # 이벤트 설정 (변수)
	//-------------------------------------
	vector<function<void(Args...)>>_onEvents = {};

public:
	//-------------------------------------
	// # 이벤트 설정 (함수)
	//-------------------------------------
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
	for (function<void<Args...> onEvent : _onEvents)
	{
		onEvent(std::forward<Args>(args)...);
	}
}