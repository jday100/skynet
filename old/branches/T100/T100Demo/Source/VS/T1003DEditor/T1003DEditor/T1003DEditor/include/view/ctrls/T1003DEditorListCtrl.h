#ifndef T1003DEDITORLISTCTRL_H
#define T1003DEDITORLISTCTRL_H

#include <wx/listctrl.h>
#include "T100Common.h"

class T1003DEditorListCtrl : public wxListCtrl
{
    public:
        T1003DEditorListCtrl(wxWindow *parent,
               wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxLC_ICON | wxLC_AUTOARRANGE,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxListCtrlNameStr);
        virtual ~T1003DEditorListCtrl();

    protected:
        void OnItemSelected(wxListEvent& event);
        void OnItemDeselected(wxListEvent& event);

        void OnMouseRightDown(wxMouseEvent& event);

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORLISTCTRL_H
