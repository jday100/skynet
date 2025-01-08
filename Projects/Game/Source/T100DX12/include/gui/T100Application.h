#ifndef T100APPLICATION_H
#define T100APPLICATION_H

#include <windows.h>

class T100DX12;

class T100Application
{
    public:
        T100Application();
        virtual ~T100Application();

        static int                  Run(T100DX12* pDX12, HINSTANCE hInstance, int nCmdShow);
        static HWND                 GetHwnd();

    protected:
        static LRESULT CALLBACK     WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        static HWND                 m_hwnd;

};

#endif // T100APPLICATION_H
