#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include <atomic>
#include "common/T100ConsoleCommon.h"
#include "console/T100ConsoleBase.h"

namespace T100NATIVE{

class T100Console
{
    public:
        T100Console(T100CONSOLE_TYPE = T100CONSOLE_TYPE_WINDOWS);
        virtual ~T100Console();

        T100VOID                            Outline(T100WSTRING&);
        T100VOID                            Getline(T100WSTRING&);

    protected:
        std::atomic<T100CONSOLE_TYPE>       m_type;
        T100ConsoleBase*                    m_consolePtr            = T100NULL;

    private:
        T100VOID                            init();
        T100VOID                            uninit();
};

}

#endif // T100CONSOLE_H
