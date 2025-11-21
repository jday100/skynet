#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "common/T100ConsoleCommon.h"

namespace T100NATIVE{

class T100ConsoleBase
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID                        Print(T100WSTRING&) = 0;

        virtual T100VOID                        Outline(T100WSTRING&) = 0;
        virtual T100VOID                        Getline(T100WSTRING&) = 0;

        virtual T100VOID                        SetForegroundColour(T100COLOUR_TYPE);
        virtual T100COLOUR_TYPE                 GetForegroundColour();

        virtual T100VOID                        SetBackgroundColour(T100COLOUR_TYPE);
        virtual T100COLOUR_TYPE                 GetBackgroundColour();

    protected:
        T100COLOUR_TYPE                         m_foregroundColour          = T100COLOUR_TYPE_WHITE;
        T100COLOUR_TYPE                         m_backgroundColour          = T100COLOUR_TYPE_BLACK;

    private:
};

}

#endif // T100CONSOLEBASE_H
