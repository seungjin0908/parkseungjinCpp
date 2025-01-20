#pragma once
#include "Panel.h"

/*
CompletePanel
 ├─Image_CompleteIcon (o)
 └─Text_Complete (o)
*/
class CompletePanel : public Panel
{
    DECLARE_CHILD(CompletePanel, Panel);

public:
    virtual void Init();
    virtual void Render(HDC hdc);
    virtual void Update();
    virtual void Release();
};

