#include "T100Triangle.h"

#include "T100DX12Model.h"
#include "T100DX12Scene.h"
#include "T100DX12Studio.h"

T100WSTRING         T100Triangle::Name          = L"Triangle";
T100ENTITY_TYPE     T100Triangle::Type          = T100ENTITY_TRIANGLE;

T100Triangle::T100Triangle() :
    T100Editable()
{
    //ctor
    init();
}

T100Triangle::~T100Triangle()
{
    //dtor
    uninit();
}

T100VOID T100Triangle::init()
{
    T100Entity::Name    = L"Triangle";
    T100Entity::Type    = T100ENTITY_TRIANGLE;

    m_renderType        = T100_RENDER_3D;
    m_motionType        = T100_MOTION_MOVE;

    vertex              = triangleVertices;
}

T100VOID T100Triangle::uninit()
{

}

T100VOID T100Triangle::Load(T100DX12Scene* scene)
{
    vertex      = triangleVertices;
    Length      = Size();

    if(m_editable){
        m_selection = T100NEW T100Triangle();
        m_selection->SetColour(255, 0, 0, 0);
        m_selection->Load(scene);
    }
}

T100DX12Model* T100Triangle::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model           = T100NEW T100DX12Model();

    model->Type                         = T100DX12_MODEL_TRIANGLE;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);

    model->m_visible                    = m_visible;

    model->vertex                       = vertex;
    model->Length                       = Size();

    studio->m_scene_manager.GetScene()->CompileShaderFile(file, vertexName, vertexID, model->vertexShader);
    studio->m_scene_manager.GetScene()->CompileShaderFile(file, pixelName, pixelID, model->pixelShader);

    model->VertexDescriptions           = const_cast<D3D12_INPUT_ELEMENT_DESC*>((D3D12_INPUT_ELEMENT_DESC*)StandardVertexDescription);
    model->VertexDescriptionsLength     = StandardVertexDescriptionNumElements;
    model->m_numIndices = 3;

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

T100VOID T100Triangle::ToJSON(JSON& json)
{
    EntityToJSON(json);
}

T100VOID T100Triangle::FromJSON(JSON& json)
{
    EntityFromJSON(json);
}
