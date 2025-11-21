#include "T100ElementModule.h"

#include "T100DiagramCommon.h"

T100ElementModule::T100ElementModule() :
    T100ElementBase()
{
    //ctor
    init();
}

T100ElementModule::~T100ElementModule()
{
    //dtor
    uninit();
}

T100VOID T100ElementModule::init()
{
    m_type      = T100ELEMENT_MODULE;

    m_width     = 50;
    m_height    = 80;
}

T100VOID T100ElementModule::uninit()
{

}

T100BOOL T100ElementModule::Draw(wxDC& dc)
{
    Resize(dc);

    dc.DrawRectangle(m_originX, m_originY, m_width, m_height);

    wxString    name = m_name;

    dc.DrawText(name, m_nameX + 5, m_nameY);

    return T100TRUE;
}

T100BOOL T100ElementModule::Hit(T100INT x, T100INT y)
{
    T100FLOAT   x1, y1;
    T100FLOAT   x2, y2;

    T100FLOAT   sx, sy;
    T100FLOAT   ex, ey;

    sx  = m_originX;
    sy  = m_originY;
    ex  = m_originX + m_width;
    ey  = m_originY + m_height;

    if(sx <= ex){
        x1  = sx;
        x2  = ex;
    }else{
        x1  = ex;
        x2  = sx;
    }

    if(sy <= ey){
        y1  = sy;
        y2  = ey;
    }else{
        y1  = ey;
        y2  = sy;
    }

    if(x >= x1 && x <= x2 && y >= y1 && y <= y2){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ElementModule::Edit(wxWindow* parent)
{

}

T100BOOL T100ElementModule::Cross(T100UINT cx, T100UINT cy, T100UINT& x, T100UINT& y)
{
    T100BOOL    result;

    result  = CrossPoint(m_originX, m_originY, m_originX, m_tailY, cx, cy, m_centroidX, m_centroidY, x, y);

    if(result){
        result  = OnLine(m_originX, m_originY, m_originX, m_tailY, cx, cy, m_centroidX, m_centroidY, x, y);
        if(result){
            return result;
        }
    }

    result  = CrossPoint(m_originX, m_originY, m_tailX, m_originY, cx, cy, m_centroidX, m_centroidY, x, y);

    if(result){
        result  = OnLine(m_originX, m_originY, m_tailX, m_originY, cx, cy, m_centroidX, m_centroidY, x, y);
        if(result){
            return result;
        }
    }

    result  = CrossPoint(m_tailX, m_originY, m_tailX, m_tailY, cx, cy, m_centroidX, m_centroidY, x, y);

    if(result){
        result  = OnLine(m_tailX, m_originY, m_tailX, m_tailY, cx, cy, m_centroidX, m_centroidY, x, y);
        if(result){
            return result;
        }
    }

    result  = CrossPoint(m_originX, m_tailY, m_tailX, m_tailY, cx, cy, m_centroidX, m_centroidY, x, y);

    if(result){
        result  = OnLine(m_originX, m_tailY, m_tailX, m_tailY, cx, cy, m_centroidX, m_centroidY, x, y);
        if(result){
            return result;
        }
    }

    return result;
}

T100VOID T100ElementModule::Resize(wxDC& dc)
{
    wxCoord     x   = 0;
    wxCoord     y   = 0;

    if(m_name.empty()){

    }else{
        dc.GetMultiLineTextExtent(m_name, &x, &y);
    }

    x += 10;

    m_width     = x > m_width ? x : m_width;
    m_height    = y > m_height ? y : m_height;

    m_nameX     = (m_width - x) / 2 + m_originX;
    m_nameY     = (m_height - y) / 2 + m_originY;

    m_tailX     = m_originX + m_width;
    m_tailY     = m_originY + m_height;

    m_centroidX = m_originX + m_width / 2;
    m_centroidY = m_originY + m_height / 2;
}
