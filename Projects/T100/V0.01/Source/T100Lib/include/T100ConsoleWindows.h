#ifndef T100CONSOLEWINDOWS_H
#define T100CONSOLEWINDOWS_H

#include "T100ConsoleBase.h"


class T100ConsoleWindows : public T100ConsoleBase
{
    public:
        T100ConsoleWindows();
        virtual ~T100ConsoleWindows();

        T100VOID            outline(T100WSTRING&);

        T100VOID            getline(T100WSTRING&);

        T100VOID            setForegroundColour(T100COLOUR_PRIMITIVE_TYPE);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100CONSOLEWINDOWS_H
