#include "T100FontTools.h"

namespace T100WINDOWS{

T100FontTools::T100FontTools() :
    T100Class()
{
    //ctor
}

T100FontTools::~T100FontTools()
{
    //dtor
}

HFONT T100FontTools::GetDefaultFont()
{
    HFONT       font;

    font    = (HFONT)GetStockObject(SYSTEM_FONT);

    return font;
}

T100VOID T100FontTools::GetFontNames(HWND hwnd, T100WSTRING_VECTOR& fonts)
{
    HDC         hdc;

    hdc     = GetDC(hwnd);

    EnumFontFamilies(hdc, 0, (FONTENUMPROC)EnumFontsProcedure, (LPARAM)&fonts);
}

int CALLBACK EnumFontsProcedure(ENUMLOGFONTEX* logical, NEWTEXTMETRICEX* physical, DWORD type, LPARAM param)
{
    T100WSTRING_VECTOR*     fonts       = (T100WSTRING_VECTOR*)param;

    fonts->push_back(logical->elfLogFont.lfFaceName);
}

}
