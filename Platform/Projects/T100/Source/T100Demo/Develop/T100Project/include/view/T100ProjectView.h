#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include <wx/wx.h>
#include "T100Common.h"
#include "T100ProjectMDIMainFrame.h"

class T100ProjectView
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        T100BOOL                show();
        T100BOOL                hide();

        wxFrame*                getFrame();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100ProjectMDIMainFrame*        m_frame             = T100NULL;
};

#endif // T100PROJECTVIEW_H
