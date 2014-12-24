#ifndef _393F0E5F_A4B6_4A86_A419_75F9A702960D_H_
#define _393F0E5F_A4B6_4A86_A419_75F9A702960D_H_

#include "ResourceManager/IResourceManager.h"

class Image;

class CResourceManager :
    public CComObjectRootEx<CComMultiThreadModel>, 
    public CComCoClass<CResourceManager>,
    public IResourceManager
{
public:
    CResourceManager();
    virtual ~CResourceManager();

    BEGIN_COM_MAP(CResourceManager)
        COM_INTERFACE_ENTRY(IResourceManager)
    END_COM_MAP()

    // IResourceManager.
    virtual HRESULT AddPack(IResourcePack* _pack);
    virtual HRESULT RemovePack(IResourcePack* _pack);
    virtual HRESULT GetImage(const std::wstring& _name, std::wstring& _path);
    virtual HRESULT GetFont(const std::wstring& _name, HFONT& _font);
    virtual HRESULT GetColor(const std::wstring& _name, DWORD& _color);

public:
    HRESULT GetPack(const std::wstring& _name, IResourcePack** _pack);
    static int GetFixedDPI(int _dpi);
    static Gdiplus::Image* CreateImage(const std::wstring& _path);
protected:
    typedef std::list<CComPtr<IResourcePack>> PACKCHAIN;
    PACKCHAIN m_packs;
};

#endif // _393F0E5F_A4B6_4A86_A419_75F9A702960D_H_
