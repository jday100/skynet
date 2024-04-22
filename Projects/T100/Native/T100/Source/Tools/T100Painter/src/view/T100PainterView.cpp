#include "T100PainterView.h"

#include <wx/filedlg.h>
#include "T100PainterMain.h"

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
    m_frame             = T100NEW T100PainterFrame(T100NULL);
    m_canvas            = T100NEW T100Canvas(m_frame);
    m_elements_panel    = T100NEW T100PainterElementsPanel(m_frame);

    m_frame->getAuiManager()->AddPane(m_elements_panel, wxAuiPaneInfo().Name(wxT("Elements")).BestSize(300, -1).Left());
    m_frame->getAuiManager()->AddPane(m_canvas, wxAuiPaneInfo().Name(wxT("Canvas")).DefaultPane().CenterPane());
    m_frame->getAuiManager()->Update();
}

T100VOID T100PainterView::destroy()
{
    T100DELETE  m_frame;
}

T100BOOL T100PainterView::show()
{
    return m_frame->Show();
}

T100Canvas* T100PainterView::getCanvas()
{
    return m_canvas;
}

T100PainterFrame* T100PainterView::getFrame()
{
    return m_frame;
}

T100PainterElementsPanel* T100PainterView::getElementsPanel()
{
    return m_elements_panel;
}

T100BOOL T100PainterView::Open(T100STRING& filename)
{
    T100STRING          file;
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename    = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T100PainterView::SaveAs(T100STRING& filename)
{
    T100STRING          file;
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename    = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}
