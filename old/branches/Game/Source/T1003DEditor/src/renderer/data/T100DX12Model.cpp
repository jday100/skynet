#include "T100DX12Model.h"

#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12Model::T100DX12Model()
{
    //ctor
}

T100DX12Model::~T100DX12Model()
{
    //dtor
}

T100VOID T100DX12Model::Load(T100DX12Studio* studio)
{
    m_studio    = studio;
}

T100VOID T100DX12Model::Upload(T100DX12Studio* studio)
{
}

T100VOID T100DX12Model::Update()
{

}

T100VOID T100DX12Model::Render(T100DX12Studio* studio, T100DX12Frame* frame)
{

}

T100VOID T100DX12Model::SetPosition(T100Vector3 value)
{
    m_position.x    = value.X;
    m_position.y    = value.Y;
    m_position.z    = value.Z;

    for(T100DX12Context* context : m_contexts){
        context->Append(T100DX12_CONTEXT_EVENT_POSITION, m_position);
    }
}

T100VOID T100DX12Model::SetRotation(T100Vector3 value)
{
    m_rotation.x    = value.X;
    m_rotation.y    = value.Y;
    m_rotation.z    = value.Z;
}

T100VOID T100DX12Model::SetScaling(T100Vector3 value)
{
    m_scaling.x     = value.X;
    m_scaling.y     = value.Y;
    m_scaling.z     = value.Z;
}

T100VOID T100DX12Model::SetVisible(T100BOOL visible)
{
    m_visible   = visible;
    for(T100DX12Context* context : m_contexts){
        context->Append(T100DX12_CONTEXT_EVENT_VISIBLE, m_visible);
    }
}

T100DX12_RENDER_TYPE T100DX12Model::ConvertRenderType(T100_RENDER_TYPE type)
{
    T100DX12_RENDER_TYPE        result      = T100DX12_RENDER_2D;
    switch(type){
    case T100_RENDER_2D:
        {
            result  = T100DX12_RENDER_2D;
        }
        break;
    case T100_RENDER_3D:
        {
            result  = T100DX12_RENDER_3D;
        }
        break;
    }
    return result;
}

T100DX12_MOTION_TYPE T100DX12Model::ConvertMotionType(T100_MOTION_TYPE type)
{
    T100DX12_MOTION_TYPE        result      = T100DX12_MOTION_STILL;
    switch(type){
    case T100_MOTION_STILL:
        {
            result  = T100DX12_MOTION_STILL;
        }
        break;
    case T100_MOTION_STAND:
        {
            result  = T100DX12_MOTION_STAND;
        }
        break;
    case T100_MOTION_MOVE:
        {
            result  = T100DX12_MOTION_MOVE;
        }
        break;
    }
    return result;
}

T100VOID T100DX12Model::Clear()
{
    for(T100DX12Context* context : m_contexts)
    {
        context->Clear();
    }
}

DXGI_FORMAT T100DX12Model::ConvertFormat(T100DXGI_FORMAT format)
{
    DXGI_FORMAT     result;

    switch(format){
    case T100DXGI_FORMAT_R32G32B32_FLOAT:
        {
            result  = DXGI_FORMAT_R32G32B32_FLOAT;
        }
        break;
    case T100DXGI_FORMAT_R32G32B32A32_FLOAT:
        {
            result  = DXGI_FORMAT_R32G32B32A32_FLOAT;
        }
        break;
    }
    return result;
}

D3D12_INPUT_CLASSIFICATION T100DX12Model::ConvertInputSlotClass(T100D3D12_INPUT_CLASSIFICATION value)
{
    D3D12_INPUT_CLASSIFICATION      result;

    switch(value){
    case T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA:
        {
            result  = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        }
        break;
    }
    return result;
}
