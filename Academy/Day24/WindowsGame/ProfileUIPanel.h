#pragma once
#include "Panel.h"
class ProfileAreaPanel;
class Image;
class ProfileUIPanel : public Panel
{
	DECLARE_CHILD(ProfileUIPanel, Panel);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

private:
	ProfileAreaPanel* _profileAreaPanel = nullptr;
	Image* _nameImage;



protected:

public:


};

