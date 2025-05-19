#ifndef T100CONTROL_H
#define T100CONTROL_H

#include "gui/T100Window.h"

class T100Control : public T100Window
{
    public:
        T100Control();
        T100Control(T100Win32Application*, T100Window*);
        virtual ~T100Control();

    protected:

    private:
};

#endif // T100CONTROL_H
