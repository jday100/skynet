#include "T100FontDialog.h"

namespace T100WINDOWS{

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
    T100Dialog::Create(parent);
}

T100VOID T100FontDialog::Destroy()
{

}

T100VOID T100FontDialog::SetFont(const T100Font& font)
{
    m_font      = font;
}

const T100Font& T100FontDialog::GetFont()
{
    return m_font;
}

T100VOID T100FontDialog::Show()
{
    CHOOSEFONT      cf;
    LOGFONT         lf;
    HWND            hwnd;
    DWORD           colour;

    hwnd    = ConvertToWindow(m_parent)->GetHWND();

    ZeroMemory(&cf, sizeof(cf));

    cf.lStructSize      = sizeof(cf);
    cf.hwndOwner        = hwnd;
    cf.lpLogFont        = &lf;
    cf.rgbColors        = colour;
    cf.Flags    = CF_SCREENFONTS | CF_EFFECTS;

    if(ChooseFont(&cf) == T100TRUE){
        m_font.SetFaceName(lf.lfFaceName);
    }
}

}
