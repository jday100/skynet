#include "T100WxAppManager.h"

namespace T100WxWidgets{

T100WxAppManager::T100WxAppManager()
    :T100Library::T100AppManager()
{
    //ctor
}

T100WxAppManager::~T100WxAppManager()
{
    //dtor
}

wxFrame* T100WxAppManager::getFrame()
{
    return m_frame;
}

}
