#ifndef T100LOGCONSOLE_H
#define T100LOGCONSOLE_H

#include "T100LogCommon.h"
#include "T100LogBase.h"
#include "T100Console.h"

namespace T100Library{

class T100LogConsole : public T100LogBase
{
    public:
        T100LogConsole();
        virtual ~T100LogConsole();

        virtual T100VOID            outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100Console                 m_console;

};

}

#endif // T100LOGCONSOLE_H
