#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include <wx/wx.h>
#include "T100Common.h"

class T100ProjectMDIMainFrame;
class T100ProjectViewManager;
class T100ProjectPlatenManager;

class T100ProjectView
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        T100BOOL                        show();
        T100BOOL                        hide();

        T100BOOL                        close();

        wxFrame*                        getFrame();

        T100ProjectViewManager*         getViewManager();
        T100ProjectPlatenManager*       getPlatenManager();

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

    private:
        T100ProjectMDIMainFrame*        m_frame             = T100NULL;
        T100ProjectViewManager*         m_manager           = T100NULL;
        T100ProjectPlatenManager*       m_platen            = T100NULL;
};

#endif // T100PROJECTVIEW_H
