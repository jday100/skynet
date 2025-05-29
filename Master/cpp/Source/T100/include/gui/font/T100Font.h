#ifndef T100FONT_H
#define T100FONT_H

#include <windows.h>
#include "base/T100Class.h"

class T100Font : public T100Class
{
    public:
        T100Font();
        T100Font(T100WSTRING);
        virtual ~T100Font();

        HFONT                   GetHFONT();

        T100VOID                SetFaceName(T100WSTRING);
        T100WSTRING             GetFaceName();

    protected:
        T100WSTRING             m_faceName;
        HFONT                   m_font;

    private:
        T100VOID                Init(T100WSTRING);
};

#endif // T100FONT_H
