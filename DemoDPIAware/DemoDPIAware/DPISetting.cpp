#include "stdafx.h"
#include "DPISetting.h"

#define _WIDTH(rc) (rc.right - rc.left)
#define _HEIGHT(rc) (rc.bottom - rc.top)

CDPISetting* CDPISetting::s_instance = NULL;

/*
static
*/
CDPISetting* CDPISetting::Instance()
{
    if (!s_instance)
    {
        s_instance = new CDPISetting();
        if (s_instance)
        {
            s_instance->_Init();
        }
    }

    return s_instance;
}

CDPISetting::CDPISetting() :
        m_dpiBaseLine(96), 
        m_dpiX(96), 
        m_dpiY(96), 
        m_initialized(false)
{

}

CDPISetting::~CDPISetting()
{

}

int CDPISetting::GetDPIX()
{
    return m_dpiX;
}

int CDPISetting::GetDPIY()
{
    return m_dpiY;
}

int CDPISetting::GetDPIBaseLine()
{
    return m_dpiBaseLine;
}

int CDPISetting::ScaleX(int _width)
{
    return MulDiv(_width, m_dpiX, m_dpiBaseLine);
}

int CDPISetting::ScaleY(int _height)
{
    return MulDiv(_height, m_dpiY, m_dpiBaseLine);
}

int CDPISetting::UnScaleX(int _width)
{
    return MulDiv(_width, m_dpiBaseLine, m_dpiX);
}

int CDPISetting::UnScaleY(int _height)
{
    return MulDiv(_height, m_dpiBaseLine, m_dpiY);
}

void CDPISetting::ScaleRect(RECT& _rect)
{
    _rect.left = ScaleX(_rect.left);
    _rect.top = ScaleY(_rect.top);
    _rect.right = ScaleX(_rect.right);
    _rect.bottom = ScaleY(_rect.bottom);
}

int CDPISetting::PointsToPixel(int _points)
{
    return MulDiv(_points, m_dpiY, 72);
}

int CDPISetting::GetResolutionX()
{
    return m_resolutionX;
}

int CDPISetting::GetResolutionY()
{
    return m_resolutionY;
}

//////////////////////////////////////////////////////////////////////////
// BEGIN protected.
bool CDPISetting::_Init()
{
    if (!m_initialized)
    {
        HDC hDCScreen = ::GetDC(NULL);
        m_dpiX = ::GetDeviceCaps(hDCScreen, LOGPIXELSX);
        m_dpiY = ::GetDeviceCaps(hDCScreen, LOGPIXELSY);
        ::ReleaseDC(NULL, hDCScreen);

        m_resolutionX = ::GetSystemMetrics(SM_CXSCREEN);
        m_resolutionY = ::GetSystemMetrics(SM_CYSCREEN);

        m_initialized = true;
    }

    return m_initialized;
}
// END protected.
//////////////////////////////////////////////////////////////////////////
