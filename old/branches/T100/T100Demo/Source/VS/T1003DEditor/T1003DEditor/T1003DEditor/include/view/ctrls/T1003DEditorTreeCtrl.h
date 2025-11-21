#ifndef T1003DEDITORTREECTRL_H
#define T1003DEDITORTREECTRL_H

#include <wx/treectrl.h>
#include "T100Common.h"

class T1003DEditorTreeCtrl : public wxTreeCtrl
{
    public:
        T1003DEditorTreeCtrl(wxWindow *parent,
               wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTreeCtrlNameStr);
        virtual ~T1003DEditorTreeCtrl();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORTREECTRL_H
