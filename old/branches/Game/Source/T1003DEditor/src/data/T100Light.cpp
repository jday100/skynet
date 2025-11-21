#include "T100Light.h"

#include "entity/T100Rectangle.h"
#include "T100DX12Studio.h"
#include "T100DX12Model.h"

T100ENTITY_TYPE         T100Light::Type           = T100ENTITY_LIGHT;
T100WSTRING             T100Light::Name           = L"Light";

T100Light::T100Light() :
    T100Editable()
{
    //ctor
    init();
}

T100Light::~T100Light()
{
    //dtor
    uninit();
}


T100VOID T100Light::init()
{
    T100Entity::Name    = L"Light";
    T100Entity::Type    = T100ENTITY_LIGHT;
}

T100VOID T100Light::uninit()
{

}

T100VOID T100Light::Load(T100DX12Scene* scene)
{
    if(m_editable){
        m_selection = T100NEW T100Rectangle();
        m_selection->SetColour(255, 0, 0, 0);

        m_selection->VertexShaderFile.TYPE    = scene->VertexShaderFile.TYPE;
        m_selection->VertexShaderFile.FILE    = scene->VertexShaderFile.FILE;
        m_selection->VertexShaderFile.ENTRY   = scene->VertexShaderFile.ENTRY;
        m_selection->VertexShaderFile.TARGET  = scene->VertexShaderFile.TARGET;

        m_selection->PixelShaderFile.TYPE     = scene->PixelShaderFile.TYPE;
        m_selection->PixelShaderFile.FILE     = scene->PixelShaderFile.FILE;
        m_selection->PixelShaderFile.ENTRY    = scene->PixelShaderFile.ENTRY;
        m_selection->PixelShaderFile.TARGET   = scene->PixelShaderFile.TARGET;

        m_selection->VertexDescriptions       = scene->VertexDescriptions;
        m_selection->ShaderParameters         = scene->ShaderParameters;

        m_selection->Load(scene);
    }
}

T100DX12Model* T100Light::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model   = T100NEW T100DX12Model();

    model->Type         = T100DX12_MODEL_LIGHT;

    m_model     = model;

    if(m_editable){
        m_model->m_selection    = m_selection->Convert(studio);
        m_model->m_editable     = T100TRUE;
    }

    return model;
}

T100VOID T100Light::ToJSON(JSON& json)
{
    T100Entity*     entity      = this;

    json["name"]        = entity->Name;
}

T100VOID T100Light::FromJSON(JSON& json)
{
    T100Entity*     entity      = this;

    entity->Name        = json["name"].get<std::wstring>();
}

/*
T100VOID T100Light::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
}

T100VOID T100Light::SetPosition(T100Vector3 value)
{
    m_position  = value;
}

T100Vector3 T100Light::GetPosition()
{
    return m_position;
}
*/

T100VOID T100Light::SetDirection(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_direction = {x, y, z};
}

T100VOID T100Light::SetDirection(T100Vector3 value)
{
    m_direction = value;
}

T100Vector3 T100Light::GetDirection()
{
    return m_direction;
}
