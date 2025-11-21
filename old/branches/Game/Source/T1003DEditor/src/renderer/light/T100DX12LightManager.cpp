#include "T100DX12LightManager.h"

T100DX12LightManager::T100DX12LightManager(T100DX12Studio* studio) :
    m_studioPtr(studio),
    m_lights()
{
    //ctor
}

T100DX12LightManager::~T100DX12LightManager()
{
    //dtor
}

T100DX12_LIGHT_VECTOR& T100DX12LightManager::GetLights()
{
    return m_lights;
}

T100VOID T100DX12LightManager::Append(T100Light* light)
{
    T100DX12Light*  instance    = T100NEW T100DX12Light();

    ConvertLight(instance, light);

    instance->m_source  = light;
    light->m_light      = instance;

    m_lights.push_back(instance);
}

T100VOID T100DX12LightManager::Remove(T100Light* light)
{

}

T100VOID T100DX12LightManager::ConvertLight(T100DX12Light* target, T100Light* source)
{
    target->SetPosition(source->GetPosition());
}
