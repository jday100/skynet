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

        m_hwnd  = CreateDialog(instance, m_style.WindowLabel.c_str(), hwnd, (DLGPROC)DefaultDialogProcedure);

        //result  = DialogBox(instance, MAKEINTRESOURCE(DLG_MAIN), hwnd, (DLGPROC)DefaultDialogProcedure);
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
