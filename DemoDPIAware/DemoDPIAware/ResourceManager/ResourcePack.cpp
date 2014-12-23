#include "stdafx.h"
#include "ResourcePack.h"

CResourcePack::CResourcePack()
{
}

CResourcePack::~CResourcePack()
{
    if (m_textures)
    {
        delete m_textures;
        m_textures = NULL;
    }

    if (m_fonts)
    {
        delete m_fonts;
        m_fonts = NULL;
    }

    if (m_colors)
    {
        delete m_colors;
        m_colors = NULL;
    }
}

HRESULT CResourcePack::FinalConstruct()
{
    CComObject<CTexturePack>* texture = NULL;
    CComObject<CFontPack>* font = NULL;
    CComObject<CColorPack>* color = NULL;

    if (SUCCEEDED(CComObject<CTexturePack>::CreateInstance(&texture))
        && texture)
    {
        texture->QueryInterface(__uuidof(ITexturePack), (void**)&m_textures);
    }

    if (SUCCEEDED(CComObject<CFontPack>::CreateInstance(&font))
        && font)
    {
        font->QueryInterface(__uuidof(IFontPack), (void**)&m_fonts);
    }

    if (SUCCEEDED(CComObject<CColorPack>::CreateInstance(&color))
        && color)
    {
        color->QueryInterface(__uuidof(IColorPack), (void**)&m_colors);
    }

    return S_OK;
}

void CResourcePack::FinalRelease()
{
    m_colors.Release();
    m_textures.Release();
    m_fonts.Release();
}

HRESULT CResourcePack::GetPackName(std::wstring& _name)
{
    _name = m_tag;
    return S_OK;
}

HRESULT CResourcePack::GetImage(const std::wstring& _name, std::wstring& _path)
{
    return S_OK;
}

HRESULT CResourcePack::GetFont(const std::wstring& _name, HFONT& _font)
{
    return S_OK;
}

HRESULT CResourcePack::GetColor(const std::wstring& _name, DWORD& _color)
{
    return S_OK;
}

HRESULT CResourcePack::AddFont(const std::wstring& _name, const HFONT& _font)
{
    if (m_fonts)
    {
        return m_fonts->AddFont(_name, _font);
    }

    return E_FAIL;
}

HRESULT CResourcePack::AddColor(const std::wstring& _name, const DWORD& _color)
{
    if (m_colors)
    {
        return m_colors->AddColor(_name, _color);
    }

    return E_FAIL;
}

//////////////////////////////////////////////////////////////////////////
// BEGIN public.
HRESULT CResourcePack::Init(const std::wstring _root, const std::wstring& _tag)
{
    m_root = _root;
    m_tag = _tag;
    return S_OK;
}
// END public.
//////////////////////////////////////////////////////////////////////////
