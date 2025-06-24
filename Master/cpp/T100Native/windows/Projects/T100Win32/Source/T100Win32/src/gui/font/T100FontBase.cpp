#include "T100FontBase.h"

namespace T100WINDOWS{

T100FontBase::T100FontBase() :
    T100Class()
{
    //ctor
    init();
}

T100FontBase::~T100FontBase()
{
    //dtor
    uninit();
}

T100VOID T100FontBase::init()
{
    m_created   = T100FALSE;
}

T100VOID T100FontBase::uninit()
{

}

HFONT T100FontBase::GetHFONT()
{
    return m_hfont;
}

T100VOID T100FontBase::SetFaceName(const T100WSTRING& name)
{
    m_faceName      = name;
}

const T100WSTRING& T100FontBase::GetFaceName()
{
    return m_faceName;
}

T100VOID T100FontBase::SetWidth(T100INT value)
{
    m_width         = value;
}

T100INT T100FontBase::GetWidth()
{
    return m_width;
}

T100VOID T100FontBase::SetHeight(T100INT value)
{
    m_height        = value;
}

T100INT T100FontBase::GetHeight()
{
    return m_height;
}

T100VOID T100FontBase::SetEscapement(T100INT value)
{
    m_escapement    = value;
}

T100INT T100FontBase::GetEscapement()
{
    return m_escapement;
}

T100VOID T100FontBase::SetOrientation(T100INT value)
{
    m_orientation   = value;
}

T100INT T100FontBase::GetOrientation()
{
    return m_orientation;
}

T100VOID T100FontBase::SetWeight(T100INT value)
{
    m_weight        = value;
}

T100INT T100FontBase::GetWeight()
{
    return m_weight;
}

T100VOID T100FontBase::SetItalic(T100BYTE value)
{
    m_italic        = value;
}

T100BYTE T100FontBase::GetItalic()
{
    return m_italic;
}

T100VOID T100FontBase::SetUnderline(T100BYTE value)
{
    m_underline     = value;
}

T100BYTE T100FontBase::GetUnderline()
{
    return m_underline;
}

T100VOID T100FontBase::SetStrikeOut(T100BYTE value)
{
    m_strikeOut     = value;
}

T100BYTE T100FontBase::GetStrikeOut()
{
    return m_strikeOut;
}

T100VOID T100FontBase::SetCharSet(T100BYTE value)
{
    m_charSet       = value;
}

T100BYTE T100FontBase::GetCharSet()
{
    return m_charSet;
}

T100VOID T100FontBase::SetOutPrecision(T100BYTE value)
{
    m_outPrecision  = value;
}

T100BYTE T100FontBase::GetOutPrecision()
{
    return m_outPrecision;
}

T100VOID T100FontBase::SetClipPrecision(T100BYTE value)
{
    m_clipPrecision = value;
}

T100BYTE T100FontBase::GetClipPrecision()
{
    return m_clipPrecision;
}

T100VOID T100FontBase::SetQuality(T100BYTE value)
{
    m_quality       = value;
}

T100BYTE T100FontBase::GetQuality()
{
    return m_quality;
}

T100VOID T100FontBase::SetPitchAndFamily(T100BYTE value)
{
    m_pitchAndFamily    = value;
}

T100BYTE T100FontBase::GetPitchAndFamily()
{
    return m_pitchAndFamily;
}

}
