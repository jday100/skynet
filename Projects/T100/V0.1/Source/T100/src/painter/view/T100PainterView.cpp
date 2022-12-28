#include "T100PainterView.h"

#include "T100PainterFrame.h"

namespace T100Painter{

T100PainterView::T100PainterView()
{
    //ctor
    create();
}

T100PainterView::~T100PainterView()
{
    //dtor
    destroy();
}

T100VOID T100PainterView::create()
{
    m_frame     = T100NEW T100PainterFrame(T100NULL);

}

T100VOID T100PainterView::destroy()
{

}

T100VOID T100PainterView::show()
{
    if(m_frame){
        m_frame->Show();
    }
}

}
