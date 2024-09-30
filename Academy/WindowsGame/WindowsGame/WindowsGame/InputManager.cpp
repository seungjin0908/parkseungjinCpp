#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_CODE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	::GetCursorPos(&_mousePos);
}

bool InputManager::GetKey(KeyCode key)
{
	return false;
}

bool InputManager::GetKeyDown(KeyCode key)
{
	return false;
}

bool InputManager::GetKeyUp(KeyCode key)
{
	return false;
}

POINT InputManager::GetMousePos()
{
	return POINT();
}
