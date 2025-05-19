#ifndef T100LOGGERCONSOLE_H
#define T100LOGGERCONSOLE_H

#include "common/T100LogCommon.h"
#include "log/T100LogBase.h"
#include "console/T100Console.h"

class T100LoggerConsole : public T100LogBase
{
    public:
        T100LoggerConsole();
        virtual ~T100LoggerConsole();

        virtual T100VOID        OutLine(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE = T100SOURCE_NONE);

    protected:

    private:
        T100Console             m_console;
};

#endif // T100LOGGERCONSOLE_H
