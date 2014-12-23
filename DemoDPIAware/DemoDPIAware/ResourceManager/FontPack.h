#ifndef _4BCCDF42_2D93_4A25_AA70_D0413F7E2FF6_H_
#define _4BCCDF42_2D93_4A25_AA70_D0413F7E2FF6_H_

#include "ResourceManager/IResourcePack.h"

class CFontPack :
    public CComObjectRootEx<CComMultiThreadModel>, 
    public CComCoClass<CFontPack>, 
    public IFontPack
{
public:
    CFontPack();
    virtual ~CFontPack();

    BEGIN_COM_MAP(CFontPack)
        COM_INTERFACE_ENTRY(IFontPack)
    END_COM_MAP()

    virtual HRESULT AddFont(const std::wstring& _name, const HFONT& _font);
    virtual HRESULT RemoveFont(const std::wstring& _name);
    virtual HRESULT GetFont(const std::wstring& _name, HFONT& _font);
private:
};

#endif // _4BCCDF42_2D93_4A25_AA70_D0413F7E2FF6_H_
