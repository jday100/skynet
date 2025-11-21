#include "T1003DEditorLightManager.h"

#include <wx/wx.h>
#include "T1003DEditorServe.h"
#include "T1003DEditorCallback.h"

T1003DEditorLightManager::T1003DEditorLightManager(T1003DEditorServe* serve) :
    m_servePtr(serve)
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

T100Light* T1003DEditorLightManager::GetLight()
{
    T100Light*      light       = T100NEW T100Light();
    T100Entity*     entity;

    light->SetEditable(T100TRUE);
    entity  = light;

    int     i       = ++m_lightCount;
    entity->Name     = wxString::Format(L"Light%u", i);
    return light;
}
