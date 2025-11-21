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

        T100VOID            SetID(T100UINT);
        T100UINT            GetID();

    protected:
        T100UINT            m_id            = 0;

    private:
};

}

#endif // T100MENUITEM_H
