#ifndef T100CONSOLETERMINALTHREAD_H
#define T100CONSOLETERMINALTHREAD_H

#include "T100Thread.h"
#include "T100ConsoleTerminal.h"

namespace T100Library{

class T100ConsoleTerminalThread : public T100Thread
{
    public:
        T100ConsoleTerminalThread(T100ConsoleTerminal*);
        virtual ~T100ConsoleTerminalThread();

    protected:
        T100VOID                run();

    private:
        T100ConsoleTerminal*    m_console           = T100NULL;

};

}

#endif // T100CONSOLETERMINALTHREAD_H
