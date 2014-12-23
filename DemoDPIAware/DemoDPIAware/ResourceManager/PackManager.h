#ifndef _DCC8D435_B9D7_4D16_8096_C4E389150105_H_
#define _DCC8D435_B9D7_4D16_8096_C4E389150105_H_

#include "ResourceManager/IResourceManager.h"

class CPackManager :
    public CComObjectRootEx<CComMultiThreadModel>, 
    public CComCoClass<CPackManager>, 
    public IPackManager
{
public:
    CPackManager();
    virtual ~CPackManager();

    BEGIN_COM_MAP(CPackManager)
        COM_INTERFACE_ENTRY(IPackManager)
    END_COM_MAP()

    virtual HRESULT AddPack(IResourcePack* _pack);
    virtual HRESULT RemovePack(IResourcePack* _pack);
    virtual HRESULT GetPack(const std::wstring& _name, IResourcePack** _pack);

public:
    static HRESULT LoadPack(
        const std::wstring _root, 
        const std::wstring& _path, 
        IResourcePack** _pack);

private:
    typedef std::map<std::wstring, CComPtr<IResourcePack>> MAP_PACK;
    MAP_PACK m_packs;
};

#endif // _DCC8D435_B9D7_4D16_8096_C4E389150105_H_
