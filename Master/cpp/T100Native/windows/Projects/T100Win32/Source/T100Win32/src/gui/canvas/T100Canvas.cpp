#include "T100Canvas.h"

namespace T100WINDOWS{

T100Canvas::T100Canvas() :
    T100Panel()
{
    //ctor
}

T100Canvas::T100Canvas(T100Window* parent) :
    T100Panel()
{
    //ctor
    init(parent);
}

T100Canvas::~T100Canvas()
{
    //dtor
    uninit();
}

T100VOID T100Canvas::init(T100Window* parent)
{

}

T100VOID T100Canvas::uninit()
{

}

T100VOID T100Canvas::Create(T100Window* parent, T100CanvasStyle* style)
{

}

T100VOID T100Canvas::Destroy()
{

}

}
