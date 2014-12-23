#include "stdafx.h"
#include "PackManager.h"
#include "ResourceManager/ResourcePack.h"

CPackManager::CPackManager()
{

}

CPackManager::~CPackManager()
{

}

/*
static 
*/
HRESULT CPackManager::LoadPack(const std::wstring _root, const std::wstring& _path, IResourcePack** _pack)
{
    CheckPointer(_pack, E_INVALIDARG);
    HRESULT result = S_FALSE;

    do 
    {
        CComObject<CResourcePack>* object = NULL;
        if (FAILED(result = CComObject<CResourcePack>::CreateInstance(&object))
            || !object) break;

        result = object->Init(_root, _path);

        object->QueryInterface(__uuidof(IResourcePack), (void**)_pack);

    } while (false);

    return result;
}

HRESULT CPackManager::AddPack(IResourcePack* _pack)
{
    return E_NOTIMPL;
}

HRESULT CPackManager::RemovePack(IResourcePack* _pack)
{
    return E_NOTIMPL;
}

HRESULT CPackManager::GetPack(const std::wstring& _name, IResourcePack** _pack)
{
    HRESULT result = E_FAIL;
    CheckPointer(_pack, E_INVALIDARG);

    MAP_PACK::const_iterator itr = m_packs.find(_name);
    if (itr != m_packs.end())
    {
        CComQIPtr<IResourcePack> pack = itr->second;
        result = pack.CopyTo(_pack);
    }

    return result;
}
