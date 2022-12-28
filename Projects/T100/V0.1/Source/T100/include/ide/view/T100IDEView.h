#ifndef T100IDEVIEW_H
#define T100IDEVIEW_H

#include <wx/frame.h>
#include "T100Common.h"

namespace T100IDE{
class T100IDEPlatenManager;
class T100IDEViewManager;
class T100IDEServe;
class T100IDEMainFrame;


class T100IDEView
{
    public:
        T100IDEView();
        virtual ~T100IDEView();

        T100VOID                    show();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        wxFrame*                    m_parent            = T100NULL;
        T100IDEMainFrame*           m_frame             = T100NULL;

        T100IDEPlatenManager*       m_platen            = T100NULL;
        T100IDEViewManager*         m_manager           = T100NULL;

};

}

#endif // T100IDEVIEW_H
