#include "T100ElementRectangle.h"

#include "T100Planimetry.h"
#include "T100ElementCommon.h"

namespace T100Painter{

T100ElementRectangle::T100ElementRectangle()
    :T100ElementBase()
{
    //ctor
    create();
}

T100ElementRectangle::~T100ElementRectangle()
{
    //dtor
    destroy();
}

T100VOID T100ElementRectangle::create()
{
    m_name  = L"Rectangle";
    m_label = L"Rectangle";
    m_panel = L"Graphic";
    m_key   = L"elements.rectangle";
    m_type  = T100ELEMENT_GRAPHICS_RECTANGLE;
}

T100VOID T100ElementRectangle::destroy()
{

}

T100VOID T100ElementRectangle::Clear()
{
    m_starting_x    = 0;
    m_starting_y    = 0;

    m_ending_x      = 0;
    m_ending_y      = 0;
}

T100BOOL T100ElementRectangle::draw(wxDC& dc)
{
    dc.DrawRectangle(wxRect(wxPoint(m_origin_x, m_origin_y), wxPoint(m_tail_x, m_tail_y)));
    return T100TRUE;
}

T100ElementRectangle* T100ElementRectangle::Clone()
{
    T100ElementRectangle*       result          = T100NULL;

    result = T100NEW T100ElementRectangle();

    if(result){
        *result = *this;
    }

    return result;
}

T100BOOL T100ElementRectangle::Hit(T100INT x, T100INT y)
{
    return T100Math::T100Planimetry::Hit(m_origin_x, m_origin_y, m_tail_x, m_tail_y, x, y);
}

T100BOOL T100ElementRectangle::PaintMove(T100INT x, T100INT y)
{
    m_tail_x        = x;
    m_tail_y        = y;
    m_ending_x      = x;
    m_ending_y      = y;

    return T100TRUE;
}

T100BOOL T100ElementRectangle::SelectedMove(T100INT x, T100INT y)
{
    T100INT     dx, dy;

    dx  = x - m_starting_x;
    dy  = y - m_starting_y;

    m_origin_x  += dx;
    m_origin_y  += dy;

    m_tail_x    += dx;
    m_tail_y    += dy;

    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

T100BOOL T100ElementRectangle::Update(wxPropertyGrid* panel)
{
    T100LONG        parent;
    T100LONG        index;
    wxUIntPtr       ptr;

}

T100VOID T100ElementRectangle::Position()
{
    m_origin_x      = m_starting_x;
    m_origin_y      = m_starting_y;
    m_tail_x        = m_ending_x;
    m_tail_y        = m_ending_y;
}

T100BOOL T100ElementRectangle::Move()
{
    T100INT     dx, dy;

    dx  = m_ending_x - m_starting_x;
    dy  = m_ending_y - m_starting_y;

    m_origin_x  = m_origin_x + dx;
    m_origin_y  = m_origin_y + dy;

    m_tail_x    = m_tail_x  + dx;
    m_tail_y    = m_tail_y  + dy;

    m_starting_x    = m_ending_x;
    m_starting_y    = m_ending_y;

    return T100TRUE;
}

T100BOOL T100ElementRectangle::SetPaintStarting(T100INT x, T100INT y)
{
    m_origin_x      = x;
    m_origin_y      = y;

    m_tail_x        = x;
    m_tail_y        = y;

    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

}
