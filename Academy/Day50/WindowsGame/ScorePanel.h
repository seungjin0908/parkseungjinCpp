#pragma once
#include "Panel.h"

/*
ScorePanel
 ├─Image_ScoreBackground (o)
 ├─Image_ScoreIcon (o)
 └─Text_Score (o)
*/
class ScorePanel : public Panel
{
    DECLARE_CHILD(ScorePanel, Panel);

public:
    virtual void Init();
    virtual void Render(HDC hdc);
    virtual void Update();
    virtual void Release();
};

