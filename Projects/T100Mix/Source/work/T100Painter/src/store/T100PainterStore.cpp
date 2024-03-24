#include "T100PainterStore.h"

#include "callback\T100Callback.h"
#include "fs\file\T100FileBufferedReader.h"
#include "wx\paint\element\T100PaintElementBase.h"


T100PainterStore::T100PainterStore()
{
    //ctor
    create();
}

T100PainterStore::~T100PainterStore()
{
    //dtor
    destroy();
}

T100VOID T100PainterStore::create()
{
    m_diagram_drawer    = T100NEW T100DiagramDrawer();
}

T100VOID T100PainterStore::destroy()
{
    T100SAFE_DELETE(m_diagram_drawer)
}

T100BOOL T100PainterStore::Save()
{

}

T100BOOL T100PainterStore::OpenFile()
{

}

T100BOOL T100PainterStore::SaveFile()
{

}
