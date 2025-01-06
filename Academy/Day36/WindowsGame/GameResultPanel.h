#pragma once
#include "Panel.h"

/*
GameResultPanel
    ├─GameResultCardPanel
    │  ├─ButtonPanel
    │  │  ├─Button_Exit (o)
    │  │  └─Button_Repeat (o)
    │  ├─CompletePanel
    │  │  ├─Image_CompleteIcon (o)
    │  │  └─Text_Complete (o)
    │  ├─ScorePanel
    │  │  ├─Image_ScoreBackground (o)
    │  │  ├─Image_ScoreIcon (o)
    │  │  └─Text_Score (o)
    │  └─StarPanel
    │      ├─Image_Star_Fill (o)
    │      ├─Image_Star_Fill (o)
    │      └─Image_Star_Empty (o)
    └─Image_Background (o)
*/
class GameResultPanel : public Panel
{
    DECLARE_CHILD(GameResultPanel, Panel);

public:
    virtual void Init();
    virtual void Render(HDC hdc);
    virtual void Update();
    virtual void Release();
};

