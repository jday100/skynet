#ifndef T100CONSOLEWINDOWS_H
#define T100CONSOLEWINDOWS_H

#include "T100ConsoleBase.h"

class T100ConsoleWindows : public T100ConsoleBase
{
    public:
        T100ConsoleWindows();
        virtual ~T100ConsoleWindows();

        T100VOID            Print(T100WSTRING&);

        T100VOID            OutLine(T100WSTRING);
        T100VOID            GetLine(T100WSTRING&);

        T100VOID            SetForegroundColour(T100COLOUR_TYPE);

    protected:

    private:
};

#endif // T100CONSOLEWINDOWS_H
