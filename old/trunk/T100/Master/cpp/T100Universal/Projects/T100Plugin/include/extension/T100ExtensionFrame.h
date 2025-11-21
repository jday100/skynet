#ifndef T100EXTENSIONFRAME_H
#define T100EXTENSIONFRAME_H

#include "gui/T100Frame.h"
#include "plugin/T100Extension.h"

using namespace T100WINDOWS;

namespace T100UNIVERSAL{

class T100ExtensionFrame : public T100Extension
{
    public:
        T100ExtensionFrame();
        virtual ~T100ExtensionFrame();

        T100Frame*              GetFrame();

        virtual T100VOID        Bind(T100Frame*);

        virtual T100VOID        SignIn(T100INT, T100EVENT_FUNCTION, T100EventHandler*);

    protected:
        T100Frame*              m_frame     = T100NULL;

        T100EVENT_FUNCTION_DATA_HASH        m_events;

    private:
};

}

#endif // T100EXTENSIONFRAME_H
