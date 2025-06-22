#ifndef T100MENU_H
#define T100MENU_H

#include "gui/menu/T100MenuItem.h"

namespace T100WINDOWS{

class T100MenuBar;

class T100Menu : public T100MenuBase
{
    public:
        T100Menu(const T100WSTRING&);
        T100Menu(T100MenuBar*, const T100WSTRING&);
        virtual ~T100Menu();

        T100VOID            Append(T100UINT, const T100WSTRING&);

        T100VOID            Append(T100MenuItem*);
        T100VOID            Remove(T100MenuItem*);

        T100VOID            AppendSeparator();

    protected:

    private:
};

}

#endif // T100MENU_H
