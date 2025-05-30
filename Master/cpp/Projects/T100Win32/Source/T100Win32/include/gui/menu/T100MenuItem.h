#ifndef T100MENUITEM_H
#define T100MENUITEM_H

#include <windows.h>
#include <commctrl.h>
#include "T100Common.h"
#include "T100MenuItemBase.h"

class T100Menu;

class T100MenuItem : public T100MenuItemBase
{
    public:
        T100MenuItem(T100Menu*, T100WORD, T100WSTRING);
        virtual ~T100MenuItem();

    protected:

    private:
};

#endif // T100MENUITEM_H
