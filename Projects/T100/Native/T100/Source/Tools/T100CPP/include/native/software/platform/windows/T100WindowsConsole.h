#ifndef T100WINDOWSCONSOLE_H
#define T100WINDOWSCONSOLE_H

#include "T100ConsoleBase.h"

class T100WindowsConsole : public T100ConsoleBase
{
    public:
        T100WindowsConsole();
        virtual ~T100WindowsConsole();

        virtual T100BOOL            out(T100WString);
        virtual T100BOOL            in(T100WString&);

    protected:

    private:
};

#endif // T100WINDOWSCONSOLE_H
