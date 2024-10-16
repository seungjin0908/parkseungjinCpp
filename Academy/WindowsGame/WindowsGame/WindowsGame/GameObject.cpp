#include "pch.h"
#include "GameObject.h"
#include "Component.h"

void GameObject::Init()
{
}

void GameObject::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		if (false == component->GetEnable()) continue;

		component->Render(hdc);
	}
}

void GameObject::Update()
{
	for (Component* component : _components)
	{
		if (false == component->GetEnable()) continue;

		component->Update();
	}
}

void GameObject::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}

	_components.clear();
}

void GameObject::AddComponent(Component* component)
{
	if (component == nullptr)return;

	component->SetOwner(this);
	component->Init();
	_components.push_back(component);
}

void GameObject::RemoveComponet(Component* component)
{
	if (component == nullptr) return;

	auto findIt = find(_components.begin(), _components.end(), component);

	if (findIt != _components.end())
	{
		Component* deletComponent = *findIt;
		deletComponent->Release();
		SAFE_DELETE(deletComponent);
		_components.erase(findIt);
	}
}
