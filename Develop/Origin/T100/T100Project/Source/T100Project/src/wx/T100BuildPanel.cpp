#include "T100BuildPanel.h"

#include "T100ProjectCommon.h"

BEGIN_EVENT_TABLE(T100BuildPanel, wxTextCtrl)
    EVT_RIGHT_DOWN(OnMouseRightDown)
    EVT_MENU(T100PROJECT_EDITOR_MENU_CLEAR, OnClear)
END_EVENT_TABLE()

T100BuildPanel::T100BuildPanel(wxWindow *parent,
               wxWindowID id,
               const wxString& value,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name) :
    wxTextCtrl(parent, id, value, pos, size, style, validator, name)
{
    //ctor
    init();
}

T100BuildPanel::~T100BuildPanel()
{
    //dtor
    uninit();
}

T100VOID T100BuildPanel::init()
{

}

T100VOID T100BuildPanel::uninit()
{

}

T100VOID T100BuildPanel::OnMouseRightDown(wxMouseEvent& event)
{
    wxMenu*         menu    = T100NEW wxMenu();

    menu->Append(T100PROJECT_EDITOR_MENU_CLEAR, L"Clear");

    PopupMenu(menu);
}

T100VOID T100BuildPanel::OnClear(wxCommandEvent& event)
{
    Clear();
}

T100BOOL T100BuildPanel::Append(const T100WSTRING& value)
{
    AppendText(value);
    AppendText(L"\n");
}

