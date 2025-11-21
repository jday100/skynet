#include "data/T100DX12Mesh.h"

#include "T100DX12Common.h"
#include "math/T100DX12MathTools.h"

T100DX12Mesh::T100DX12Mesh() :
    T100MeshInstance()
{
    //ctor
}

T100DX12Mesh::~T100DX12Mesh()
{
    //dtor
}

T100VOID T100DX12Mesh::Load()
{

}

T100VOID T100DX12Mesh::Append(T100DX12Context* contextPtr)
{
    m_contexts.push_back(contextPtr);
}

T100VOID T100DX12Mesh::Remove(T100DX12Context* contextPtr)
{

}

T100VOID T100DX12Mesh::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_POSITION, m_position);
    }
}

T100VOID T100DX12Mesh::SetPosition(T100Vector3f& value)
{
    m_position  = value;
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_POSITION, m_position);
    }
}

T100VOID T100DX12Mesh::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    T100Vector3f    rotation    = {x, y, z};
    AngleToRadian(rotation, m_rotation);
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_ROTATION, m_rotation);
    }
}

T100VOID T100DX12Mesh::SetRotation(T100Vector3f& value)
{
    AngleToRadian(value, m_rotation);
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_ROTATION, m_rotation);
    }
}

T100VOID T100DX12Mesh::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_scaling   = {x, y, z};
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_SCALING, m_scaling);
    }
}

T100VOID T100DX12Mesh::SetScaling(T100Vector3f& value)
{
    m_scaling   = value;
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_SCALING, m_scaling);
    }
}

T100VOID T100DX12Mesh::SetVisible(T100BOOL flag)
{
    m_visible   = flag;
    for(T100DX12Context* context : m_contexts){
        context->AppendEvent(T100DX12_CONTEXT_EVENT_VISIBLE, m_visible);
    }
}

T100VOID T100DX12Mesh::Clear()
{
    for(T100DX12Context* context : m_contexts)
    {
        context->Clear();
    }
}
