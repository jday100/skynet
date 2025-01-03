#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "T100Common.h"

class T100ConsoleBase
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID            outline(T100WString) = 0;
        virtual T100VOID            getline(T100WString&) = 0;

    protected:

    private:
};

#endif // T100CONSOLEBASE_H
