#ifndef T100MENUITEM_H
#define T100MENUITEM_H

#include "gui/menu/T100MenuBase.h"

namespace T100WINDOWS{

class T100Menu;

class T100MenuItem : public T100MenuBase
{
    public:
        T100MenuItem(T100UINT, const T100WSTRING&);
        T100MenuItem(T100Menu*, T100UINT, const T100WSTRING&);
        virtual ~T100MenuItem();

    protected:

    private:
};

}

#endif // T100MENUITEM_H
