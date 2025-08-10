#ifndef T100MAINPANEL_H
#define T100MAINPANEL_H

#include <wx/aui/auibook.h>
#include "T100Common.h"
#include "T100FileInfo.h"
#include "T100Editor.h"

class T100MainPanel : public wxAuiNotebook
{
    public:
        T100MainPanel(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxAUI_NB_DEFAULT_STYLE);
        virtual ~T100MainPanel();

        virtual T100VOID            Create(T100FileInfo*);
        virtual T100VOID            Clear();

        T100VOID                    Save();

    protected:
        T100Editor*                 m_current       = T100NULL;

    private:
        T100VOID                    OnPageChanged(wxAuiNotebookEvent&);

        DECLARE_EVENT_TABLE()
};

#endif // T100MAINPANEL_H
