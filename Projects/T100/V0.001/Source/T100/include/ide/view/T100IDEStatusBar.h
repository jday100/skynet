#ifndef T100IDESTATUSBAR_H
#define T100IDESTATUSBAR_H

#include <wx/statusbr.h>
#include "T100Common.h"


class T100IDEStatusBar
{
    public:
        T100IDEStatusBar(wxFrame*);
        virtual ~T100IDEStatusBar();

        T100BOOL                create();

    protected:
        T100VOID                destroy();

    private:
        wxFrame*                m_frame                 = T100NULL;
        wxStatusBar*            m_status_bar            = T100NULL;
};

#endif // T100IDESTATUSBAR_H
