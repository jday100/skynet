#include "T100EditorView.h"

#include "T100EditorFrame.h"

namespace T100Editor{

T100EditorView::T100EditorView()
{
    //ctor
}

T100EditorView::~T100EditorView()
{
    //dtor
    destroy();
}

T100BOOL T100EditorView::create()
{
    if(m_parent){
        m_edit      = T100NEW T100WxWidgets::T100EditCtrl(m_parent);
    }else{
        m_frame     = T100NEW T100EditorFrame(T100NULL);
        m_edit      = T100NEW T100WxWidgets::T100EditCtrl(m_frame);
    }
    return T100TRUE;
}

T100VOID T100EditorView::destroy()
{
    T100SAFE_DELETE(m_frame);
}

T100VOID T100EditorView::setParent(wxWindow* parent)
{
    m_parent = parent;
}

T100WxWidgets::T100EditCtrl* T100EditorView::getEditCtrl()
{
    return m_edit;
}

T100VOID T100EditorView::show()
{
    if(m_frame){
        m_frame->Show();
    }
}

}
