#include "T100FontDialog.h"

namespace T100WINDOWS{

T100FontDialog::T100FontDialog() :
    T100Dialog()
{
    //ctor
}

T100FontDialog::~T100FontDialog()
{
    //dtor
}

T100VOID T100FontDialog::Create(T100Window* parent)
{

}

T100VOID T100FontDialog::Destroy()
{

}

T100VOID T100FontDialog::SetFont(const T100Font& font)
{
    m_font      = font;
}

const T100Font& T100FontDialog::GetFont()
{
    return m_font;
}

}
