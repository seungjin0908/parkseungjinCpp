#pragma once
#include "Panel.h"
class Image;
class ProfileAreaPanel : public Panel
{
	DECLARE_CHILD(ProfileAreaPanel, Panel);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

private:
	Image* _profileImage = nullptr;
	Image* _plusImage = nullptr;
public:
};

