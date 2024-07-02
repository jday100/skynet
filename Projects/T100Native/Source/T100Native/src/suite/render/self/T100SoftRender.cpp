#include "T100SoftRender.h"

#include <string.h>
#include "T100LinearAlgebra.h"
#include "T100Cuboid.h"
#include "T100SpaceGeometry.h"

T100SoftRender::T100SoftRender()
    :T100RenderBase(), m_entities(), m_space()
{
    //ctor
}

T100SoftRender::~T100SoftRender()
{
    //dtor
}

T100VOID T100SoftRender::Start()
{

}

T100VOID T100SoftRender::Stop()
{

}

T100VOID T100SoftRender::Draw()
{
    m_view_origin_x = m_view_width / 2;
    m_view_origin_y = m_view_height / 2;

    memset(m_screen, 0, m_length);

    for(int i=0;i<m_length;i+=4){
        m_screen[i]   = 255;
        m_screen[i+1] = 0;
        m_screen[i+2] = 0;
        m_screen[i+3] = 0;
    }

    T100INT         total;

    total   = m_entities.size();

    /*
    T100Cuboid*     cuboid      = T100NEW T100Cuboid();

    cuboid->Create(50, 50, 50);

    m_entities.push_back(cuboid);
    */

    for(T100Entity* entity : m_entities){
        if(entity){
            for(T100Facet* facet : entity->GetFacets()){
                if(facet){
                    DrawPoint(facet->m_a, 0);
                    DrawPoint(facet->m_b, 0);
                    DrawPoint(facet->m_c, 0);
                }
            }
        }
    }
}

T100VOID T100SoftRender::SetSize(T100INT width, T100INT height)
{
    m_view_width    = width;
    m_view_height   = height;
    m_length        = width * height * 4;
    m_screen        = T100NEW T100BYTE[m_length];
}

T100BYTE* T100SoftRender::GetData()
{
    return m_screen;
}

T100INT T100SoftRender::GetWidth()
{
    return m_view_width;
}

T100INT T100SoftRender::GetHeight()
{
    return m_view_height;
}

T100ENTITY_VECTOR& T100SoftRender::GetEntities()
{
    return m_entities;
}

T100LIGHT_VECTOR& T100SoftRender::GetLights()
{
    return m_lights;
}

T100CAMERA_VECTOR& T100SoftRender::GetCameras()
{
    return m_cameras;
}

T100VOID T100SoftRender::DrawPoint(T100Point& point, T100INT colour)
{
    T100INT         x, y;
    T100INT         value;

    T100Point       result;

    result  = m_space.Space(point);

    x   = result.m_x + m_view_origin_x;
    y   = result.m_y + m_view_origin_y;

    value   = (y * m_view_width + x) * 4;

    if(value < 0 || value >= m_length)return;

    m_screen[value++] = 0;
    m_screen[value++] = 255;
    m_screen[value++] = 0;
    m_screen[value++] = 0;
}

T100VOID T100SoftRender::Rotate(T100Point& source, T100Matrix4& matrix, T100Point& target)
{
    target  = matrix * source;
}

T100VOID T100SoftRender::Move(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    /*
    T100Matrix3         matrix      = T100SpaceGeometry::Translate(x, y, z);

    for(T100Entity* entity : m_entities){
        if(entity){
            for(T100Facet* facet : entity->GetFacets()){
                if(facet){
                    facet->m_x = facet->m_x * matrix;
                    facet->m_y = facet->m_y * matrix;
                    facet->m_z = facet->m_z * matrix;
                }
            }
        }
    }
    */

    m_space.Translate(x, y, z);
}

T100VOID T100SoftRender::Rotate(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    //m_space.RevolveX(x);
    //m_space.RevolveY(y);
    //m_space.RevolveZ(z);

    m_space.Revolve(x, y, z);
}

T100VOID T100SoftRender::Pyramid()
{

    for(T100Entity* entity : m_entities){
        if(entity){
            for(T100Facet* facet : entity->GetFacets()){
                if(facet){
                    DrawPoint(facet->m_a, 0);
                    DrawPoint(facet->m_b, 0);
                    DrawPoint(facet->m_c, 0);
                }
            }
        }
    }
}

