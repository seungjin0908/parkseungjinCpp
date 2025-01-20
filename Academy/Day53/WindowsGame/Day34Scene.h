#pragma once
#include "Scene.h"

class Image;
class Day34Scene : public Scene
{
	DECLARE_CHILD(Day34Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	Image* _image = nullptr;
};

