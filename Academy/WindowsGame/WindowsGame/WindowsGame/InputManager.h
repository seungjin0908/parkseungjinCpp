#pragma once

enum class KeyCode
{
	LeftMouse =VK_LBUTTON,
	RightMouse=VK_RBUTTON,

	Up = VK_UP,
	Left=VK_LEFT,

};

enum class KeyState
{
	None,
	Press,
	Down,
	Up,
	End
};

enum
{
	KEY_CODE_COUNT = static_cast<int>(UINT8_MAX) +1,
	KEY_STATE_COUNT =static_cast<int>(KeyState::End)
};

class InputManager
{
public:
	void Init(HWND hwnd);
	void Update();

public:
	bool GetKey(KeyCode key);
	bool GetKeyDown(KeyCode key);
	bool GetKeyUp(KeyCode key);

	POINT GetMousePos();
private:
	KeyState GetState(KeyCode key) { return _states[static_cast<unsigned char>(key)]; }

private:
	HWND _hwnd = {};
	POINT _mousePos = {};
	vector<KeyState> _states;
};