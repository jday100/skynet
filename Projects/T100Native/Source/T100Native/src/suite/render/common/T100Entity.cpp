#include "T100Entity.h"

T100Entity::T100Entity()
{
    //ctor
}

T100Entity::~T100Entity()
{
    //dtor
}

T100FACET_VECTOR& T100Entity::GetFacets()
{
    return m_facets;
}

T100VOID T100Entity::SetOrigin(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_origin_x  = x;
    m_origin_y  = y;
    m_origin_z  = z;
}
