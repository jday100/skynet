#include "T100DX12Renderer.h"

T100DX12Renderer::T100DX12Renderer()
    :T100Renderer(), m_dx12(T100NULL)
{
    //ctor
    init();
}

T100DX12Renderer::~T100DX12Renderer()
{
    //dtor
    uninit();
}

T100VOID T100DX12Renderer::init()
{

}

T100VOID T100DX12Renderer::uninit()
{

}

T100BOOL T100DX12Renderer::create(HWND hwnd)
{
    m_dx12  = T100NEW T100DX12(hwnd);

    //m_dx12->start();
}

T100BOOL T100DX12Renderer::destroy()
{
    //m_dx12->stop();

    T100SAFE_DELETE m_dx12;
}

T100BOOL T100DX12Renderer::render()
{
    //m_dx12->render();
}
