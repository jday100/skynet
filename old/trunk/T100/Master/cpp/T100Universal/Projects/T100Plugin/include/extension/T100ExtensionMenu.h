#ifndef T100EXTENSIONMENU_H
#define T100EXTENSIONMENU_H

#include "gui/T100Menu.h"
#include "plugin/T100Extension.h"

using namespace T100WINDOWS;

namespace T100UNIVERSAL{

class T100ExtensionMenu : public T100Extension
{
    public:
        T100ExtensionMenu();
        virtual ~T100ExtensionMenu();

        T100Menu*               GetMenu();

        virtual T100VOID        Bind(T100Menu*, T100EVENT_FUNCTION, T100EventHandler*);

        virtual T100VOID        SignIn(T100INT, T100EVENT_FUNCTION, T100EventHandler*);

        virtual T100VOID        Send(T100MenuEvent&);


    protected:
        T100EVENT_FUNCTION_DATA         m_event;
        T100Menu*                       m_menu      = T100NULL;

        T100EVENT_FUNCTION_DATA_HASH    m_children;

    private:
};

}

#endif // T100EXTENSIONMENU_H
