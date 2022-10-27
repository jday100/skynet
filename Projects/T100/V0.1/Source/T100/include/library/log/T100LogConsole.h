#ifndef T100LOGCONSOLE_H
#define T100LOGCONSOLE_H

#include "T100LogCommon.h"
#include "T100LogBase.h"

namespace T100Library{

class T100LogConsole : public T100LogBase
{
    public:
        T100LogConsole();
        virtual ~T100LogConsole();

        virtual T100VOID            outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE);

    protected:

    private:
};

}

#endif // T100LOGCONSOLE_H
