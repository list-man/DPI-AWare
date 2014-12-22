#include "stdafx.h"
#include "Frame.h"

CFrame::CFrame()
{

}

CFrame::~CFrame()
{

}

//////////////////////////////////////////////////////////////////////////
// BEGIN message handler.
LRESULT CFrame::OnCreate(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    return 0;
}

LRESULT CFrame::OnDestroy(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    ::PostQuitMessage(0);
    return 0;
}

LRESULT CFrame::OnEraseBkgnd(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    _bHandled = TRUE;
    return 0;
}

LRESULT CFrame::OnPaint(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled)
{
    {
        WTL::CPaintDC paintDC(m_hWnd);
    }

    CRect rectClient;
    GetClientRect(&rectClient);
    CMemoryDC memoryDC(CClientDC(m_hWnd), rectClient);

    return 0;
}
// END message handler.
//////////////////////////////////////////////////////////////////////////

HRESULT CFrame::Create(const CRect& _rect)
{
    CWindowImpl<CFrame>::Create(
        NULL, 
        const_cast<CRect*>(&_rect), 
        NULL, 
        WS_OVERLAPPEDWINDOW, 
        0);

    return NULL != m_hWnd ? S_OK:E_FAIL;
}

HRESULT CFrame::Show()
{
    ShowWindow(SW_SHOWNOACTIVATE);
    return S_OK;
}

HRESULT CFrame::Hide()
{
    ShowWindow(SW_HIDE);
    return S_OK;
}
