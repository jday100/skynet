#include "T100SoftSpace.h"

T100SoftSpace::T100SoftSpace()
    :T100SpaceBase()
{
    //ctor
    TurnOn();
}

T100SoftSpace::~T100SoftSpace()
{
    //dtor
    TurnOff();
}

T100VOID T100SoftSpace::TurnOn()
{
    m_space.DATA.DATA4[0][0]    = 1;
    m_space.DATA.DATA4[1][1]    = 1;
    m_space.DATA.DATA4[2][2]    = 1;
    m_space.DATA.DATA4[3][3]    = 1;

    m_translate.DATA.DATA4[0][0]    = 1;
    m_translate.DATA.DATA4[1][1]    = 1;
    m_translate.DATA.DATA4[2][2]    = 1;
    m_translate.DATA.DATA4[3][3]    = 1;
}

T100VOID T100SoftSpace::TurnOff()
{

}

T100VOID T100SoftSpace::SetSpaceMatrix(T100Matrix4& matrix)
{
    m_space = matrix;
}

T100Matrix4& T100SoftSpace::GetSpaceMatrix()
{
    return m_space;
}

T100Point T100SoftSpace::Translate(T100Point& source, T100FLOAT x, T100FLOAT y, T100FLOAT z)
{

}

T100Point T100SoftSpace::RevolveX(T100Point& source, T100FLOAT x)
{

}

T100Point T100SoftSpace::RevolveY(T100Point& source, T100FLOAT y)
{

}

T100Point T100SoftSpace::RevolveZ(T100Point& source, T100FLOAT z)
{

}

T100Point T100SoftSpace::Space(T100Point& dot)
{
    return m_space * dot;
}

T100VOID T100SoftSpace::Translate(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_translate.DATA.DATA4[3][0]  += x;
    m_translate.DATA.DATA4[3][1]  += y;
    m_translate.DATA.DATA4[3][2]  += z;

    m_space = m_space * m_translate;
}
