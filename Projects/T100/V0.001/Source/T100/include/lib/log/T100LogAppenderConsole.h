#ifndef T100LOGAPPENDERCONSOLE_H
#define T100LOGAPPENDERCONSOLE_H

#include "T100LogAppender.h"


class T100LogAppenderConsole : public T100LogAppender
{
    public:
        T100LogAppenderConsole();
        virtual ~T100LogAppenderConsole();

        T100VOID            out(T100LOG_TYPE, T100STDSTRING);

    protected:

    private:
};

#endif // T100LOGAPPENDERCONSOLE_H
