#ifndef T100DISKVIEWMAINMENU_H
#define T100DISKVIEWMAINMENU_H

#include "gui/T100Frame.h"

using namespace T100WINDOWS;

class T100DiskViewMainMenu
{
    public:
        T100DiskViewMainMenu();
        virtual ~T100DiskViewMainMenu();

        virtual T100VOID            Create(T100Frame*);
        virtual T100VOID            Destroy();

    protected:
        T100Frame*                  m_frame         = T100NULL;

        T100MenuBar*                m_menuBar       = T100NULL;

        T100Menu*                   m_fileMenu      = T100NULL;

        T100MenuItem*               m_openItem      = T100NULL;
        T100MenuItem*               m_closeItem     = T100NULL;
        T100MenuItem*               m_quitItem      = T100NULL;


        T100Menu*                   m_helpMenu      = T100NULL;

        T100MenuItem*               m_aboutItem     = T100NULL;


    private:
};

#endif // T100DISKVIEWMAINMENU_H
