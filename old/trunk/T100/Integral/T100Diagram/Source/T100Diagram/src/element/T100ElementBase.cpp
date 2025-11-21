#include "T100ElementBase.h"

#include "T100DiagramInvoking.h"

T100ElementBase::T100ElementBase()
{
    //ctor
}

T100ElementBase::~T100ElementBase()
{
    //dtor
}

T100VOID T100ElementBase::SetName(T100WSTRING name)
{
    m_name  = name;
}

T100WSTRING& T100ElementBase::GetName()
{
    return m_name;
}

T100UINT T100ElementBase::GetType()
{
    return m_type;
}

T100VOID T100ElementBase::SetOriginX(T100UINT value)
{
    m_originX   = value;
}

T100UINT T100ElementBase::GetOriginX()
{
    return m_originX;
}

T100VOID T100ElementBase::SetOriginY(T100UINT value)
{
    m_originY   = value;
}

T100UINT T100ElementBase::GetOriginY()
{
    return m_originY;
}

T100VOID T100ElementBase::SetCentroidX(T100UINT value)
{
    m_centroidX     = value;
}

T100UINT T100ElementBase::GetCentroidX()
{
    return m_centroidX;
}

T100VOID T100ElementBase::SetCentroidY(T100UINT value)
{
    m_centroidY     = value;
}

T100UINT T100ElementBase::GetCentroidY()
{
    return m_centroidY;
}

T100VOID T100ElementBase::SetIndex(T100UINT index)
{
    m_index     = index;
}

T100UINT T100ElementBase::GetIndex()
{
    return m_index;
}

T100VOID T100ElementBase::Move(T100UINT x, T100UINT y)
{
    m_originX   = x;
    m_originY   = y;

    T100DiagramInvoking::OnModified();
}

T100BOOL T100ElementBase::CrossPoint(T100UINT x1, T100UINT y1, T100UINT x2, T100UINT y2,
                                T100UINT x3, T100UINT y3, T100UINT x4, T100UINT y4,
                                T100UINT& x, T100UINT& y)
{
    T100BOOL    result      = T100FALSE;
    T100INT     a1, b1, c1;
    T100INT     a2, b2, c2;

    a1  = y2 - y1;
    b1  = x1 - x2;
    c1  = x2 * y1 - x1 * y2;

    a2  = y4 - y3;
    b2  = x3 - x4;
    c2 = x4 * y3 - x3 * y4;

    T100INT     d;

    d = a1 * b2 - a2 * b1;

    if(d == 0){
        return T100FALSE;
    }else{
        result  = T100TRUE;
    }

    x   = (b1 * c2 - b2 * c1) / d;
    y   = (a2 * c1 - a1 * c2) / d;

    return result;
}

T100BOOL T100ElementBase::OnLine(T100UINT x1, T100UINT y1, T100UINT x2, T100UINT y2,
                                T100UINT x3, T100UINT y3, T100UINT x4, T100UINT y4,
                                T100UINT& x, T100UINT& y)
{
    if(x1 < x2){
        if(x < x1 || x > x2){
            return T100FALSE;
        }
    }else{
        if(x > x1 || x < x2){
            return T100FALSE;
        }
    }
    if(x3 < x4){
        if(x < x3 || x > x4){
            return T100FALSE;
        }
    }else{
        if(x > x3 || x < x4){
            return T100FALSE;
        }
    }
    if(y1 < y2){
        if(y < y1 || y > y2){
            return T100FALSE;
        }
    }else{
        if(y > y1 || y < y2){
            return T100FALSE;
        }
    }
    if(y3 < y4){
        if(y < y3 || y > y4){
            return T100FALSE;
        }
    }else{
        if(y > y3 || y < y4){
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100ElementBase::Arrow(T100UINT x1, T100UINT y1, T100UINT x2, T100UINT y2,
                                T100UINT& a1, T100UINT& b1, T100UINT& a2, T100UINT& b2,
                                T100UINT& a3, T100UINT& b3)
{
    T100INT     x, y;
    T100INT     a, b;
    T100FLOAT   d;

    x   = (x1 - x2);
    y   = (y1 - y2);

    d   = 20 / sqrt(x * x + y * y);

    x   = x * d;
    y   = y * d;

    a   = x * cos(3.14 / 6) - y * sin(3.14 / 6);
    b   = x * sin(3.14 / 6) + y * cos(3.14 / 6);

    a1  = a + x2;
    b1  = b + y2;

    a   = x * cos(-3.14 / 6) - y * sin(-3.14 / 6);
    b   = x * sin(-3.14 / 6) + y * cos(-3.14 / 6);

    a2  = a + x2;
    b2  = b + y2;

    a3  = x2;
    b3  = y2;

    return T100TRUE;
}
