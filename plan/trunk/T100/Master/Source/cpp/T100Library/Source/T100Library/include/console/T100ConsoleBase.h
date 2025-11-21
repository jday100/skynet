#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100ConsoleBase : public T100Class
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID            OutLine(const T100WSTRING&) = 0;
        virtual T100VOID            GetLine(const T100WSTRING&) = 0;

    protected:

    private:
};

}

#endif // T100CONSOLEBASE_H
