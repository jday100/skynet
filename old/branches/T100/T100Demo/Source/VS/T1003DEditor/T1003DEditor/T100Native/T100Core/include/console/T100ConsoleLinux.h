#ifndef T100CONSOLELINUX_H
#define T100CONSOLELINUX_H

#include "T100ConsoleBase.h"

namespace T100NATIVE{

class T100ConsoleLinux : public T100ConsoleBase
{
    public:
        T100ConsoleLinux();
        virtual ~T100ConsoleLinux();

        T100VOID            Print(T100WSTRING&);

        T100VOID            Outline(T100WSTRING&);
        T100VOID            Getline(T100WSTRING&);

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

}

#endif // T100CONSOLELINUX_H
