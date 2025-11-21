#include "T100Sphere.h"

#include "T100DX12Studio.h"
#include "T100DX12Model.h"

T100ENTITY_TYPE         T100Sphere::Type            = T100ENTITY_SPHERE;
T100WSTRING             T100Sphere::Name            = L"Sphere";

T100Sphere::T100Sphere() :
    T100Editable()
{
    //ctor
    init();
}

T100Sphere::~T100Sphere()
{
    //dtor
    uninit();
}

T100VOID T100Sphere::init()
{
    T100Entity::Name    = L"Sphere";
    T100Entity::Type    = T100ENTITY_SPHERE;
}

T100VOID T100Sphere::uninit()
{

}

T100VOID T100Sphere::Load(T100DX12Scene* scene)
{
    vertex      = T100NEW Vertex[4];

    vertex[0]   = {{-1.0f, 1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[1]   = {{1.0f, 1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[2]   = {{-1.0f, -1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[3]   = {{1.0f, -1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    Length      = sizeof(Vertex) * 4;

    if(m_editable){
        m_selection = T100NEW T100Sphere();
        m_selection->SetColour(255, 0, 0, 0);
        m_selection->Load(scene);
    }
}

T100DX12Model* T100Sphere::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model   = T100NEW T100DX12Model();

    model->Type         = T100DX12_MODEL_SPHERE;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);

    model->m_visible    = m_visible;

    model->vertex       = vertex;
    model->Length       = Length;

    studio->m_scene_manager.GetScene()->CompileShaderFile(file, vertexName, vertexID, model->vertexShader);
    studio->m_scene_manager.GetScene()->CompileShaderFile(file, pixelName, pixelID, model->pixelShader);

    model->VertexDescriptions           = const_cast<D3D12_INPUT_ELEMENT_DESC*>((D3D12_INPUT_ELEMENT_DESC*)StandardVertexDescription);
    model->VertexDescriptionsLength     = StandardVertexDescriptionNumElements;
    model->m_numIndices = 4;

    model->RenderType   = model->ConvertRenderType(m_renderType);
    model->MotionType   = model->ConvertMotionType(m_motionType);

    memcpy(&model->Bundle, &m_bundle, sizeof(T100BUNDLE));

    m_model     = model;

    if(m_editable){
        m_model->m_selection    = m_selection->Convert(studio);
        m_model->m_editable     = T100TRUE;
    }

    return model;
}

T100VOID T100Sphere::ToJSON(JSON& json)
{
    EntityToJSON(json);
}

T100VOID T100Sphere::FromJSON(JSON& json)
{
    EntityFromJSON(json);
}
