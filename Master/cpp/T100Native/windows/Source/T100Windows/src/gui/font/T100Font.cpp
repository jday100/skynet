#include "gui/T100Font.h"

namespace T100WINDOWS{

T100Font::T100Font() :
    T100FontBase()
{
    //ctor
}

T100Font::T100Font(const T100WSTRING& name) :
    T100FontBase()
{
    //ctor
    SetFaceName(name);
    init();
}

T100Font::~T100Font()
{
    //dtor
}

T100VOID T100Font::init()
{
    LOGFONT         lf;
    size_t          size;

    size    = m_faceName.size() > LF_FACESIZE ? LF_FACESIZE : m_faceName.size();

    wmemcpy(lf.lfFaceName, m_faceName.c_str(), size);

    lf.lfWidth          = m_width;
    lf.lfHeight         = m_height;
    lf.lfEscapement     = m_escapement;
    lf.lfOrientation    = m_orientation;
    lf.lfWeight         = m_weight;
    lf.lfItalic         = m_italic;
    lf.lfUnderline      = m_underline;
    lf.lfStrikeOut      = m_strikeOut;
    lf.lfCharSet        = m_charSet;
    lf.lfOutPrecision   = m_outPrecision;
    lf.lfClipPrecision  = m_clipPrecision;
    lf.lfQuality        = m_quality;
    lf.lfPitchAndFamily = m_pitchAndFamily;

    m_hfont = CreateFontIndirect(&lf);

    m_created   = T100TRUE;
}

T100VOID T100Font::uninit()
{
    DeleteObject(m_hfont);
    m_created   = T100FALSE;
}

T100VOID T100Font::Create(const T100WSTRING& name)
{
    m_faceName  = name;
    init();
}

T100VOID T100Font::Destroy()
{

}

const T100Font& T100Font::operator=(const T100Font& font)
{
    if(m_created){
        uninit();
    }

    m_faceName          = font.m_faceName;
    m_height            = font.m_height;
    m_width             = font.m_width;
    m_escapement        = font.m_escapement;
    m_orientation       = font.m_orientation;
    m_weight            = font.m_weight;

    m_italic            = font.m_italic;
    m_underline         = font.m_underline;
    m_strikeOut         = font.m_strikeOut;
    m_charSet           = font.m_charSet;
    m_outPrecision      = font.m_outPrecision;
    m_clipPrecision     = font.m_clipPrecision;
    m_quality           = font.m_quality;
    m_pitchAndFamily    = font.m_pitchAndFamily;

    init();

    return *this;
}

}
