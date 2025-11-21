#include "T100Entity.h"

#include "T100VectorTools.h"
#include "T100DX12Model.h"

T100Entity::T100Entity() :
    m_position(),
    m_rotation(),
    m_scaling(1, 1, 1),
    m_colour(1, 1, 1, 0)
{
    //ctor
}

T100Entity::~T100Entity()
{
    //dtor
}

T100VOID T100Entity::SetVisible(T100BOOL visible)
{
    m_visible   = visible;
    if(m_model){
        m_model->SetVisible(visible);
    }
}

T100BOOL T100Entity::GetVisible()
{
    return m_visible;
}

T100VOID T100Entity::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_model){
        m_model->SetPosition(m_position);
    }
}

T100VOID T100Entity::SetPosition(T100Vector3 value)
{
    m_position  = value;
    if(m_model){
        m_model->SetPosition(m_position);
    }
}

T100Vector3 T100Entity::GetPosition()
{
    return m_position;
}

T100VOID T100Entity::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_model){
        m_model->SetRotation(m_rotation);
    }
}

T100VOID T100Entity::SetRotation(T100Vector3 value)
{
    m_rotation  = value;
    if(m_model){
        m_model->SetRotation(m_rotation);
    }
}

T100Vector3 T100Entity::GetRotation()
{
    return m_rotation;
}

T100VOID T100Entity::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_scaling   = {x, y, z};
}

T100VOID T100Entity::SetScaling(T100Vector3 value)
{
    m_scaling   = value;
}

T100Vector3 T100Entity::GetScaling()
{
    return m_scaling;
}

T100VOID T100Entity::SetOrigin(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_origin    = {x, y, z};
}

T100VOID T100Entity::SetOrigin(T100Vector3 value)
{
    m_origin    = value;
}

T100Vector3 T100Entity::GetOrigin()
{
    return m_origin;
}

T100VOID T100Entity::SetColour(T100UINT r, T100UINT g, T100UINT b, T100UINT a)
{
    m_colour    = {r, g, b, a};
}

T100VOID T100Entity::SetColour(T100Vector4u value)
{
    m_colour    = value;
}

T100Vector4u T100Entity::GetColour()
{
    return m_colour;
}

T100VOID T100Entity::SetBundle(T100BOOL value)
{
    m_bundle.USED   = value;

    if(value){
        m_bundle.AMOUNT.X   = m_bundle.AMOUNT.X == 0 ? 1 : m_bundle.AMOUNT.X;
        m_bundle.AMOUNT.Y   = m_bundle.AMOUNT.Y == 0 ? 1 : m_bundle.AMOUNT.Y;
        m_bundle.AMOUNT.Z   = m_bundle.AMOUNT.Z == 0 ? 1 : m_bundle.AMOUNT.Z;
    }

    if(m_model){

    }
}

T100BOOL T100Entity::GetBundle()
{
    return m_bundle.USED;
}

T100VOID T100Entity::SetBundleAmount(T100UINT x, T100UINT y, T100UINT z)
{
    m_bundle.AMOUNT.X   = x;
    m_bundle.AMOUNT.Y   = y;
    m_bundle.AMOUNT.Z   = z;
}

T100VOID T100Entity::SetBundleAmount(T100Vector3u& amount)
{
    memcpy(&m_bundle.AMOUNT, &amount.UINT3, sizeof(T100UINT) * 3);
}

T100Vector3u T100Entity::GetBundleAmount()
{
    T100Vector3u    result;

    result.X    = m_bundle.AMOUNT.X;
    result.Y    = m_bundle.AMOUNT.Y;
    result.Z    = m_bundle.AMOUNT.Z;

    return result;
}

T100VOID T100Entity::SetBundleSpacing(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_bundle.SPACING.X  = x;
    m_bundle.SPACING.Y  = y;
    m_bundle.SPACING.Z  = z;
}

T100VOID T100Entity::SetBundleSpacing(T100Vector3& spacing)
{
    memcpy(&m_bundle.SPACING, &spacing.FLOAT3, sizeof(T100FLOAT) * 3);
}

T100Vector3 T100Entity::GetBundleSpacing()
{
    T100Vector3     result;

    result.X    = m_bundle.SPACING.X;
    result.Y    = m_bundle.SPACING.Y;
    result.Z    = m_bundle.SPACING.Z;

    return result;
}

T100VOID T100Entity::SetRenderType(T100_RENDER_TYPE type)
{
    m_renderType    = type;
}

T100_RENDER_TYPE T100Entity::GetRenderType()
{
    return m_renderType;
}

T100VOID T100Entity::SetMotionType(T100_MOTION_TYPE type)
{
    m_motionType    = type;
}

T100_MOTION_TYPE T100Entity::GetMotionType()
{
    return m_motionType;
}

T100VOID T100Entity::SetMaterial(T100WSTRING material)
{
    m_material  = material;
}

T100WSTRING& T100Entity::GetMaterial()
{
    return m_material;
}

T100VOID T100Entity::Transition2D(T100Vector3 source, T100Vector3& target)
{
    XMVECTOR    value;
    XMVECTOR    rotation;
    XMVECTOR    result;

    value       = XMLoadFloat3((XMFLOAT3*)&source.FLOAT3);
    rotation    = XMLoadFloat3((XMFLOAT3*)&m_rotation.FLOAT3);

    result  = XMVector3Rotate(value, rotation);

    XMStoreFloat3((XMFLOAT3*)&target.FLOAT3, result);
}

T100ENTITY_TYPE T100Entity::ConvertEntityType(T100UINT value)
{
    switch(value){
    case 1:
        {
            return T100ENTITY_DOT;
        }
        break;
    case 2:
        {
            return T100ENTITY_LINE;
        }
        break;
    case 3:
        {
            return T100ENTITY_TRIANGLE;
        }
        break;
    case 4:
        {
            return T100ENTITY_CITY;
        }
        break;
    }
}

T100VOID T100Entity::EntityToJSON(JSON& json)
{
    json["name"]        = Name;
    json["type"]        = Type;

    json["visible"]     = m_visible;
    json["position"]    = m_position.FLOAT3;
    json["rotation"]    = m_rotation.FLOAT3;
    json["scaling"]     = m_scaling.FLOAT3;
    json["origin"]      = m_origin.FLOAT3;
    json["colour"]      = m_colour.UINT4;
}

T100VOID T100Entity::EntityFromJSON(JSON& json)
{
    Name            = json["name"].get<std::wstring>();
    Type            = ConvertEntityType(json["type"]);

    m_visible       = json["visible"].get<bool>();
    json["position"].get_to(m_position.FLOAT3);
    json["rotation"].get_to(m_rotation.FLOAT3);
    json["scaling"].get_to(m_scaling.FLOAT3);
    json["origin"].get_to(m_origin.FLOAT3);
    json["colour"].get_to(m_colour.UINT4);
}

T100VOID T100Entity::Clear()
{
    if(m_model){
        m_model->Clear();
        T100SAFE_DELETE m_model;
    }
}
