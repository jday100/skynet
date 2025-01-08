#ifndef T100WINDOW_H
#define T100WINDOW_H

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>



class T100Window
{
    public:
        T100Window();
        virtual ~T100Window();

    protected:

    private:
};

#endif // T100WINDOW_H
