#include "gui/font/T100Font.h"

#include "gui/font/T100FontTools.h"

T100Font::T100Font() :
    T100Class()
{
    //ctor
    Init(L"");
}

T100Font::T100Font(T100WSTRING name) :
    T100Class(),
    m_faceName(name)
{
    //ctor
    Init(name);
}

T100Font::~T100Font()
{
    //dtor
}

HFONT T100Font::GetHFONT()
{
    return m_font;
}

T100VOID T100Font::SetFaceName(T100WSTRING name)
{
    m_faceName      = name;
    Init(name);
}

T100WSTRING T100Font::GetFaceName()
{
    return m_faceName;
}

T100VOID T100Font::Init(T100WSTRING name)
{
    if(name.empty()){
        m_font      = T100FontTools::GetDefaultFont();
    }else{
        LOGFONT         font;

        GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(font), &font);

        T100INT     size;

        size    = name.size();

        size    = size > LF_FACESIZE ? LF_FACESIZE : size;

        memcpy(font.lfFaceName, name.c_str(), size);

        //font.lfFaceName = name.c_str();

        m_font      = CreateFontIndirect(&font);
    }
}
