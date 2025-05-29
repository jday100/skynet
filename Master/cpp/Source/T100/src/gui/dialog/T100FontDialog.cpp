#include "T100FontDialog.h"

T100FontDialog::T100FontDialog() :
    T100Dialog()
{
    //ctor
}

T100FontDialog::~T100FontDialog()
{
    //dtor
}

T100VOID T100FontDialog::Create(T100Window* parent)
{
    CHOOSEFONT      cf;
    LOGFONT         lf;
    DWORD           colour;
    ZeroMemory(&cf, sizeof(cf));

    cf.lStructSize      = sizeof(cf);
    cf.hwndOwner        = parent->GetHWND();
    cf.lpLogFont        = &lf;
    cf.rgbColors        = colour;
    cf.Flags    = CF_SCREENFONTS | CF_EFFECTS;

    if(ChooseFont(&cf) == T100TRUE){

    }
}
