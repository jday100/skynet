#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100ConsoleBase.h"

class T100Console
{
    public:
        T100Console(T100CONSOLE_TYPE = T100CONSOLE_TYPE_WINDOWS);
        virtual ~T100Console();

        T100VOID                    OutLine(T100WSTRING&);
        T100VOID                    GetLine(T100WSTRING&);

    protected:

    private:
        T100CONSOLE_TYPE            m_type;
        T100ConsoleBase*            m_consolePtr        = T100NULL;

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100CONSOLE_H
