#include "stdafx.h"
#include "Frame.h"
#include "DPISetting.h"

CFrame::CFrame()
{
    m_buttonSize.cx = 40;
    m_buttonSize.cy = 26;
    m_captionHeight = 30;

    m_initWndPos.x = m_initWndPos.y = 0;
    m_initWndSize.cx = CW_USEDEFAULT;
    m_initWndSize.cy = CW_USEDEFAULT;
}

CFrame::~CFrame()
{

}

//////////////////////////////////////////////////////////////////////////
// BEGIN message handler.
LRESULT CFrame::OnCreate(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    DWORD dwStyle = ::GetWindowLong(m_hWnd, GWL_STYLE);
    dwStyle &= ~WS_SYSMENU;
    dwStyle &= ~WS_THICKFRAME;
    dwStyle &= ~WS_CAPTION;
    ::SetWindowLong(m_hWnd, GWL_STYLE, dwStyle);

    return 0;
}

LRESULT CFrame::OnDestroy(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    ::PostQuitMessage(0);
    return 0;
}

LRESULT CFrame::OnSize(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    _bHandled = FALSE;
    CDPISetting* g_dpi = CDPISetting::Instance();

    CRect rectWindow;
    GetWindowRect(&rectWindow);
    int width = rectWindow.Width();//LOWORD(_lParam);
    int height = rectWindow.Height();//HIWORD(_lParam);
    int widthUnScaled = g_dpi->UnScaleX(width);
    int heightUnScaled = g_dpi->UnScaleY(height);

    int rightOffset = widthUnScaled - m_gap;
    m_rectClose = CRect(rightOffset - m_buttonSize.cx, 0, rightOffset, m_buttonSize.cy);
    rightOffset -= m_gap;
    m_rectMaximize = CRect(rightOffset - m_buttonSize.cx, 0, rightOffset, m_buttonSize.cy);
    rightOffset -= m_gap;
    m_rectMinimize = CRect(rightOffset - m_buttonSize.cx, 0, rightOffset, m_buttonSize.cy);
    rightOffset -= m_gap;
    m_rectChangeSkin = CRect(rightOffset - m_buttonSize.cx, 0, rightOffset, m_buttonSize.cy);

    g_dpi->ScaleRect(m_rectClose);
    g_dpi->ScaleRect(m_rectMaximize);
    g_dpi->ScaleRect(m_rectMinimize);
    g_dpi->ScaleRect(m_rectChangeSkin);

    m_rectCaption = CRect(0, 0, width, g_dpi->ScaleY(m_captionHeight));

    return 0;
}

LRESULT CFrame::OnEraseBkgnd(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    _bHandled = TRUE;
    return 0;
}

LRESULT CFrame::OnPaint(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    _bHandled = TRUE;

    {
        WTL::CPaintDC paintDC(m_hWnd);
    }

    CRect rectClient;
    GetClientRect(&rectClient);
    CClientDC clientDC(m_hWnd);
    CMemoryDC memoryDC(clientDC, rectClient);
    //memoryDC.FillSolidRect(rectClient, RGB(255, 0, 0));
    Gdiplus::Graphics graphics(memoryDC);
    _PaintBkgnd(graphics, rectClient);
    _PaintCaption(graphics, m_rectCaption);
    _PaintButton(graphics, kChangeSkin, m_rectChangeSkin);
    _PaintButton(graphics, kMinimize, m_rectMinimize);
    _PaintButton(graphics, kMaximize, m_rectMaximize);
    _PaintButton(graphics, kClose, m_rectClose);

    return 0;
}

LRESULT CFrame::OnNcHitTest(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    _bHandled = TRUE;

    LRESULT result = HTCLIENT;
    CPoint point(GET_X_LPARAM(_lParam), GET_Y_LPARAM(_lParam));
    ScreenToClient(&point);
    if (m_rectCaption.PtInRect(point))
    {
        result = HTCAPTION;
    }

    return result;
}
// END message handler.
//////////////////////////////////////////////////////////////////////////

HRESULT CFrame::Create(const CRect& _rect)
{
    DWORD dwStyle = WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN;

    m_initWndPos = _rect.TopLeft();
    m_initWndSize = _rect.Size();

    CDPISetting* gdpi = CDPISetting::Instance();
    CRect rectInit(
        m_initWndPos.x, 
        m_initWndPos.y, 
        m_initWndPos.x + gdpi->ScaleX(m_initWndSize.cx), 
        m_initWndPos.y + gdpi->ScaleY(m_initWndSize.cy));

    CWindowImpl<CFrame>::Create(
        NULL, 
        rectInit, 
        NULL, 
        dwStyle, 
        0);

    return NULL != m_hWnd ? S_OK:E_FAIL;
}

HRESULT CFrame::SetPos(int _left, int _top)
{
    bool changeFlag = (_left != m_initWndPos.x || _top != m_initWndPos.y);

    m_initWndPos.x = _left;
    m_initWndPos.y = _top;

    if (changeFlag)
    {
        ::SetWindowPos(
            m_hWnd, 
            HWND_NOTOPMOST, 
            m_initWndPos.x, 
            m_initWndPos.y, 
            0,
            0, 
            SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);
    }

    return S_OK;
}

HRESULT CFrame::SetSize(int _width, int _height)
{
    bool changeFlag = (m_initWndSize.cx != _width || m_initWndSize.cy != _height);
    m_initWndSize.cx = _width;
    m_initWndSize.cy = _height;

    if (changeFlag)
    {
        CDPISetting* gdpi = CDPISetting::Instance();
        ::SetWindowPos(
            m_hWnd, 
            HWND_NOTOPMOST, 
            0, 
            0, 
            gdpi->ScaleX(_width), 
            gdpi->ScaleY(_height), 
            SWP_NOZORDER|SWP_NOMOVE|SWP_NOACTIVATE);
    }

    return S_OK;
}

HRESULT CFrame::Show()
{
    ShowWindow(SW_SHOWNORMAL);
    return S_OK;
}

HRESULT CFrame::Hide()
{
    ShowWindow(SW_HIDE);
    return S_OK;
}

HRESULT CFrame::SetCaptionHeight(int _height)
{
    CRect rectClient;
    GetClientRect(&rectClient);
    m_captionHeight = _height;
    m_rectCaption = CRect(0, 0, rectClient.Width(), CDPISetting::Instance()->ScaleY(_height));
    return S_OK;
}

HRESULT CFrame::SetItemGap(int _gap)
{
    m_gap = _gap;
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////
// BEGIN protected.
void CFrame::_PaintBkgnd(Gdiplus::Graphics& _graphics, const CRect& _rect)
{
    Gdiplus::SolidBrush sb(Gdiplus::Color(51, 51, 51));
    _graphics.FillRectangle(&sb, _rect.left, _rect.top, _rect.Width(), _rect.Height());
}

void CFrame::_PaintCaption(Gdiplus::Graphics& _graphics, const CRect& _rect)
{
    Gdiplus::SolidBrush sb(Gdiplus::Color(0, 0, 255));
    _graphics.FillRectangle(&sb, _rect.left, _rect.top, _rect.Width(), _rect.Height());
}

void CFrame::_PaintButton(Gdiplus::Graphics& _graphics, EKButton _kbutton, const CRect& _rect)
{

}
// END protected.
//////////////////////////////////////////////////////////////////////////
