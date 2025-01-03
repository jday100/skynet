#ifndef T100CONSOLEWINDOWS_H
#define T100CONSOLEWINDOWS_H

#include "T100ConsoleBase.h"

class T100ConsoleWindows : public T100ConsoleBase
{
    public:
        T100ConsoleWindows();
        virtual ~T100ConsoleWindows();

        T100VOID            outline(T100WString);
        T100VOID            getline(T100WString&);

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

#endif // T100CONSOLEWINDOWS_H
