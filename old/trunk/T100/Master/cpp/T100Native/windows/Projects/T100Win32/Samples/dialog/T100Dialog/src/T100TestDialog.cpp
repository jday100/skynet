#include "T100TestDialog.h"

#include "gui/T100Win32Application.h"

LPWORD lpwAlign(LPWORD lpIn)
{
    ULONG   ul;
    ul = (ULONG)lpIn;
    ul++;
    ul >>=1;
    ul <<=1;
    return (LPWORD)ul;
}

T100TestDialog::T100TestDialog() :
    T100Dialog()
{
    //ctor
}

T100TestDialog::~T100TestDialog()
{
    //dtor
}

T100VOID T100TestDialog::Create(T100Window* parent)
{
    HGLOBAL             hgbl;
    LPDLGTEMPLATE       lpdt;
    LPDLGITEMTEMPLATE   lpdit;
    LPWORD              lpw;
    LPWSTR              lpwsz;
    LRESULT             result;
    int                 nchar;

    hgbl = GlobalAlloc(GMEM_ZEROINIT, 1024);
    if(!hgbl) return;

    lpdt = (LPDLGTEMPLATE)GlobalLock(hgbl);

    lpdt->cdit = 1;
    lpdt->x = 10;
    lpdt->y = 10;
    lpdt->cx = 200;
    lpdt->cy = 170;

    lpw = (LPWORD)(lpdt + 1);
    *lpw++ = 0;
    *lpw++ = 0;

    lpwsz = (LPWSTR)lpw;
    nchar = 1 + MultiByteToWideChar(CP_ACP, 0, "a", -1, lpwsz,  50);
    lpw += nchar;


    lpw = lpwAlign(lpw);

    lpdit = (LPDLGITEMTEMPLATE)lpw;
    lpdit->x = 10;
    lpdit->y = 50;
    lpdit->cx = 80;
    lpdit->cy = 15;
    lpdit->id = IDOK;
    //lpdit->style = WS_CHILD | WS_VISIBLE | WS_SYSMENU | BS_DEFPUSHBUTTON;
    lpdit->style = WS_CHILD | WS_VISIBLE | WS_SYSMENU | BS_GROUPBOX;

    lpw = (LPWORD)(lpdit + 1);
    *lpw++ = 0xffff;
    *lpw++ = 0x0080;


    lpwsz = (LPWSTR)lpw;
    nchar = 1 + MultiByteToWideChar(CP_ACP, 0, "a", -1, lpwsz, 50);
    lpw += nchar;
    *lpw++ = 0;



    GlobalUnlock(hgbl);




    T100Tree::Create(parent);
    HINSTANCE       instance;
    HWND            hwnd;

    instance    = GetApplication()->GetInstance();

    if(!parent){
        return;
    }

    hwnd = parent->GetHWND();

    result  = DialogBoxIndirect(instance, lpdt, hwnd, (DLGPROC)DefaultDialogProcedure);


}
