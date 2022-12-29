#include "T100ElementCircle.h"

namespace T100Painter{

T100ElementCircle::T100ElementCircle()
    :T100ElementBase()
{
    //ctor
}

T100ElementCircle::~T100ElementCircle()
{
    //dtor
}

T100BOOL T100ElementCircle::draw(wxDC& dc)
{
    dc.DrawCircle(100, 100, 10);
}

}
