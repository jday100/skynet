#include "T100CompilePanel.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100CompilePanel, wxTextCtrl)
    EVT_RIGHT_DOWN(OnMouseRightDown)
    EVT_MENU(T100PROJECT_EDITOR_MENU_CLEAR, OnClear)
END_EVENT_TABLE()

T100CompilePanel::T100CompilePanel(wxWindow *parent,
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
}

T100CompilePanel::~T100CompilePanel()
{
    //dtor
}

T100BOOL T100CompilePanel::Append(const T100WSTRING& value)
{
    AppendText(value);
    AppendText(L"\n");
}

T100VOID T100CompilePanel::OnMouseRightDown(wxMouseEvent& event)
{
    wxMenu*         menu    = T100NEW wxMenu();

    menu->Append(T100PROJECT_EDITOR_MENU_CLEAR, L"Clear");

    PopupMenu(menu);
}

T100VOID T100CompilePanel::OnClear(wxCommandEvent& event)
{
    Clear();
}
