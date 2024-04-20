#include "T100PainterStore.h"

#include "T100Diagram.h"

T100PainterStore::T100PainterStore()
{
    //ctor
}

T100PainterStore::~T100PainterStore()
{
    //dtor
}

T100BOOL T100PainterStore::Load(T100STRING file, T100DiagramInfo& info)
{
    T100Diagram         diagram;

    return diagram.load(file, info);
}

T100BOOL T100PainterStore::Save(T100STRING file, T100DiagramInfo& info)
{
    T100Diagram         diagram;

    return diagram.save(file, info);
}
