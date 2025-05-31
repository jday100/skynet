#ifndef T100FONTTOOLS_H
#define T100FONTTOOLS_H

#include <windows.h>
#include "T100Common.h"

int CALLBACK EnumFontsProc(ENUMLOGFONTEX*, NEWTEXTMETRICEX*, DWORD, LPARAM);

class T100FontTools
{
    public:
        T100FontTools();
        virtual ~T100FontTools();

        static T100VOID             Get(HWND, T100WSTRING_VECTOR&);

        static HFONT                GetDefaultFont();

    protected:

    private:
};

#endif // T100FONTTOOLS_H
