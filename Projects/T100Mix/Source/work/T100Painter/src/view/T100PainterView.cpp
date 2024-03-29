#include "T100PainterView.h"

#include <wx/filedlg.h>

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
    m_frame = T100NEW T100PainterFrame(0);
}

T100VOID T100PainterView::destroy()
{
    T100SAFE_DELETE(m_frame)
}

T100VOID T100PainterView::show()
{
    if(m_frame){
        m_frame->Show();
    }
}

wxFrame* T100PainterView::getFrame()
{
    return m_frame;
}

T100BOOL T100PainterView::Open()
{
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    //file = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}
