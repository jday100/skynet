#ifndef T100MAINPANEL_H
#define T100MAINPANEL_H

#include <wx/aui/auibook.h>
#include "T100Common.h"
#include "T100FileInfo.h"
#include "T100Editor.h"
#include "T100Pack.h"

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

        T100Editor*                 GetCurrentEditor();

    protected:
        T100Pack*                   m_current       = T100NULL;

    private:
        T100VOID                    OnPageChanged(wxAuiNotebookEvent&);
        T100VOID                    OnPageClosed(wxAuiNotebookEvent&);

        DECLARE_EVENT_TABLE()
};

#endif // T100MAINPANEL_H
