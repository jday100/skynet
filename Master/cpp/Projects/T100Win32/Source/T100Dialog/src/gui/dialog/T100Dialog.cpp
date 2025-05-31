#include "T100Dialog.h"

#include "resource.h"
#include "gui/common/T100WindowCommon.h"
#include "gui/event/T100ApplicationEventHandler.h"

T100Dialog::T100Dialog() :
    T100Window()
{
    //ctor
}

T100Dialog::~T100Dialog()
{
    //dtor
}

T100VOID T100Dialog::Create(T100Window* parent)
{
    T100ObjectTreeNode::Create(T100WINDOW_TYPE_T100DIALOG, parent);
}

T100VOID T100Dialog::Show()
{
    HINSTANCE       instance;
    HWND            hwnd;
    T100Window*     parent      = T100NULL;
    int             i;

    instance    = GetApplicationPtr()->GetThisInstance();
    parent      = ConvertToWindow(GetParentPtr());

    if(parent){
        hwnd    = parent->GetHWND();

        i       = DialogBox(instance, MAKEINTRESOURCE(DLG_MAIN), hwnd, (DLGPROC)DefaultDialogProcedure);
    }
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
