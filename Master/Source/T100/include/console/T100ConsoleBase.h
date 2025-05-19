#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "T100Common.h"
#include "common/T100ConsoleCommon.h"
#include "common/T100GraphicCommon.h"

class T100ConsoleBase
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID                        Print(T100WSTRING&) = 0;

        virtual T100VOID                        OutLine(T100WSTRING) = 0;
        virtual T100VOID                        GetLine(T100WSTRING&) = 0;

        virtual T100VOID                        SetForegroundColour(T100COLOUR_TYPE);
        virtual T100COLOUR_TYPE                 GetForegroundColour();

        virtual T100VOID                        SetBackgroundColour(T100COLOUR_TYPE);
        virtual T100COLOUR_TYPE                 GetBackgroundColour();

    protected:
        T100COLOUR_TYPE                         m_foreground            = T100COLOUR_TYPE_WHITE;
        T100COLOUR_TYPE                         m_background            = T100COLOUR_TYPE_BLACK;

    private:
};

#endif // T100CONSOLEBASE_H
