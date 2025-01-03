#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100Common.h"
#include "T100ConsoleBase.h"

class T100Console
{
    public:
        T100Console();
        virtual ~T100Console();

        T100VOID                outline(T100WString);
        T100VOID                getline(T100WString&);

    protected:

    private:
        T100VOID                create();
        T100VOID                destroy();

        T100ConsoleBase*        m_console           = T100NULL;
};

#endif // T100CONSOLE_H
