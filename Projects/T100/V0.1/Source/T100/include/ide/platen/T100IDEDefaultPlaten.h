#ifndef T100IDEDEFAULTPLATEN_H
#define T100IDEDEFAULTPLATEN_H

#include <wx/menu.h>
#include "T100IDEPlatenBase.h"

namespace T100IDE{

class T100IDEDefaultPlaten : public T100IDEPlatenBase
{
    public:
        T100IDEDefaultPlaten(T100IDEView*);
        virtual ~T100IDEDefaultPlaten();

        T100BOOL            create();

        T100BOOL            show();
        T100BOOL            hide();

        T100VOID            show_project(T100BOOL = T100TRUE);

        wxMenuBar*          CreateMainMenuBar();

    protected:
        T100VOID            destroy();

        T100BOOL            create_menu();

        T100BOOL            create_project();

    private:
        wxMenu*             m_menu_view             = T100NULL;

};

}

#endif // T100IDEDEFAULTPLATEN_H
