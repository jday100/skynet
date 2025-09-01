#include "T100Editor.h"

#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100Editor, wxStyledTextCtrl)
    EVT_STC_MODIFIED(wxID_ANY, OnModified)
END_EVENT_TABLE()

T100Editor::T100Editor(wxWindow *parent,
                        wxWindowID id,
                        const wxPoint& pos,
                        const wxSize& size,
                        long style,
                        const wxString& name) :
    wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

T100VOID T100Editor::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100Editor::GetPath()
{
    return m_path;
}

T100VOID T100Editor::OnModified(wxStyledTextEvent& event)
{
    T100ProjectInvoking::OnModified(m_path);
}
