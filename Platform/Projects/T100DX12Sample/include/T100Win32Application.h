#ifndef T100WIN32APPLICATION_H
#define T100WIN32APPLICATION_H

#include "T100DXSample.h"

class T100DXSample;

class T100Win32Application
{
    public:
        T100Win32Application();
        virtual ~T100Win32Application();

        static int Run(T100DXSample* pSample, HINSTANCE hInstance, int mCmdShow);
        static HWND GetHwnd() {return m_hwnd;}

    protected:
        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        static HWND     m_hwnd;

};

#endif // T100WIN32APPLICATION_H
;
