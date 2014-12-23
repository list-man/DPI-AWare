#ifndef _4BC7F626_D933_48A7_8832_8DBC30DA90C8_H_
#define _4BC7F626_D933_48A7_8832_8DBC30DA90C8_H_

MIDL_INTERFACE("8392EE1C-FCB7-4EF4-874C-AE23A6E3D9B4")
IResourcePack : IUnknown
{
    virtual HRESULT GetPackName(std::wstring& _name) PURE;
    virtual HRESULT GetImage(const std::wstring& _name, std::wstring& _path) PURE;
    virtual HRESULT GetFont(const std::wstring& _name, HFONT& _font) PURE;
    virtual HRESULT GetColor(const std::wstring& _name, DWORD& _color) PURE;
    virtual HRESULT AddFont(const std::wstring& _name, const HFONT& _font) PURE;
    virtual HRESULT AddColor(const std::wstring& _name, const DWORD& _color) PURE;
};

MIDL_INTERFACE("0B96E0F8-D688-4895-9B17-8F2201F32872")
ITexturePack : IUnknown
{
    virtual HRESULT GetImage(const std::wstring& _name, std::wstring& _path) PURE;
};

MIDL_INTERFACE("98FA36C5-2629-44BD-BA06-D26E92EBE21B")
IFontPack : IUnknown
{
    virtual HRESULT AddFont(const std::wstring& _name, const HFONT& _font) PURE;
    virtual HRESULT RemoveFont(const std::wstring& _name) PURE;
    virtual HRESULT GetFont(const std::wstring& _name, HFONT& _font) PURE;
};

MIDL_INTERFACE("9CC71256-B5CD-434B-B712-722C17EBD9A1")
IColorPack : IUnknown
{
    virtual HRESULT AddColor(const std::wstring& _name, const DWORD& _color) PURE;
    virtual HRESULT RemoveColor(const std::wstring& _name) PURE;
    virtual HRESULT GetColor(const std::wstring& _name, DWORD& _color) PURE;
};

#endif // _4BC7F626_D933_48A7_8832_8DBC30DA90C8_H_
