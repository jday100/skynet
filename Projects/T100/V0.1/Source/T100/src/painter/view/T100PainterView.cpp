#include "T100PainterView.h"

#include "T100PainterFrame.h"

namespace T100Painter{

T100PainterView::T100PainterView()
{
    //ctor
}

T100PainterView::~T100PainterView()
{
    //dtor
    destroy();
}

T100BOOL T100PainterView::create()
{
    if(m_parent){
        m_paint     = T100NEW T100WxWidgets::T100PaintCtrl(m_paint);
    }else{
        m_frame     = T100NEW T100PainterFrame(T100NULL);
        m_paint     = T100NEW T100WxWidgets::T100PaintCtrl(m_frame);
    }

    return T100TRUE;
}

T100VOID T100PainterView::destroy()
{
    T100SAFE_DELETE(m_frame);
}

T100VOID T100PainterView::setParent(wxWindow* parent)
{
    m_parent = parent;
}

T100VOID T100PainterView::show()
{
    if(m_frame){
        m_frame->Show();
    }
}

}
