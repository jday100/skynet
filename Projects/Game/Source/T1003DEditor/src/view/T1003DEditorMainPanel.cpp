#include "T1003DEditorMainPanel.h"

BEGIN_EVENT_TABLE(T1003DEditorMainPanel, wxPanel)
    EVT_PAINT(T1003DEditorMainPanel::OnPaint)
END_EVENT_TABLE()

T1003DEditorMainPanel::T1003DEditorMainPanel(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxString& name)
    :wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
}

T1003DEditorMainPanel::~T1003DEditorMainPanel()
{
    //dtor
}

T100VOID T1003DEditorMainPanel::setEditor(T1003DEditor* editor)
{
    m_editor = editor;
}

void T1003DEditorMainPanel::OnPaint(wxPaintEvent& event)
{
    m_editor->Render();
}
