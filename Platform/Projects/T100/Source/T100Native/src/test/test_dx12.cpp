#include "T100ApplicationWindow.h"
#include "T100D3DX12.h"

LRESULT CALLBACK DX12WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
                   HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nCmdShow
                   )
{
    T100ApplicationWindow       app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);
    T100D3DX12*                 dx12 = new T100D3DX12();

    app.Create(_T("CodeBlocksWindowsApp"), _T("Code::Blocks Template Windows App"), DX12WindowProcedure, dx12);
    app.Show();
    return app.Run();
}

LRESULT CALLBACK DX12WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //T100D3DX12* pDX12 = reinterpret_cast<T100D3DX12*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    static T100D3DX12*      pDX12;

    switch (message)
    {
    case WM_CREATE:
        {
            LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
            SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));

            pDX12 = (T100D3DX12*)reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams);

            pDX12->Create(hWnd);
        }
        break;
    case WM_PAINT:
        if (pDX12)
        {
            //pDX12->Render();
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
