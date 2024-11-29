#pragma once
#include "Panel.h"

/*
ButtonPanel
 ├─Button_Exit (o)
 └─Button_Repeat (o)
*/
class ButtonPanel : public Panel
{
    DECLARE_CHILD(ButtonPanel, Panel);

public:
    virtual void Init();
    virtual void Render(HDC hdc);
    virtual void Update();
    virtual void Release();
};

