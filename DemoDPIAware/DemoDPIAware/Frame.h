#ifndef _3F4C458B_771B_49A4_AEF8_EBF17F0A3799_H_
#define _3F4C458B_771B_49A4_AEF8_EBF17F0A3799_H_

class CFrame :
    public CWindowImpl<CFrame>
{
public:
    CFrame();
    virtual ~CFrame();

    BEGIN_MSG_MAP(CFrame)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
    END_MSG_MAP()

    // message handler.
    LRESULT OnCreate(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnDestroy(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnEraseBkgnd(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);
    LRESULT OnPaint(UINT _uMsg, WPARAM _wParam, LPARAM _lParam, BOOL& _bHandled);

public:
    HRESULT Create(const CRect& _rect);
    HRESULT Show();
    HRESULT Hide();
private:

};

#endif // _3F4C458B_771B_49A4_AEF8_EBF17F0A3799_H_
