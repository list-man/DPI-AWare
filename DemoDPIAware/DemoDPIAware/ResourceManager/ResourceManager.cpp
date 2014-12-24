#include "stdafx.h"
#include "ResourceManager.h"

CResourceManager::CResourceManager()
{

}

CResourceManager::~CResourceManager()
{

}

HRESULT CResourceManager::AddPack(IResourcePack* _pack)
{
    CheckPointer(_pack, E_INVALIDARG);
    HRESULT result = S_FALSE;

    do 
    {
        std::wstring name;
        _pack->GetPackName(name);
        if (SUCCEEDED(GetPack(name, NULL)))
        {
            // already exist.
            result = S_FALSE;
            break;
        }

        m_packs.insert(m_packs.begin(), _pack);
        result = S_OK;

    } while (false);

    return result;
}

HRESULT CResourceManager::RemovePack(IResourcePack* _pack)
{
    CheckPointer(_pack, E_INVALIDARG);
    HRESULT result = S_FALSE;

    PACKCHAIN::const_iterator current = m_packs.begin();
    PACKCHAIN::const_iterator end = m_packs.end();

    std::wstring nameRef;
    _pack->GetPackName(nameRef);

    while (current != end)
    {
        CComQIPtr<IResourcePack> pack = *current;
        if (pack)
        {
            std::wstring name;
            if (SUCCEEDED(pack->GetPackName(name))
                && name == nameRef)
            {
                m_packs.erase(current);
                result = S_OK;
                break;
            }
        }

        current++;
    }

    return result;
}

HRESULT CResourceManager::GetImage(const std::wstring& _name, std::wstring& _path)
{
    HRESULT result = E_FAIL;

    PACKCHAIN::const_iterator current = m_packs.begin();
    PACKCHAIN::const_iterator end = m_packs.end();
    while (current != end)
    {
        CComQIPtr<IResourcePack> pack = *current;
        if (pack)
        {
            if (SUCCEEDED(result = pack->GetImage(_name, _path)))
            {
                break;
            }
        }

        current++;
    }

    return result;
}

HRESULT CResourceManager::GetFont(const std::wstring& _name, HFONT& _font)
{
    HRESULT result = E_FAIL;

    PACKCHAIN::const_iterator current = m_packs.begin();
    PACKCHAIN::const_iterator end = m_packs.end();
    while (current != end)
    {
        CComQIPtr<IResourcePack> pack = *current;
        if (pack)
        {
            if (SUCCEEDED(result = pack->GetFont(_name, _font)))
            {
                break;
            }
        }

        current++;
    }

    return result;
}

HRESULT CResourceManager::GetColor(const std::wstring& _name, DWORD& _color)
{
    HRESULT result = E_FAIL;

    PACKCHAIN::const_iterator current = m_packs.begin();
    PACKCHAIN::const_iterator end = m_packs.end();
    while (current != end)
    {
        CComQIPtr<IResourcePack> pack = *current;
        if (pack)
        {
            if (SUCCEEDED(result = pack->GetColor(_name, _color)))
            {
                break;
            }
        }

        current++;
    }

    return result;
}

//////////////////////////////////////////////////////////////////////////
// BEGIN protected.
HRESULT CResourceManager::GetPack(const std::wstring& _name, IResourcePack** _pack)
{
    HRESULT result = E_FAIL;

    PACKCHAIN::const_iterator current = m_packs.begin();
    PACKCHAIN::const_iterator end = m_packs.end();

    while (current != end)
    {
        CComQIPtr<IResourcePack> pack = *current;
        if (pack)
        {
            std::wstring name;
            if (SUCCEEDED(pack->GetPackName(name))
                && name == _name)
            {
                if (_pack) pack.CopyTo(_pack);

                result = S_OK;
                break;
            }
        }

        current++;
    }

    return result;
}

/*
static
*/
int CResourceManager::GetFixedDPI(int _dpi)
{
    if (_dpi > 96)
    {
        return 192;
    }
    else
    {
        return 96;
    }
}

/*
static
*/
Gdiplus::Image* CResourceManager::CreateImage(const std::wstring& _path)
{
    return Gdiplus::Image::FromFile(_path.c_str(), FALSE);
}
// END protected.
//////////////////////////////////////////////////////////////////////////
