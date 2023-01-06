#include "T100ElementCircle.h"

#include "T100Planimetry.h"
#include "T100ElementCommon.h"

#include "T100TestTools.h"


namespace T100Painter{

T100ElementCircle::T100ElementCircle()
    :T100ElementBase()
{
    //ctor
    create();
}

T100ElementCircle::~T100ElementCircle()
{
    //dtor
    destroy();
}

T100VOID T100ElementCircle::create()
{
    m_name  = L"Circle";
    m_label = L"Circle";
    m_key   = L"elements.circle";
    m_type  = T100ELEMENT_CIRCLE;
}

T100VOID T100ElementCircle::destroy()
{

}

T100VOID T100ElementCircle::Clear()
{
    m_origin_x  = 0;
    m_origin_y  = 0;
    m_radius    = 0;
}

T100BOOL T100ElementCircle::draw(wxDC& dc)
{
    /*
    T100Library::T100TestTools::Print(&m_origin_x);
    T100Library::T100TestTools::Print(&m_origin_y);
    T100Library::T100TestTools::Print(&m_radius);
    */

    dc.DrawCircle(m_origin_x, m_origin_y, m_radius);
}

T100ElementCircle* T100ElementCircle::Clone()
{
    T100ElementCircle*      result          = T100NULL;

    result = T100NEW T100ElementCircle();

    if(result){
        *result = *this;
    }

    return result;
}

T100BOOL T100ElementCircle::Hit(T100INT x, T100INT y)
{
    T100FLOAT   result;

    result = T100Math::T100Planimetry::Dist(m_origin_x, m_origin_y, x, y);

    if(result <= m_radius){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ElementCircle::MouseLeftDown(T100INT x, T100INT y)
{
    m_origin_x  = x;
    m_origin_y  = y;

    return T100TRUE;
}

T100BOOL T100ElementCircle::MouseLeftUp(T100INT x, T100INT y)
{
    m_target_x  = x;
    m_target_y  = y;

    m_radius    = T100Math::T100Planimetry::Dist(m_origin_x, m_origin_y, m_target_x, m_target_y);

    return T100TRUE;
}

T100BOOL T100ElementCircle::MouseMove(T100INT x, T100INT y)
{
    m_target_x  = x;
    m_target_y  = y;

    m_radius    = T100Math::T100Planimetry::Dist(m_origin_x, m_origin_y, m_target_x, m_target_y);

    return T100TRUE;
}

T100BOOL T100ElementCircle::Update(wxListView* panel)
{
    T100LONG        parent;
    T100LONG        index;
    wxUIntPtr       ptr;

    parent  = panel->GetItemCount();

    index   = panel->InsertItem(parent, L"Circle");
}

}
