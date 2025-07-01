#include "gui/T100Dialog.h"

#include "resource.h"
#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100Dialog::T100Dialog() :
    T100SelfLoopWindow()
{
    //ctor
}

T100Dialog::T100Dialog(T100Window* parent) :
    T100SelfLoopWindow()
{
    //ctor
    T100Tree::Create(parent);
    init(parent);
}

T100Dialog::~T100Dialog()
{
    //dtor
}

T100VOID T100Dialog::init(T100Window* parent)
{
    HINSTANCE       instance;
    HWND            hwnd;
    T100INT         result;

    instance    = GetApplication()->GetInstance();
    //parent      = ConvertToWindow(GetParent());

    if(parent){
        hwnd    = parent->GetHWND();

        //result  = DialogBox(instance, MAKEINTRESOURCE(DLG_MAIN), hwnd, (DLGPROC)DefaultDialogProcedure);

        //m_hwnd  = CreateDialog(instance, m_style.WindowLabel.c_str(), hwnd, (DLGPROC)DefaultDialogProcedure);

        CreateDialog(instance, hwnd);
    }

}

T100VOID T100Dialog::uninit()
{

}

T100VOID T100Dialog::Create(T100Window* parent)
{
    T100Tree::Create(parent);
    init(parent);
}

T100VOID T100Dialog::Destroy()
{

}

T100VOID T100Dialog::CreateDialog(HINSTANCE instance, HWND hwnd)
{
    T100INT             result;
    DLGTEMPLATE         dt;
    LPDLGTEMPLATE       lpdt;
    LPDLGITEMTEMPLATE   lpdit;

    dt.dwExtendedStyle  = 0;
    dt.cx       = 100;
    dt.cy       = 70;
    dt.x        = 10;
    dt.y        = 10;
    dt.cdit     = 0;
    dt.style    = WS_POPUP | WS_BORDER | WS_SYSMENU | DS_MODALFRAME | WS_CAPTION;

    DLGITEMTEMPLATE     dit1;

    result  = DialogBoxIndirect(instance, &dt, hwnd, (DLGPROC)DefaultDialogProcedure);
}

BOOL CALLBACK DefaultDialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message){
    case WM_INITDIALOG:
        {

        }
        break;
    case WM_CLOSE:
        {
            EndDialog(hwnd, 0);
        }
        break;
    case WM_COMMAND:
        {

        }
        break;
    }
    return 0;
}

}
