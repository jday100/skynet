#include "T100WxAppManager.h"

namespace T100WxWidgets{

T100WxAppManager::T100WxAppManager()
    :T100Library::T100AppManager()
{
    //ctor
    create();
}

T100WxAppManager::~T100WxAppManager()
{
    //dtor
    destroy();
}

T100VOID T100WxAppManager::create()
{
    wxLocale(wxLANGUAGE_CHINESE_SIMPLIFIED);
}

T100VOID T100WxAppManager::destroy()
{

}

wxFrame* T100WxAppManager::getFrame()
{
    return m_frame;
}

T100BOOL T100WxAppManager::quit(T100WORD value)
{
    //m_frame->Destroy();

    return T100AppManager::quit(value);
}

}
