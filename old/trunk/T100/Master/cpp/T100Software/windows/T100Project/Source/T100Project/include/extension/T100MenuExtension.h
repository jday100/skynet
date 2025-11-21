#ifndef T100MENUEXTENSION_H
#define T100MENUEXTENSION_H

#include "T100Extension.h"
#include "gui/handler/T100EventHandler.h"

using namespace T100WINDOWS;

#define     T100MENU_EXTENSION_HASH                 std::unordered_map<T100UINT, T100WSTRING>

class T100MenuExtension : public T100Extension
{
    public:
        T100MenuExtension();
        virtual ~T100MenuExtension();

        virtual T100VOID            SendEvent(...);

        virtual T100VOID            ConnectMenu(T100UINT, T100EventHandler*, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);

        T100VOID                    Append(T100UINT, const T100WSTRING&);
        T100VOID                    FindEvent(T100MenuEvent&);

    protected:
        T100EVENT_FUNCTION_DATA_HASH            m_events;
        T100MENU_EXTENSION_HASH                 m_menus;

    private:
};

#endif // T100MENUEXTENSION_H
