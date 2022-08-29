#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "T100GraphicCommon.h"


class T100ConsoleBase
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID                        outline(T100WSTRING&) = 0;
        virtual T100VOID                        getline(T100WSTRING&) = 0;

        virtual T100VOID                        setForegroundColour(T100COLOUR_PRIMITIVE_TYPE);
        virtual T100COLOUR_PRIMITIVE_TYPE       getForegroundColour();

        virtual T100VOID                        setBackgroundColour(T100COLOUR_PRIMITIVE_TYPE);
        virtual T100COLOUR_PRIMITIVE_TYPE       getBackgroundColour();

    protected:
        T100COLOUR_PRIMITIVE_TYPE               m_foreground            = T100COLOUR_WHITE;
        T100COLOUR_PRIMITIVE_TYPE               m_background            = T100COLOUR_BLACK;

    private:
};

#endif // T100CONSOLEBASE_H
