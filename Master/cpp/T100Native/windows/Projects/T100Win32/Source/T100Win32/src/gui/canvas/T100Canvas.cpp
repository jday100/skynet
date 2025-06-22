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
    init(parent, &T100CanvasStyle());
}

T100Canvas::~T100Canvas()
{
    //dtor
    uninit();
}

T100VOID T100Canvas::init(T100Window* parent, T100CanvasStyle* style)
{
    T100Panel::Create(parent, style);
}

T100VOID T100Canvas::uninit()
{

}

T100VOID T100Canvas::Create(T100Window* parent, T100CanvasStyle* style)
{
    if(style){
        m_style     = *style;
        init(parent, style);
    }else{
        T100CanvasStyle     thisStyle;
        m_style     = thisStyle;
        init(parent, &thisStyle);
    }
}

T100VOID T100Canvas::Destroy()
{
    T100Panel::Destroy();
}

}
