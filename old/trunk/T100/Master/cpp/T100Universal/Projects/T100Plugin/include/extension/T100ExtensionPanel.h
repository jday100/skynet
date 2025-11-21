#ifndef T100EXTENSIONPANEL_H
#define T100EXTENSIONPANEL_H

#include "gui/T100Panel.h"
#include "plugin/T100Extension.h"

using namespace T100WINDOWS;

namespace T100UNIVERSAL{

class T100ExtensionPanel : public T100Extension
{
    public:
        T100ExtensionPanel();
        virtual ~T100ExtensionPanel();

        T100Panel*              GetPanel();

        virtual T100VOID        Bind(T100Panel*);

        virtual T100VOID        SignIn(T100INT, T100EVENT_FUNCTION, T100EventHandler*);

    protected:
        T100Panel*              m_panel     = T100NULL;

        T100EVENT_FUNCTION_DATA_HASH        m_events;

    private:
};

}

#endif // T100EXTENSIONPANEL_H
