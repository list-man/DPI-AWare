#ifndef _08539C19_1138_4235_8D8D_52BC6E1088B6_H_
#define _08539C19_1138_4235_8D8D_52BC6E1088B6_H_

#include "FontPack.h"
#include "TexturePack.h"
#include "ColorPack.h"
#include "ResourceManager/IResourcePack.h"

class CResourcePack :
    public CComObjectRootEx<CComMultiThreadModel>,
    public CComCoClass<CResourcePack>, 
    public IResourcePack
{
public:
    CResourcePack();
    virtual ~CResourcePack();

    HRESULT FinalConstruct();
    void FinalRelease();

    BEGIN_COM_MAP(CResourcePack)
        COM_INTERFACE_ENTRY(IResourcePack)
    END_COM_MAP()

    virtual HRESULT GetPackName(std::wstring& _name);
    virtual HRESULT GetImage(const std::wstring& _name, std::wstring& _path);
    virtual HRESULT GetFont(const std::wstring& _name, HFONT& _font);
    virtual HRESULT GetColor(const std::wstring& _name, DWORD& _color);
    virtual HRESULT AddFont(const std::wstring& _name, const HFONT& _font);
    virtual HRESULT AddColor(const std::wstring& _name, const DWORD& _color);

public:
    HRESULT Init(const std::wstring _root, const std::wstring& _tag);
private:
    std::wstring m_root;
    std::wstring m_tag;
    CComPtr<ITexturePack> m_textures;
    CComPtr<IFontPack> m_fonts;
    CComPtr<IColorPack> m_colors;
};

#endif // _08539C19_1138_4235_8D8D_52BC6E1088B6_H_
