#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "T100ConsoleCommon.h"

namespace T100Library{

class T100ConsoleBase : public T100Class
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID                        outline(T100WSTRING&) = 0;
        virtual T100VOID                        getline(T100WSTRING&) = 0;

        virtual T100VOID                        setForegroundColour(T100COLOUR_TYPE);
        virtual T100COLOUR_TYPE                 getForegroundColour();

        virtual T100VOID                        setBackgroundColour(T100COLOUR_TYPE);
        virtual T100COLOUR_TYPE                 getBackgroundColour();

    protected:
        T100COLOUR_TYPE                         m_foreground            = T100COLOUR_TYPE_WHITE;
        T100COLOUR_TYPE                         m_background            = T100COLOUR_TYPE_BLACK;

    private:
};

}

#endif // T100CONSOLEBASE_H
