#include "T100GroupedEntryDrawer.h"

T100GroupedEntryDrawer::T100GroupedEntryDrawer()
{
    //ctor
    create();
}

T100GroupedEntryDrawer::~T100GroupedEntryDrawer()
{
    //dtor
    destroy();
}

T100VOID T100GroupedEntryDrawer::create()
{

}

T100VOID T100GroupedEntryDrawer::destroy()
{

}

T100VOID T100GroupedEntryDrawer::setGrouper(T100Grouper* grouper)
{
    m_grouper   = grouper;
}

T100Grouper* T100GroupedEntryDrawer::getGrouper()
{
    return m_grouper;
}

T100BOOL T100GroupedEntryDrawer::append(T100Entry* entry)
{

}

T100BOOL T100GroupedEntryDrawer::remove(T100Entry* entry)
{

}
