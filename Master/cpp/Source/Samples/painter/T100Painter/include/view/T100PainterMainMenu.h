#ifndef T100PAINTERMAINMENU_H
#define T100PAINTERMAINMENU_H

#include "gui/T100Frame.h"
#include "gui/T100MenuBar.h"

class T100PainterMainMenu
{
    public:
        T100PainterMainMenu();
        virtual ~T100PainterMainMenu();

        T100VOID            Create(T100Frame*);
        T100VOID            Destroy();

    protected:
        T100Menu*           m_fileMenuPtr       = T100NULL;

        T100MenuItem*       m_newItemPtr        = T100NULL;
        T100MenuItem*       m_quitItemPtr       = T100NULL;

    private:
        T100Frame*          m_framePtr          = T100NULL;
        T100MenuBar*        m_menuBarPtr        = T100NULL;
};

#endif // T100PAINTERMAINMENU_H
