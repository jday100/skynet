#ifndef T100CONSOLELINUX_H
#define T100CONSOLELINUX_H

#include "T100ConsoleBase.h"

class T100ConsoleLinux : public T100ConsoleBase
{
    public:
        T100ConsoleLinux();
        virtual ~T100ConsoleLinux();

        T100VOID            Print(T100WSTRING&);

        T100VOID            OutLine(T100WSTRING&);
        T100VOID            GetLine(T100WSTRING&);

    protected:

    private:
};

#endif // T100CONSOLELINUX_H
