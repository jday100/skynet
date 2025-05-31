#include "gui/font/T100FontTools.h"

T100FontTools::T100FontTools()
{
    //ctor
}

T100FontTools::~T100FontTools()
{
    //dtor
}

T100VOID T100FontTools::Get(HWND hwnd, T100WSTRING_VECTOR& fonts)
{
    HDC     hdc;

    hdc     = GetDC(hwnd);

    EnumFontFamilies(hdc, 0, (FONTENUMPROC)EnumFontsProc, (LPARAM)&fonts);

}

int CALLBACK EnumFontsProc(ENUMLOGFONTEX* logical, NEWTEXTMETRICEX* physical, DWORD type, LPARAM param)
{
    T100WSTRING_VECTOR*         fonts       = (T100WSTRING_VECTOR*)param;

    //fonts->push_back(logical->elfFullName);

    fonts->push_back(logical->elfLogFont.lfFaceName);
}

HFONT T100FontTools::GetDefaultFont()
{
    HFONT       font;

    font    = (HFONT)GetStockObject(SYSTEM_FONT);

    return font;
}
