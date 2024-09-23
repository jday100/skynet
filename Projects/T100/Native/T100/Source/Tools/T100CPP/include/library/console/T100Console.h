#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100Common.h"
#include "T100WString.h"

class T100Console
{
    public:
        T100Console();
        virtual ~T100Console();

        virtual T100BOOL            out(T100WString);

    protected:

    private:
};

#endif // T100CONSOLE_H
