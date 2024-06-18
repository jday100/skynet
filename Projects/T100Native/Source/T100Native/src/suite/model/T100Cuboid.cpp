#include "T100Cuboid.h"

T100Cuboid::T100Cuboid()
    :T100Entity()
{
    //ctor
}

T100Cuboid::~T100Cuboid()
{
    //dtor
}

T100VOID T100Cuboid::Create(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    T100Facet*  face11      = T100NEW T100Facet();
    T100Facet*  face12      = T100NEW T100Facet();
    T100Facet*  face21      = T100NEW T100Facet();
    T100Facet*  face22      = T100NEW T100Facet();
    T100Facet*  face31      = T100NEW T100Facet();
    T100Facet*  face32      = T100NEW T100Facet();
    T100Facet*  face41      = T100NEW T100Facet();
    T100Facet*  face42      = T100NEW T100Facet();
    T100Facet*  face51      = T100NEW T100Facet();
    T100Facet*  face52      = T100NEW T100Facet();
    T100Facet*  face61      = T100NEW T100Facet();
    T100Facet*  face62      = T100NEW T100Facet();

    T100FLOAT       hx, hy, hz;

    hx  = x / 2.0;
    hy  = y / 2.0;
    hz  = z / 2.0;

    face11->m_x.SetValue(-hx, hy, hz);
    face11->m_y.SetValue(hx, hy, hz);
    face11->m_z.SetValue(hx, -hy, hz);

    face12->m_x.SetValue(-hx, hy, hz);
    face12->m_y.SetValue(hx, -hy, hz);
    face12->m_z.SetValue(-hx, -hy, hz);

    face21->m_x.SetValue(hx, hy, hz);
    face21->m_y.SetValue(hx, hy, hz);
    face21->m_z.SetValue(hx, hy, hz);

    face22->m_x.SetValue(hx, hy, hz);
    face22->m_y.SetValue(hx, hy, hz);
    face22->m_z.SetValue(hx, hy, hz);

    face31->m_x.SetValue(hx, hy, hz);
    face31->m_y.SetValue(hx, hy, hz);
    face31->m_z.SetValue(hx, hy, hz);

    face32->m_x.SetValue(hx, hy, hz);
    face32->m_y.SetValue(hx, hy, hz);
    face32->m_z.SetValue(hx, hy, hz);

    face41->m_x.SetValue(hx, hy, hz);
    face41->m_y.SetValue(hx, hy, hz);
    face41->m_z.SetValue(hx, hy, hz);

    face42->m_x.SetValue(hx, hy, hz);
    face42->m_y.SetValue(hx, hy, hz);
    face42->m_z.SetValue(hx, hy, hz);

    face51->m_x.SetValue(hx, hy, hz);
    face51->m_y.SetValue(hx, hy, hz);
    face51->m_z.SetValue(hx, hy, hz);

    face52->m_x.SetValue(hx, hy, hz);
    face52->m_y.SetValue(hx, hy, hz);
    face52->m_z.SetValue(hx, hy, hz);

    face61->m_x.SetValue(hx, hy, hz);
    face61->m_y.SetValue(hx, hy, hz);
    face61->m_z.SetValue(hx, hy, hz);

    face62->m_x.SetValue(hx, hy, hz);
    face62->m_y.SetValue(hx, hy, hz);
    face62->m_z.SetValue(hx, hy, hz);

    m_facets.push_back(face11);
    m_facets.push_back(face12);
    m_facets.push_back(face21);
    m_facets.push_back(face22);
    m_facets.push_back(face31);
    m_facets.push_back(face32);
    m_facets.push_back(face41);
    m_facets.push_back(face42);
    m_facets.push_back(face51);
    m_facets.push_back(face52);
    m_facets.push_back(face61);
    m_facets.push_back(face62);
}

T100VOID T100Cuboid::Destroy()
{

}
