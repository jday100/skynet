#include "T100PainterView.h"

#include <wx/filedlg.h>
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

///

T100BOOL T100PainterView::OpenFile(T100STRING& file)
{
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    file = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T100PainterView::LoadFile(T100PAINTER_ELEMENT_VECTOR* elements)
{
    m_paint->Load(elements);
    m_paint->Refresh();
    return T100TRUE;
}

}
