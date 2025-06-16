#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "console/T100ConsoleBase.h"

namespace T100LIBRARY{

class T100Console : public T100Class
{
    public:
        T100Console();
        virtual ~T100Console();

        virtual T100VOID            OutLine(const T100WSTRING&);
        virtual T100VOID            GetLine(const T100WSTRING&);

    protected:
        T100ConsoleBase*            m_console       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100CONSOLE_H
