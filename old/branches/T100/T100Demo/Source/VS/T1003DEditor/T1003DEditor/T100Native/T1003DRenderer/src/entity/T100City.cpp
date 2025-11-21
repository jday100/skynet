#include "entity/T100City.h"

#include "link/T100Instance.h"

T100WSTRING         T100City::Name          = L"City";
T100UINT            T100City::Type          = T100ENTITY_CITY;

T100City::T100City() :
    T100Entity()
{
    //ctor
    init();
}

T100City::~T100City()
{
    //dtor
    uninit();
}

T100VOID T100City::init()
{
    T100Entity::Name        = L"City";
    T100Entity::Type        = T100ENTITY_CITY;

    VertexShaderFile.TYPE   = T100SHADER_FILE_COMPILED;
    VertexShaderFile.FILE   = L"entity/shader_mesh_simple_vert.cso";

    PixelShaderFile1.TYPE   = T100SHADER_FILE_COMPILED;
    PixelShaderFile1.FILE   = L"entity/shader_mesh_simple_pixel.cso";

    PixelShaderFile2.TYPE   = T100SHADER_FILE_COMPILED;
    PixelShaderFile2.FILE   = L"entity/shader_mesh_alt_pixel.cso";

    MeshDataFile.FILE       = L"entity/occcity.bin";
}

T100VOID T100City::uninit()
{

}

T100VOID T100City::Load()
{
    VertexDescription       = T100NEW T100D3D12_INPUT_ELEMENT_DESC[4];

    VertexDescription[0]    = { "POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[1]    = { "NORMAL",   0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[2]    = { "TEXCOORD", 0, T100DXGI_FORMAT_R32G32_FLOAT,    0, 24, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[3]    = { "TANGENT",  0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 32, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

    VertexDescriptionLength = 4;

    m_bundle.USED       = T100TRUE;
    m_bundle.AMOUNT.X   = 3;
    m_bundle.AMOUNT.Y   = 1;
    m_bundle.AMOUNT.Z   = 10;
    m_bundle.SPACING.X  = 15;
    m_bundle.SPACING.Z  = 15;

    if(m_editable){
        T100City*       city    = T100NEW T100City();
        m_selectionPtr  = city;
    }
}

T100VOID T100City::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T100City::SetPosition(T100Vector3f& value)
{
    m_position  = value;
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T100City::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100City::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100City::ToJSON(JSON& json)
{

}

T100VOID T100City::FromJSON(JSON& json)
{

}

T100VOID T100City::Clear()
{
    if(m_instancePtr){
        m_instancePtr->Clear();
    }
}
