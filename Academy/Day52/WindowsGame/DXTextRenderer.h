#pragma once
#include "Component.h"
class DXText;
class DXTextRenderer : public Component
{
	DECLARE_CHILD(DXTextRenderer, Component);

public:
	virtual void Init();
	virtual void D2DRender();
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(DXText* dxTextResource) { _dxTextResource = dxTextResource; }
	DXText* GetInfo() { return _dxTextResource; }

	void SetText(wstring text) { _text = text; }
	wstring GetText() { return _text; }

private:
	DXText* _dxTextResource;
	wstring _text;
};

