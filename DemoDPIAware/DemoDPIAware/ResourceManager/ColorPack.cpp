#include "stdafx.h"
#include "ColorPack.h"

CColorPack::CColorPack()
{

}

CColorPack::~CColorPack()
{

}

HRESULT CColorPack::AddColor(const std::wstring& _name, const DWORD& _color)
{
    return S_OK;
}

HRESULT CColorPack::RemoveColor(const std::wstring& _name)
{
    return S_OK;
}

HRESULT CColorPack::GetColor(const std::wstring& _name, DWORD& _color)
{
    return S_OK;
}
