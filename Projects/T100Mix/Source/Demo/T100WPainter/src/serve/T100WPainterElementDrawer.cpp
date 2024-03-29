#include "T100WPainterElementDrawer.h"

#include "T100ElementCircle.h"

T100WPainterElementDrawer::T100WPainterElementDrawer()
{
    //ctor
}

T100WPainterElementDrawer::~T100WPainterElementDrawer()
{
    //dtor
}

T100ElementBase* T100WPainterElementDrawer::Create()
{
    return T100NEW T100ElementCircle();
}
