#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100ConsoleCommon.h"
#include "T100ConsoleBase.h"


class T100Console
{
    public:
        T100Console(T100CONSOLE_TYPE type = T100CONSOLE_WINDOWS);
        virtual ~T100Console();

        T100VOID                outline(T100WSTRING&);
        T100VOID                getline(T100WSTRING&);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100CONSOLE_TYPE        m_type;
        T100ConsoleBase*        m_console           = T100NULL;

};

#endif // T100CONSOLE_H
