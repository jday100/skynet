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

        T100Editor*                 GetCurrentEditor();

        virtual T100BOOL            Open(T100FileInfo*);
        virtual T100BOOL            Close(T100FileInfo*);

        virtual T100BOOL            Save();
        virtual T100BOOL            SaveAll();
        virtual T100BOOL            Clear();

    protected:
        T100Pack*                   m_current       = T100NULL;

    private:
        T100VOID                    OnPageChanged(wxAuiNotebookEvent&);
        T100VOID                    OnPageClosing(wxAuiNotebookEvent&);
        T100VOID                    OnPageClosed(wxAuiNotebookEvent&);

        DECLARE_EVENT_TABLE()
};

#endif // T100MAINPANEL_H
