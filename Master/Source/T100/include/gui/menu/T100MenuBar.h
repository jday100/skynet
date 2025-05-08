#ifndef T100MENUBAR_H
#define T100MENUBAR_H

#include "T100Menu.h"

class T100MenuBar
{
    friend class T100Menu;
    friend class T100Frame;
    public:
        T100MenuBar();
        virtual ~T100MenuBar();

        T100VOID            Create(T100WSTRING&);
        T100VOID            Destroy();

    protected:
        HMENU               m_menuBar;

    private:
};

#endif // T100MENUBAR_H
