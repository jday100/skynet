#include "T100WPainterStore.h"

#include "T100Diagram.h"

T100WPainterStore::T100WPainterStore()
{
    //ctor
}

T100WPainterStore::~T100WPainterStore()
{
    //dtor
}

T100BOOL T100WPainterStore::Load(T100STRING file, T100DiagramInfo& info)
{
    T100Diagram         diagram;

    diagram.load(file, info);
}

T100BOOL T100WPainterStore::Save(T100STRING file, T100DiagramInfo& info)
{
    T100Diagram         diagram;

    diagram.save(file, info);
}
