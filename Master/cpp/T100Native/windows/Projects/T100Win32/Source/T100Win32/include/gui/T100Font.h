#ifndef T100FONT_H
#define T100FONT_H

#include <atomic>
#include <windows.h>
#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Font : public T100Class
{
    public:
        T100Font();
        T100Font(const T100WSTRING&);
        virtual ~T100Font();

        HFONT                       GetHFONT();

        virtual T100VOID            Create(const T100WSTRING&);
        virtual T100VOID            Destroy();

        T100VOID                    SetFaceName(const T100WSTRING&);
        const T100WSTRING&          GetFaceName();

        const T100Font& operator=(const T100Font&);

    protected:
        HFONT                       m_hfont;
        T100WSTRING                 m_faceName;
        std::atomic_bool            m_created;

        T100INT                     m_height;
        T100INT                     m_width;
        T100INT                     m_escapement;
        T100INT                     m_orientation;
        T100INT                     m_weight;

        T100BYTE                    m_italic;
        T100BYTE                    m_underline;
        T100BYTE                    m_strikeOut;
        T100BYTE                    m_charSet;
        T100BYTE                    m_outPrecision;
        T100BYTE                    m_clipPrecision;
        T100BYTE                    m_quality;
        T100BYTE                    m_pitchAndFamily;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100FONT_H
