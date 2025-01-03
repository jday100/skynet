#ifndef T100LOGCONSOLE_H
#define T100LOGCONSOLE_H

#include "develop/log/T100LogBase.h"
#include "console/T100Console.h"

class T100LogConsole : public T100LogBase
{
    public:
        T100LogConsole();
        virtual ~T100LogConsole();

        T100VOID            outline(T100WString);
        T100VOID            getline(T100WString&);

    protected:

    private:
        T100Console         m_console;
};

#endif // T100LOGCONSOLE_H
