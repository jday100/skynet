#include "T100SoftRasterize.h"

T100SoftRasterize::T100SoftRasterize()
    :T100RasterizeBase()
{
    //ctor
}

T100SoftRasterize::~T100SoftRasterize()
{
    //dtor
}

T100VOID T100SoftRasterize::SetRender(T100RenderBase* render)
{
    m_render    = render;
}

T100RenderBase* T100SoftRasterize::GetRender()
{
    return m_render;
}

T100VOID T100SoftRasterize::SetSize(T100INT width, T100INT height)
{
    m_width     = width;
    m_height    = height;
}

T100VOID T100SoftRasterize::Draw()
{
    for(int n = 0;n < m_height;n++){
        for(int m = 0;m < m_width;m++){
            Pyramid(m, n);
        }
    }
}

T100VOID T100SoftRasterize::Pyramid(T100INT x, T100INT y)
{
    T100ENTITY_VECTOR&          entities        = m_render->GetEntities();

    for(T100Entity* entity : entities){
        if(entity){
            for(T100Facet* facet : entity->GetFacets()){
                if(facet){
                    CrossPoint();
                }
            }
        }
    }
}

T100VOID T100SoftRasterize::CrossPoint()
{

}
