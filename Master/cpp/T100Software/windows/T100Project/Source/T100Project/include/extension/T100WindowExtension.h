#ifndef T100WINDOWEXTENSION_H
#define T100WINDOWEXTENSION_H

#include "T100Extension.h"
#include "gui/handler/T100EventHandler.h"

using namespace T100WINDOWS;

class T100WindowExtension : public T100Extension
{
    public:
        T100WindowExtension();
        virtual ~T100WindowExtension();

        virtual T100VOID            SendEvent(...);

        T100VOID                    Connect(T100VOID*);

    protected:
        T100EVENT_FUNCTION_DATA_HASH            m_events;

        T100VOID*                   m_data      = T100NULL;

    private:
};

#endif // T100WINDOWEXTENSION_H
