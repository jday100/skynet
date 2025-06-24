#ifndef T100FONTTOOLS_H
#define T100FONTTOOLS_H

#include <windows.h>
#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

int CALLBACK EnumFontsProcedure(ENUMLOGFONTEX*, NEWTEXTMETRICEX*, DWORD, LPARAM);

class T100FontTools : public T100Class
{
    public:
        T100FontTools();
        virtual ~T100FontTools();

        static HFONT                GetDefaultFont();

        static T100VOID             GetFontNames(HWND, T100WSTRING_VECTOR&);

    protected:

    private:
};

}

#endif // T100FONTTOOLS_H
