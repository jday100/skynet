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
    init();
}

T100Editor::~T100Editor()
{
    //dtor
    uninit();
}

T100VOID T100Editor::init()
{
    SetMarginWidth(0,  50);

    //wxFont font(10, wxDEFAULT, wxNORMAL, wxNORMAL);
    wxFont font(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("MV Boli"),wxFONTENCODING_DEFAULT);

    StyleSetFont(wxSTC_STYLE_DEFAULT, font);
}

T100VOID T100Editor::uninit()
{

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
