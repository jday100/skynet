#ifndef T100FONTBASE_H
#define T100FONTBASE_H

#include <atomic>
#include <windows.h>
#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100FontBase : public T100Class
{
    public:
        T100FontBase();
        virtual ~T100FontBase();

        HFONT                       GetHFONT();

        T100VOID                    SetFaceName(const T100WSTRING&);
        const T100WSTRING&          GetFaceName();

        T100VOID                    SetWidth(T100INT);
        T100INT                     GetWidth();

        T100VOID                    SetHeight(T100INT);
        T100INT                     GetHeight();

        T100VOID                    SetEscapement(T100INT);
        T100INT                     GetEscapement();

        T100VOID                    SetOrientation(T100INT);
        T100INT                     GetOrientation();

        T100VOID                    SetWeight(T100INT);
        T100INT                     GetWeight();

        T100VOID                    SetItalic(T100BYTE);
        T100BYTE                    GetItalic();

        T100VOID                    SetUnderline(T100BYTE);
        T100BYTE                    GetUnderline();

        T100VOID                    SetStrikeOut(T100BYTE);
        T100BYTE                    GetStrikeOut();

        T100VOID                    SetCharSet(T100BYTE);
        T100BYTE                    GetCharSet();

        T100VOID                    SetOutPrecision(T100BYTE);
        T100BYTE                    GetOutPrecision();

        T100VOID                    SetClipPrecision(T100BYTE);
        T100BYTE                    GetClipPrecision();

        T100VOID                    SetQuality(T100BYTE);
        T100BYTE                    GetQuality();

        T100VOID                    SetPitchAndFamily(T100BYTE);
        T100BYTE                    GetPitchAndFamily();

    protected:
        HFONT                       m_hfont;
        T100WSTRING                 m_faceName;
        std::atomic_bool            m_created;

        T100INT                     m_width             = 32;
        T100INT                     m_height            = 32;
        T100INT                     m_escapement        = 0;
        T100INT                     m_orientation       = 0;
        T100INT                     m_weight            = 1;

        T100BYTE                    m_italic            = 0;
        T100BYTE                    m_underline         = 0;
        T100BYTE                    m_strikeOut         = 0;
        T100BYTE                    m_charSet           = 0;
        T100BYTE                    m_outPrecision      = 0;
        T100BYTE                    m_clipPrecision     = 0;
        T100BYTE                    m_quality           = 0;
        T100BYTE                    m_pitchAndFamily    = 0;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100FONTBASE_H
