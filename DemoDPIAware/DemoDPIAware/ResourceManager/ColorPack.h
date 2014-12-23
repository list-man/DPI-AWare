#ifndef _94F28F29_3264_4420_BEEA_C9CC371AE71C_H_
#define _94F28F29_3264_4420_BEEA_C9CC371AE71C_H_

#include "ResourceManager/IResourcePack.h"

class CColorPack :
    public CComObjectRootEx<CComMultiThreadModel>,
    public CComCoClass<CColorPack>, 
    public IColorPack
{
public:
    CColorPack();
    virtual ~CColorPack();

    BEGIN_COM_MAP(CColorPack)
        COM_INTERFACE_ENTRY(IColorPack)
    END_COM_MAP()

    virtual HRESULT AddColor(const std::wstring& _name, const DWORD& _color);
    virtual HRESULT RemoveColor(const std::wstring& _name);
    virtual HRESULT GetColor(const std::wstring& _name, DWORD& _color);

private:
};

#endif // _94F28F29_3264_4420_BEEA_C9CC371AE71C_H_
