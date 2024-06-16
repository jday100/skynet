#include "T100SoftRender.h"

#include <string.h>

T100SoftRender::T100SoftRender()
    :T100RenderBase()
{
    //ctor
}

T100SoftRender::~T100SoftRender()
{
    //dtor
}

T100VOID T100SoftRender::Start()
{

}

T100VOID T100SoftRender::Stop()
{

}

T100VOID T100SoftRender::Draw()
{
    memset(m_screen, 0, m_length);

    for(int i=0;i<m_length;i++){
        m_screen[i] = i % 255;
    }
}

T100VOID T100SoftRender::SetSize(T100INT width, T100INT height)
{
    m_width     = width;
    m_height    = height;
    m_length    = width * height * 4;
    m_screen    = T100NEW T100BYTE[m_length];
}

T100BYTE* T100SoftRender::GetData()
{
    return m_screen;
}

T100INT T100SoftRender::GetWidth()
{
    return m_width;
}

T100INT T100SoftRender::GetHeight()
{
    return m_height;
}
