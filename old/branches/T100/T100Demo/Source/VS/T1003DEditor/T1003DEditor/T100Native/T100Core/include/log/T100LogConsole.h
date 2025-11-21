#ifndef T100LOGCONSOLE_H
#define T100LOGCONSOLE_H

#include "common/T100LogCommon.h"
#include "log/T100LogBase.h"
#include "console/T100Console.h"

namespace T100NATIVE{

class T100LogConsole : public T100LogBase
{
    public:
        T100LogConsole();
        virtual ~T100LogConsole();

        virtual T100VOID            Outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE);

    protected:
        T100Console                 m_console;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100LOGCONSOLE_H
