#ifndef T100CVMVIEWMAINMENU_H
#define T100CVMVIEWMAINMENU_H

#include "gui/T100Frame.h"

using namespace T100WINDOWS;

class T100CVMViewMainMenu
{
    public:
        T100CVMViewMainMenu(T100Frame*);
        virtual ~T100CVMViewMainMenu();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:
        T100Frame*                  m_frame         = T100NULL;

        T100MenuBar*                m_menuBar       = T100NULL;

        T100Menu*                   m_vmMenu        = T100NULL;

        T100MenuItem*               m_newItem       = T100NULL;

        T100MenuItem*               m_startItem     = T100NULL;
        T100MenuItem*               m_stopItem      = T100NULL;

        T100Menu*                   m_helpMenu      = T100NULL;

        T100MenuItem*               m_aboutItem     = T100NULL;

    private:
};

#endif // T100CVMVIEWMAINMENU_H
