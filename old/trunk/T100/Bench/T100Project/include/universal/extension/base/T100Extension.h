#ifndef T100EXTENSION_H
#define T100EXTENSION_H

#include <wx/event.h>
#include "T100Class.h"

class T100Plugin;

typedef     T100VOID*(T100Class::*T100CLASS_METHOD)(T100VOID*);
typedef     T100VOID(T100Plugin::*T100EXTENSION_EVENT_FUNCTION)(wxEvent&);

typedef struct {
    T100Class*              Handler;
    T100CLASS_METHOD        Method;
}T100CLASS_METHOD_DATA;

class T100Extension
{
    public:
        T100Extension();
        virtual ~T100Extension();

    protected:

    private:
};

#endif // T100EXTENSION_H
