#pragma once
#include "Panel.h"

/*
StarPanel
  ├─Image_Star_Fill (o)
  ├─Image_Star_Fill (o)
  └─Image_Star_Empty (o)
*/
class StarPanel : public Panel
{
    DECLARE_CHILD(StarPanel, Panel);

public:
    virtual void Init();
    virtual void Render(HDC hdc);
    virtual void Update();
    virtual void Release();
};

