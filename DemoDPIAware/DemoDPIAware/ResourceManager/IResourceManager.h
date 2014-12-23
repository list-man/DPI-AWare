#ifndef _D5373AAB_A17E_4784_BB0A_BD2AF7651BFE_H_
#define _D5373AAB_A17E_4784_BB0A_BD2AF7651BFE_H_

#include "ResourceManager/IResourcePack.h"

MIDL_INTERFACE("EB4E1875-AD99-4250-A5D5-C39EA27D7E71")
IPackManager : IUnknown
{
    virtual HRESULT AddPack(IResourcePack* _pack) PURE;
    virtual HRESULT RemovePack(IResourcePack* _pack) PURE;
    virtual HRESULT GetPack(const std::wstring& _name, IResourcePack** _pack) PURE;
};

MIDL_INTERFACE("A207B7D0-500A-4F57-8ACF-DB7FF37DD1A6")
IResourceManager : IUnknown
{
    virtual HRESULT AddPack(IResourcePack* _pack) PURE;
    virtual HRESULT RemovePack(IResourcePack* _pack) PURE;
    virtual HRESULT GetImage(const std::wstring& _name, std::wstring& _path) PURE;
    virtual HRESULT GetFont(const std::wstring& _name, HFONT& _font) PURE;
    virtual HRESULT GetColor(const std::wstring& _name, DWORD& _color) PURE;
};

#endif // _D5373AAB_A17E_4784_BB0A_BD2AF7651BFE_H_
