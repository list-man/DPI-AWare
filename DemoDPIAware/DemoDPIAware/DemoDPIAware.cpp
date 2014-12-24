// DemoDPIAware.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DemoDPIAware.h"
#include "Frame.h"
#include "DPISetting.h"

CComModule _Module;


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

    ULONG_PTR token;
    Gdiplus::GdiplusStartupInput input;
    Gdiplus::GdiplusStartupOutput output;
    Gdiplus::GdiplusStartup(&token, &input, &output);

    ::SetProcessDPIAware();
    CFrame frame;
    int resolutionX = CDPISetting::Instance()->GetResolutionX();
    int resolutionY = CDPISetting::Instance()->GetResolutionY();
    int width = 500;//CDPISetting::Instance()->ScaleX(500);
    int height = 400;//CDPISetting::Instance()->ScaleY(400);
    int widthScaled = CDPISetting::Instance()->ScaleX(width);
    int heightScaled = CDPISetting::Instance()->ScaleY(height);
    CRect rectWindow(CPoint((resolutionX-widthScaled)>>1, (resolutionY-heightScaled)>>1), CSize(width, height));
    frame.Create(rectWindow);
    frame.SetCaptionHeight(40);
    frame.SetItemGap(3);
    frame.Show();

 	// TODO: Place code here.
	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

    Gdiplus::GdiplusShutdown(token);

	return (int) msg.wParam;
}
