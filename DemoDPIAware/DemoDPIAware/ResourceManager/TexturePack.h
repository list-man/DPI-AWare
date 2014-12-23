#ifndef _0BFA847D_73AA_42C1_B60E_87A8FAE2C4FF_H_
#define _0BFA847D_73AA_42C1_B60E_87A8FAE2C4FF_H_

#include "ResourceManager/IResourcePack.h"

class CTexturePack :
    public CComObjectRootEx<CComMultiThreadModel>, 
    public CComCoClass<CTexturePack>, 
    public ITexturePack
{
public:
    CTexturePack();
    virtual ~CTexturePack();

    BEGIN_COM_MAP(CTexturePack)
        COM_INTERFACE_ENTRY(ITexturePack)
    END_COM_MAP()

    virtual HRESULT GetImage(const std::wstring& _name, std::wstring& _path);

private:
};

#endif // _0BFA847D_73AA_42C1_B60E_87A8FAE2C4FF_H_
