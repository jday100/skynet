#ifndef T100MENU_H
#define T100MENU_H

#include "T100MenuItem.h"

class T100MenuBar;

class T100Menu : public T100Class
{
    friend class T100MenuItem;
    public:
        T100Menu(T100MenuBar*, T100WSTRING);
        virtual ~T100Menu();

        T100VOID            Create(T100UINT, T100WSTRING&);

    protected:
        HMENU               m_menuBar;
        HMENU               m_menu;

    private:
};

#endif // T100MENU_H
