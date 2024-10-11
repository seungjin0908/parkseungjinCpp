#include "pch.h"
#include "Sprite.h"

Sprite::Sprite(Texture* texture, int x, int y, int cx, int cy)
{
}

HDC Sprite::GetDC()
{
    return HDC();
}

int32 Sprite::GetTransparent()
{
    return int32();
}

Vector2Int Sprite::GetPos()
{
    return Vector2Int();
}

Vector2Int Sprite::GetSize()
{
    return Vector2Int();
}

void Sprite::Render(HDC hdc, int x, int y)
{
}
