#ifndef _3F4C458B_771B_49A4_AEF8_EBF17F0A3799_H_
#define _3F4C458B_771B_49A4_AEF8_EBF17F0A3799_H_

#include "ResourceManager/IResourceManager.h"

class CFrame :
    public CWindowImpl<CFrame>
{
public:
    CFrame();
    virtual ~CFrame();

    BEGIN_MSG_MAP(CFrame)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_NCHITTEST, OnNcHitTest)
    END_MSG_MAP()

    // message handler.
    LRESULT OnCreate(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnDestroy(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnSize(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnEraseBkgnd(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnPaint(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnNcHitTest(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
public:
    HRESULT Create(const CRect& _rect);
    HRESULT SetPos(int _left, int _top);
    HRESULT SetSize(int _width, int _height);
    HRESULT Show();
    HRESULT Hide();
    HRESULT SetCaptionHeight(int _height);
    HRESULT SetItemGap(int _gap);
protected:
    typedef enum
    {
        kChangeSkin,
        kMinimize,
        kRestore,
        kMaximize,
        kClose
    }EKButton;

    void _PaintBkgnd(Gdiplus::Graphics& _graphics, const CRect& _rect);
    void _PaintCaption(Gdiplus::Graphics& _graphics, const CRect& _rect);
    void _PaintButton(Gdiplus::Graphics& _graphics, EKButton _kbutton, const CRect& _rect);
private:
    int m_gap;
    int m_captionHeight;
    CRect m_rectCaption;
    CRect m_rectChangeSkin;
    CRect m_rectMinimize;
    CRect m_rectMaximize;
    CRect m_rectClose;
    CSize m_buttonSize;
    CPoint m_initWndPos;
    CSize m_initWndSize;

    CComPtr<IResourceManager> m_spResMgr;
};

#endif // _3F4C458B_771B_49A4_AEF8_EBF17F0A3799_H_
