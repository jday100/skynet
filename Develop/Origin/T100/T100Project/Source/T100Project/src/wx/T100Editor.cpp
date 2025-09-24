#include "T100Editor.h"

#include "T100ProjectConfig.h"
#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100Editor, wxStyledTextCtrl)

END_EVENT_TABLE()

T100Editor::T100Editor(wxWindow *parent, wxWindowID id,
                     const wxPoint& pos,
                     const wxSize& size, long style,
                     const wxString& name) :
    wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    //ctor
    init();
}

T100Editor::~T100Editor()
{
    //dtor
    uninit();
}

T100VOID T100Editor::init()
{
    m_flag      = T100FALSE;

    SetMarginWidth(0, 50);

    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, T100ProjectConfig::T100PROJECT_EDITOR_FONT, wxFONTENCODING_DEFAULT);

    StyleSetFont(wxSTC_STYLE_DEFAULT, font);

    SetTabWidth(4);
    SetUseTabs(T100FALSE);
    SetTabIndents(T100TRUE);
    SetBackSpaceUnIndents(T100TRUE);

    Connect(wxID_ANY, wxEVT_STC_MODIFIED, (wxObjectEventFunction)&T100Editor::OnModified);
}

T100VOID T100Editor::uninit()
{
    Disconnect(wxID_ANY, wxEVT_STC_MODIFIED);
}

T100VOID T100Editor::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100Editor::GetPath()
{
    return m_path;
}

T100VOID T100Editor::Lock()
{
    m_flag      = T100TRUE;
    Disconnect(wxID_ANY, wxEVT_STC_MODIFIED);
}

T100VOID T100Editor::Unlock()
{
    m_flag      = T100FALSE;
    Connect(wxID_ANY, wxEVT_STC_MODIFIED, (wxObjectEventFunction)&T100Editor::OnModified);
}

T100VOID T100Editor::OnModified(wxStyledTextEvent& event)
{
    if(m_flag){
        m_flag      = T100FALSE;
    }else{
        T100ProjectInvoking::OnModified(m_path);
    }
}
