#ifndef T100CONTROL_H
#define T100CONTROL_H

#include "gui/window/T100Window.h"

class T100Control : public T100Window
{
    public:
        T100Control();
        T100Control(T100Window*, T100WindowStyle* = T100NULL);
        virtual ~T100Control();

        T100VOID            Create(T100Window*, T100WindowStyle* = T100NULL);

    protected:

    private:
};

#endif // T100CONTROL_H
