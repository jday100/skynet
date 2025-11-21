#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100Common.h"

class T100Console
{
    public:
        T100Console();
        virtual ~T100Console();

        static T100VOID             Out(T100STRING);

    protected:

    private:
};

#endif // T100CONSOLE_H
