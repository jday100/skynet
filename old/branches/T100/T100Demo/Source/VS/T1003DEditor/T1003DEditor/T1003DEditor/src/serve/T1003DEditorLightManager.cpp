#include "serve/T1003DEditorLightManager.h"

#include <wx/wx.h>

T1003DEditorLightManager::T1003DEditorLightManager()
{
    //ctor
    init();
}

T1003DEditorLightManager::~T1003DEditorLightManager()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorLightManager::init()
{
    m_lightCount    = 0;
}

T100VOID T1003DEditorLightManager::uninit()
{

}

T1003DLight* T1003DEditorLightManager::GetLight()
{
    T1003DLight*    light       = T100NEW T1003DLight();
    int     i       = ++m_lightCount;
    light->Name     = wxString::Format(L"Light%u", i);
    return light;
}
