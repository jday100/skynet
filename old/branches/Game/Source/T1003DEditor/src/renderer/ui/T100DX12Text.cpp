#include "T100DX12Text.h"

T100DX12Text::T100DX12Text()
{
    //ctor
}

T100DX12Text::~T100DX12Text()
{
    //dtor
}

T100VOID T100DX12Text::SetFont(T100DX12Font* font)
{
    m_font  = font;
}

T100DX12Font* T100DX12Text::GetFont()
{
    return m_font;
}

T100VOID T100DX12Text::SetSize(T100FLOAT size)
{
    m_size  = size;
}

T100FLOAT T100DX12Text::GetSize()
{
    return m_size;
}
