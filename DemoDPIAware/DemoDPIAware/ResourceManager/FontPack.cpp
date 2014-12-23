#include "stdafx.h"
#include "FontPack.h"

CFontPack::CFontPack()
{

}

CFontPack::~CFontPack()
{

}

HRESULT CFontPack::AddFont(const std::wstring& _name, const HFONT& _font)
{
    return S_OK;
}

HRESULT CFontPack::RemoveFont(const std::wstring& _name)
{
    return S_OK;
}

HRESULT CFontPack::GetFont(const std::wstring& _name, HFONT& _font)
{
    return S_OK;
}
