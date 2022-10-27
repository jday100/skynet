#ifndef T100CONSOLELINUX_H
#define T100CONSOLELINUX_H

#include "T100ConsoleBase.h"

namespace T100Library{

class T100ConsoleLinux : public T100ConsoleBase
{
    public:
        T100ConsoleLinux();
        virtual ~T100ConsoleLinux();

        T100VOID            outline(T100WSTRING&);
        T100VOID            getline(T100WSTRING&);

    protected:

    private:
};

}

#endif // T100CONSOLELINUX_H
