#include "T100PainterServe.h"

T100PainterServe::T100PainterServe()
{
    //ctor
    create();
}

T100PainterServe::~T100PainterServe()
{
    //dtor
    destroy();
}

T100VOID T100PainterServe::create()
{
    m_entry_drawer  = T100NEW T100PainterEntryDrawer();
}

T100VOID T100PainterServe::destroy()
{
    T100SAFE_DELETE(m_entry_drawer)
}

T100PainterEntryDrawer* T100PainterServe::getEntryDrawer()
{
    return m_entry_drawer;
}

T100BOOL T100PainterServe::Clear()
{

}

T100BOOL T100PainterServe::Opened()
{

}

T100BOOL T100PainterServe::Saved()
{

}

T100BOOL T100PainterServe::Modified()
{

}
