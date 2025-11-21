#ifndef T100CONSOLEWINDOWS_H
#define T100CONSOLEWINDOWS_H

#include "T100ConsoleBase.h"

namespace T100NATIVE{

class T100ConsoleWindows : public T100ConsoleBase
{
    public:
        T100ConsoleWindows();
        virtual ~T100ConsoleWindows();

        T100VOID            Print(T100WSTRING&);

        T100VOID            Outline(T100WSTRING&);
        T100VOID            Getline(T100WSTRING&);

        T100VOID            SetForegroundColour(T100COLOUR_TYPE);

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

}

#endif // T100CONSOLEWINDOWS_H
