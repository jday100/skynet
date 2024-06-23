#include "T100SoftSpace.h"

T100SoftSpace::T100SoftSpace()
    :T100SpaceBase()
{
    //ctor
}

T100SoftSpace::~T100SoftSpace()
{
    //dtor
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
