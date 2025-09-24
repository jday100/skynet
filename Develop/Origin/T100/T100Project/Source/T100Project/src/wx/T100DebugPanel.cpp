#include "T100DebugPanel.h"

#include "T100ProjectCommon.h"

BEGIN_EVENT_TABLE(T100DebugPanel, wxTextCtrl)
    EVT_RIGHT_DOWN(OnMouseRightDown)
    EVT_MENU(T100PROJECT_DEBUG_MENU_CLEAR, OnClear)
END_EVENT_TABLE()

T100DebugPanel::T100DebugPanel(wxWindow *parent, wxWindowID id,
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

T100DebugPanel::~T100DebugPanel()
{
    //dtor
}

T100BOOL T100DebugPanel::Append(const T100WSTRING& value)
{
    AppendText(value);
    AppendText(L"\n");
}

T100VOID T100DebugPanel::OnMouseRightDown(wxMouseEvent& event)
{
    wxMenu*         menu    = T100NEW wxMenu();

    menu->Append(T100PROJECT_DEBUG_MENU_CLEAR, L"Clear");

    PopupMenu(menu);
}

T100VOID T100DebugPanel::OnClear(wxCommandEvent& event)
{
    Clear();
}
