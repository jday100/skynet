#include "link/T100Entity.h"

T100Entity::T100Entity() :
    T1003DMesh(),
    m_colour(255, 255, 255, 0)
{
    //ctor
}

T100Entity::~T100Entity()
{
    //dtor
}

T100VOID T100Entity::SetColour(T100UINT8 red, T100UINT8 green, T100UINT8 blue, T100UINT8 alpha)
{
    m_colour    = {red, green, blue, alpha};
}

T100VOID T100Entity::SetColour(T100Vector4u& value)
{
    m_colour    = value;
}

T100Vector4u& T100Entity::GetColour()
{
    return m_colour;
}
