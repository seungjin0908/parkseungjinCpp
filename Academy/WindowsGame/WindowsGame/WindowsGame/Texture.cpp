#include "pch.h"
#include "Texture.h"

Texture* Texture::LoadBmp(const wstring& path)
{
	HDC hdc = ::GetDC(_hWnd);
	_hdc = CreateCompatibleDC(hdc);
	_bitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0 LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (_bitmap == NULL)
	{
		MessageBox(_hWnd, path.c_str(), L"Image Load Failed", 0);
		return nullptr;
	}

	HBITMAP prev = (HBITMAP)SelectObject(_hdc, _bitmap);
	DeleteObject(prev);

	BITMAP bit = {};
	GetObject(_bitmap, sizeof(BITMAP), &bit);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;

	return this;
}

void Texture::SetSize(Vector2Int size)
{

}
