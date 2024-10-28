#include "pch.h"
#include "CameraComponent.h"
#include "Scene.h"
#include "GameObject.h"
void CameraComponent::Init()
{
	Super::Init();
}

void CameraComponent::Render(HDC hdc)
{
	Super::Render(hdc);
}

void CameraComponent::Update()
{
	Vector2 pos = this->GetOwner()->GetPos();

	CenterRect cameraArea = CurrentScene->GetCameraArea();
	/*if (pos.x < cameraArea.Left())
	{
		pos.x = cameraArea.Left();
	}
	if (cameraArea.Right() < pos.x)
	{
		pos.y = cameraArea.Right();
	}*/
	pos.x = clamp(pos.x, cameraArea.Left() + WIN_SIZE_X / 2, cameraArea.Right() - WIN_SIZE_Y / 2);
	pos.y = clamp(pos.y, cameraArea.Top() + WIN_SIZE_X / 2, cameraArea.Bottom() - WIN_SIZE_Y / 2);
	pos -= Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	
	CurrentScene->SetCameraPos(pos);

	
}

void CameraComponent::Release()
{
	Super::Release();
}
