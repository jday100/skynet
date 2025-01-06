#ifndef T100APP_H
#define T100APP_H

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <windows.h>
#include "T100Common.h"
#include "T100Window.h"

class T100App
{
    public:
        T100App(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T100App();

        T100INT             Run();

    protected:
        HINSTANCE           m_this_instance;
        HINSTANCE           m_prev_instance;
        LPSTR               m_argument;
        int                 m_cmd_show;

        T100Window*         m_window            = T100NULL;

    private:
        T100VOID            create();
        T100VOID            destroy();

};

#endif // T100APP_H
