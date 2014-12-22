#ifndef _ACA74D7A_2695_42C0_8B90_0B00EF16ABBE_H_
#define _ACA74D7A_2695_42C0_8B90_0B00EF16ABBE_H_

class CDPISetting
{
public:
    static CDPISetting* Instance();
    virtual ~CDPISetting();

    int GetDPIX();
    int GetDPIY();
    int GetDPIBaseLine();
    int GetResolutionX();
    int GetResolutionY();

    int ScaleX(int _width);
    int ScaleY(int _height);
    void ScaleRect(RECT& _rect);
    int UnScaleX(int _width);
    int UnScaleY(int _height);
    int PointsToPixel(int _points);
protected:
    CDPISetting();
    bool _Init();
private:
    int m_dpiX;
    int m_dpiY;
    int m_dpiBaseLine;

    int m_resolutionX;
    int m_resolutionY;
    bool m_initialized;
    static CDPISetting* s_instance;
};

#endif // _ACA74D7A_2695_42C0_8B90_0B00EF16ABBE_H_
