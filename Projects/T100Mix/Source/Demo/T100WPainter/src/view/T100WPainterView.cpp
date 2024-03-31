#include "T100WPainterView.h"

#include <wx/filedlg.h>
#include "T100WPainterMain.h"

T100WPainterView::T100WPainterView()
{
    //ctor
    create();
}

T100WPainterView::~T100WPainterView()
{
    //dtor
    destroy();
}

T100VOID T100WPainterView::create()
{
    m_frame             = T100NEW T100WPainterFrame(0);
    //m_elements_panel    = T100NEW T100WPainterElementsPanel(m_frame);
}

T100VOID T100WPainterView::destroy()
{

}

T100BOOL T100WPainterView::show()
{
    return m_frame->Show();
}

T100WPainterFrame* T100WPainterView::getFrame()
{
    return m_frame;
}

T100WPainterCanvas* T100WPainterView::getCanvas()
{
    return m_frame->getCanvas();
}

T100BOOL T100WPainterView::Open()
{
    T100STRING          file;
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    file = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T100WPainterView::SaveAs(T100STRING& filename)
{
    T100STRING          file;
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename    = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}
