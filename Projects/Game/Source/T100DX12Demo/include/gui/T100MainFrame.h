#ifndef T100MAINFRAME_H
#define T100MAINFRAME_H

#include <tchar.h>
#include <windows.h>

class T100MainFrame
{
    public:
        T100MainFrame();
        virtual ~T100MainFrame();

        void        create();
        void        destroy();

        void        show();
        void        run(HINSTANCE, TCHAR[], int);

    protected:

    private:
        HWND        m_hwnd;
};

#endif // T100MAINFRAME_H
