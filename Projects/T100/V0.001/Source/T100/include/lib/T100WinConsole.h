#ifndef T100WINCONSOLE_H
#define T100WINCONSOLE_H

#include "T100Common.h"


enum T100COLOUR_TYPE{
    T100COLOUR_NONE          = 0,
    T100COLOUR_BLACK,
    T100COLOUR_WHITE,
    T100COLOUR_RED,
    T100COLOUR_BLUE,
    T100COLOUR_YELLOW,
    T100COLOUR_GREEN,
    T100COLOUR_ORANGE,
    T100COLOUR_PURPLE,
    T100COLOUR_MAX
};


class T100WinConsole
{
    public:
        T100WinConsole();
        virtual ~T100WinConsole();

        static T100VOID             setColour(T100COLOUR_TYPE);

        static T100VOID             out(T100STDSTRING&);

    protected:

    private:
};

#endif // T100WINCONSOLE_H
