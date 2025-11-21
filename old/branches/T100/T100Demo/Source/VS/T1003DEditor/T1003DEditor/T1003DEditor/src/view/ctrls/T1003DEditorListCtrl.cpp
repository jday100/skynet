#include "view/ctrls/T1003DEditorListCtrl.h"

#include "skeletal/T1003DEditorCallback.h"

BEGIN_EVENT_TABLE(T1003DEditorListCtrl,wxListCtrl)
    EVT_LIST_ITEM_SELECTED(wxID_ANY, T1003DEditorListCtrl::OnItemSelected)
    EVT_LIST_ITEM_DESELECTED(wxID_ANY, T1003DEditorListCtrl::OnItemDeselected)
    EVT_RIGHT_DOWN(T1003DEditorListCtrl::OnMouseRightDown)
END_EVENT_TABLE()

T1003DEditorListCtrl::T1003DEditorListCtrl(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name) :
    wxListCtrl(parent, id, pos, size, style, validator, name)
{
    //ctor
}

T1003DEditorListCtrl::~T1003DEditorListCtrl()
{
    //dtor
}

void T1003DEditorListCtrl::OnItemSelected(wxListEvent& event)
{

}

void T1003DEditorListCtrl::OnItemDeselected(wxListEvent& event)
{

}

void T1003DEditorListCtrl::OnMouseRightDown(wxMouseEvent& event)
{
    T1003DEditorCallback::Cancel();
}
