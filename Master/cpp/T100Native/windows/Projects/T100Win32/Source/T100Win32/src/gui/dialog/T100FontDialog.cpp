#include "T100FontDialog.h"

namespace T100WINDOWS{

T100FontDialog::T100FontDialog() :
    T100Dialog()
{
    //ctor
}

T100FontDialog::T100FontDialog(T100Window* parent) :
    T100Dialog()
{
    //ctor
    init(parent);
}

T100FontDialog::~T100FontDialog()
{
    //dtor
}

T100VOID T100FontDialog::init(T100Window* parent)
{
    T100EventHandler::Create(parent);
}

T100VOID T100FontDialog::uninit()
{

}

T100VOID T100FontDialog::Create(T100Window* parent)
{
    //T100Dialog::Create(parent);
    T100EventHandler::Create(parent);
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

T100BOOL T100FontDialog::Show()
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
        m_font.SetWidth(lf.lfWidth);
        m_font.SetHeight(lf.lfHeight);
        m_font.SetEscapement(lf.lfEscapement);
        m_font.SetOrientation(lf.lfOrientation);
        m_font.SetWeight(lf.lfWeight);

        m_font.SetItalic(lf.lfItalic);
        m_font.SetUnderline(lf.lfUnderline);
        m_font.SetStrikeOut(lf.lfStrikeOut);
        m_font.SetCharSet(lf.lfCharSet);
        m_font.SetOutPrecision(lf.lfOutPrecision);
        m_font.SetClipPrecision(lf.lfClipPrecision);
        m_font.SetQuality(lf.lfQuality);
        m_font.SetPitchAndFamily(lf.lfPitchAndFamily);

        return T100TRUE;
    }

    return T100FALSE;
}

}
