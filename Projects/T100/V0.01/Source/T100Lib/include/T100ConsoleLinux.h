#ifndef T100CONSOLELINUX_H
#define T100CONSOLELINUX_H

#include "T100ConsoleBase.h"


class T100ConsoleLinux : public T100ConsoleBase
{
    public:
        T100ConsoleLinux();
        virtual ~T100ConsoleLinux();

        T100VOID            outline(T100WSTRING&);

        T100VOID            getline(T100WSTRING&);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100CONSOLELINUX_H
