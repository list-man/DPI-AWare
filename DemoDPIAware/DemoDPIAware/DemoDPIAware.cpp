// DemoDPIAware.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DemoDPIAware.h"
#include "Frame.h"
#include "DPISetting.h"


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

    ::SetProcessDPIAware();
    CFrame frame;
    int resolutionX = CDPISetting::Instance()->GetResolutionX();
    int resolutionY = CDPISetting::Instance()->GetResolutionY();
    int width = CDPISetting::Instance()->ScaleX(500);
    int height = CDPISetting::Instance()->ScaleY(400);
    CRect rectWindow(CPoint((resolutionX-width)>>1, (resolutionY-height)>>1), CSize(width, height));
    frame.Create(rectWindow);
    frame.Show();

 	// TODO: Place code here.
	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}
