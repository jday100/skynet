#include "T1003DEditorDescriptionFile.h"

T1003DEditorDescriptionFile::T1003DEditorDescriptionFile(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& descs) :
    m_descs(descs)
{
    //ctor
}

T1003DEditorDescriptionFile::~T1003DEditorDescriptionFile()
{
    //dtor
}

T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& T1003DEditorDescriptionFile::GetDescriptions()
{
    return m_descs;
}

T100VOID T1003DEditorDescriptionFile::encode()
{
    JSON        json;

    for(T100D3D12_INPUT_ELEMENT_DESC* desc : m_descs){
        JSON        thisDesc;
        EncodeDesc(desc, thisDesc);
        json.push_back(thisDesc);
    }

    m_json["descriptions"]      = json;
}

T100VOID T1003DEditorDescriptionFile::EncodeDesc(T100D3D12_INPUT_ELEMENT_DESC* desc, JSON& json)
{
    std::wstring        name    = desc->SemanticName;
    json["name"]        = name;
    json["index"]       = desc->SemanticIndex;
    json["format"]      = desc->Format;
    json["slot"]        = desc->InputSlot;
    json["offset"]      = desc->AlignedByteOffset;
    json["class"]       = desc->InputSlotClass;
    json["rate"]        = desc->InstanceDataStepRate;
}

T100VOID T1003DEditorDescriptionFile::decode()
{
    JSON&       descs       = m_json["descriptions"];

    for(JSON::iterator it = descs.begin(); it != descs.end(); ++it)
    {
        JSON&       thisDesc  = it.value();
        DecodeDesc(thisDesc);
    }
}

T100VOID T1003DEditorDescriptionFile::DecodeDesc(JSON& json)
{
    T100D3D12_INPUT_ELEMENT_DESC*       data        = T100NEW T100D3D12_INPUT_ELEMENT_DESC();

    data->SemanticName              = json["name"].get<std::wstring>().c_str();
    data->SemanticIndex             = json["index"].get<T100UINT>();
    data->Format                    = ConvertFormat(json["format"].get<T100UINT>());
    data->InputSlot                 = json["slot"].get<T100UINT>();
    data->AlignedByteOffset         = json["offset"].get<T100UINT>();
    data->InputSlotClass            = ConvertClassification(json["class"].get<T100UINT>());
    data->InstanceDataStepRate      = json["rate"].get<T100UINT>();

    m_descs.push_back(data);
}

T100DXGI_FORMAT T1003DEditorDescriptionFile::ConvertFormat(T100UINT value)
{
    T100DXGI_FORMAT         result;

    switch(value){
    case 0:
        {
            result  = T100DXGI_FORMAT_UNKNOWN;
        }
        break;
    case 1:
        {
            result  = T100DXGI_FORMAT_R32G32B32A32_TYPELESS;
        }
        break;
    case 2:
        {
            result  = T100DXGI_FORMAT_R32G32B32A32_FLOAT;
        }
        break;
    case 3:
        {
            result  = T100DXGI_FORMAT_R32G32B32A32_UINT;
        }
        break;

    case 4:
        {
            result  = T100DXGI_FORMAT_R32G32B32A32_SINT;
        }
        break;
    case 5:
        {
            result  = T100DXGI_FORMAT_R32G32B32_TYPELESS;
        }
        break;
    case 6:
        {
            result  = T100DXGI_FORMAT_R32G32B32_FLOAT;
        }
        break;
    case 7:
        {
            result  = T100DXGI_FORMAT_R32G32B32_UINT;
        }
        break;

    case 8:
        {
            result  = T100DXGI_FORMAT_R32G32B32_SINT;
        }
        break;
    case 9:
        {
            result  = T100DXGI_FORMAT_R16G16B16A16_TYPELESS;
        }
        break;
    case 10:
        {
            result  = T100DXGI_FORMAT_R16G16B16A16_FLOAT;
        }
        break;
    case 11:
        {
            result  = T100DXGI_FORMAT_R16G16B16A16_UNORM;
        }
        break;

    case 12:
        {
            result  = T100DXGI_FORMAT_R16G16B16A16_UINT;
        }
        break;
    case 13:
        {
            result  = T100DXGI_FORMAT_R16G16B16A16_SNORM;
        }
        break;
    case 14:
        {
            result  = T100DXGI_FORMAT_R16G16B16A16_SINT;
        }
        break;
    case 15:
        {
            result  = T100DXGI_FORMAT_R32G32_TYPELESS;
        }
        break;

    case 16:
        {
            result  = T100DXGI_FORMAT_R32G32_FLOAT;
        }
        break;
    case 17:
        {
            result  = T100DXGI_FORMAT_R32G32_UINT;
        }
        break;
    case 18:
        {
            result  = T100DXGI_FORMAT_R32G32_SINT;
        }
        break;
    case 19:
        {
            result  = T100DXGI_FORMAT_R32G8X24_TYPELESS;
        }
        break;

    case 20:
        {
            result  = T100DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
        }
        break;
    case 21:
        {
            result  = T100DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
        }
        break;
    case 22:
        {
            result  = T100DXGI_FORMAT_X32_TYPELESS_G8X24_UINT;
        }
        break;
    case 23:
        {
            result  = T100DXGI_FORMAT_R10G10B10A2_TYPELESS;
        }
        break;

    case 24:
        {
            result  = T100DXGI_FORMAT_R10G10B10A2_UNORM;
        }
        break;
    case 25:
        {
            result  = T100DXGI_FORMAT_R10G10B10A2_UINT;
        }
        break;
    case 26:
        {
            result  = T100DXGI_FORMAT_R11G11B10_FLOAT;
        }
        break;
    case 27:
        {
            result  = T100DXGI_FORMAT_R8G8B8A8_TYPELESS;
        }
        break;

    case 28:
        {
            result  = T100DXGI_FORMAT_R8G8B8A8_UNORM;
        }
        break;
    case 29:
        {
            result  = T100DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
        }
        break;
    case 30:
        {
            result  = T100DXGI_FORMAT_R8G8B8A8_UINT;
        }
        break;
    case 31:
        {
            result  = T100DXGI_FORMAT_R8G8B8A8_SNORM;
        }
        break;

    case 32:
        {
            result  = T100DXGI_FORMAT_R8G8B8A8_SINT;
        }
        break;
    case 33:
        {
            result  = T100DXGI_FORMAT_R16G16_TYPELESS;
        }
        break;
    case 34:
        {
            result  = T100DXGI_FORMAT_R16G16_FLOAT;
        }
        break;
    case 35:
        {
            result  = T100DXGI_FORMAT_R16G16_UNORM;
        }
        break;

    case 36:
        {
            result  = T100DXGI_FORMAT_R16G16_UINT;
        }
        break;
    case 37:
        {
            result  = T100DXGI_FORMAT_R16G16_SNORM;
        }
        break;
    case 38:
        {
            result  = T100DXGI_FORMAT_R16G16_SINT;
        }
        break;
    case 39:
        {
            result  = T100DXGI_FORMAT_R32_TYPELESS;
        }
        break;

    case 40:
        {
            result  = T100DXGI_FORMAT_D32_FLOAT;
        }
        break;
    case 41:
        {
            result  = T100DXGI_FORMAT_R32_FLOAT;
        }
        break;
    case 42:
        {
            result  = T100DXGI_FORMAT_R32_UINT;
        }
        break;
    case 43:
        {
            result  = T100DXGI_FORMAT_R32_SINT;
        }
        break;

    case 44:
        {
            result  = T100DXGI_FORMAT_R24G8_TYPELESS;
        }
        break;
    case 45:
        {
            result  = T100DXGI_FORMAT_D24_UNORM_S8_UINT;
        }
        break;
    case 46:
        {
            result  = T100DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
        }
        break;
    case 47:
        {
            result  = T100DXGI_FORMAT_X24_TYPELESS_G8_UINT;
        }
        break;

    case 48:
        {
            result  = T100DXGI_FORMAT_R8G8_TYPELESS;
        }
        break;
    case 49:
        {
            result  = T100DXGI_FORMAT_R8G8_UNORM;
        }
        break;
    case 50:
        {
            result  = T100DXGI_FORMAT_R8G8_UINT;
        }
        break;
    case 51:
        {
            result  = T100DXGI_FORMAT_R8G8_SNORM;
        }
        break;

    case 52:
        {
            result  = T100DXGI_FORMAT_R8G8_SINT;
        }
        break;
    case 53:
        {
            result  = T100DXGI_FORMAT_R16_TYPELESS;
        }
        break;
    case 54:
        {
            result  = T100DXGI_FORMAT_R16_FLOAT;
        }
        break;
    case 55:
        {
            result  = T100DXGI_FORMAT_D16_UNORM;
        }
        break;

    case 56:
        {
            result  = T100DXGI_FORMAT_R16_UNORM;
        }
        break;
    case 57:
        {
            result  = T100DXGI_FORMAT_R16_UINT;
        }
        break;
    case 58:
        {
            result  = T100DXGI_FORMAT_R16_SNORM;
        }
        break;
    case 59:
        {
            result  = T100DXGI_FORMAT_R16_SINT;
        }
        break;

    case 60:
        {
            result  = T100DXGI_FORMAT_R8_TYPELESS;
        }
        break;
    case 61:
        {
            result  = T100DXGI_FORMAT_R8_UNORM;
        }
        break;
    case 62:
        {
            result  = T100DXGI_FORMAT_R8_UINT;
        }
        break;
    case 63:
        {
            result  = T100DXGI_FORMAT_R8_SNORM;
        }
        break;

    case 64:
        {
            result  = T100DXGI_FORMAT_R8_SINT;
        }
        break;
    case 65:
        {
            result  = T100DXGI_FORMAT_A8_UNORM;
        }
        break;
    case 66:
        {
            result  = T100DXGI_FORMAT_R1_UNORM;
        }
        break;
    case 67:
        {
            result  = T100DXGI_FORMAT_R9G9B9E5_SHAREDEXP;
        }
        break;

    case 68:
        {
            result  = T100DXGI_FORMAT_R8G8_B8G8_UNORM;
        }
        break;
    case 69:
        {
            result  = T100DXGI_FORMAT_G8R8_G8B8_UNORM;
        }
        break;
    case 70:
        {
            result  = T100DXGI_FORMAT_BC1_TYPELESS;
        }
        break;
    case 71:
        {
            result  = T100DXGI_FORMAT_BC1_UNORM;
        }
        break;

    case 72:
        {
            result  = T100DXGI_FORMAT_BC1_UNORM_SRGB;
        }
        break;
    case 73:
        {
            result  = T100DXGI_FORMAT_BC2_TYPELESS;
        }
        break;
    case 74:
        {
            result  = T100DXGI_FORMAT_BC2_UNORM;
        }
        break;
    case 75:
        {
            result  = T100DXGI_FORMAT_BC2_UNORM_SRGB;
        }
        break;

    case 76:
        {
            result  = T100DXGI_FORMAT_BC3_TYPELESS;
        }
        break;
    case 77:
        {
            result  = T100DXGI_FORMAT_BC3_UNORM;
        }
        break;
    case 78:
        {
            result  = T100DXGI_FORMAT_BC3_UNORM_SRGB;
        }
        break;
    case 79:
        {
            result  = T100DXGI_FORMAT_BC4_TYPELESS;
        }
        break;

    case 80:
        {
            result  = T100DXGI_FORMAT_BC4_UNORM;
        }
        break;
    case 81:
        {
            result  = T100DXGI_FORMAT_BC4_SNORM;
        }
        break;
    case 82:
        {
            result  = T100DXGI_FORMAT_BC5_TYPELESS;
        }
        break;
    case 83:
        {
            result  = T100DXGI_FORMAT_BC5_UNORM;
        }
        break;

    case 84:
        {
            result  = T100DXGI_FORMAT_BC5_SNORM;
        }
        break;
    case 85:
        {
            result  = T100DXGI_FORMAT_B5G6R5_UNORM;
        }
        break;
    case 86:
        {
            result  = T100DXGI_FORMAT_B5G5R5A1_UNORM;
        }
        break;
    case 87:
        {
            result  = T100DXGI_FORMAT_B8G8R8A8_UNORM;
        }
        break;

    case 88:
        {
            result  = T100DXGI_FORMAT_B8G8R8X8_UNORM;
        }
        break;
    case 89:
        {
            result  = T100DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM;
        }
        break;
    case 90:
        {
            result  = T100DXGI_FORMAT_B8G8R8A8_TYPELESS;
        }
        break;
    case 91:
        {
            result  = T100DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
        }
        break;

    case 92:
        {
            result  = T100DXGI_FORMAT_B8G8R8X8_TYPELESS;
        }
        break;
    case 93:
        {
            result  = T100DXGI_FORMAT_B8G8R8X8_UNORM_SRGB;
        }
        break;
    case 94:
        {
            result  = T100DXGI_FORMAT_BC6H_TYPELESS;
        }
        break;
    case 95:
        {
            result  = T100DXGI_FORMAT_BC6H_UF16;
        }
        break;

    case 96:
        {
            result  = T100DXGI_FORMAT_BC6H_SF16;
        }
        break;
    case 97:
        {
            result  = T100DXGI_FORMAT_BC7_TYPELESS;
        }
        break;
    case 98:
        {
            result  = T100DXGI_FORMAT_BC7_UNORM;
        }
        break;
    case 99:
        {
            result  = T100DXGI_FORMAT_BC7_UNORM_SRGB;
        }
        break;

    case 100:
        {
            result  = T100DXGI_FORMAT_AYUV;
        }
        break;
    case 101:
        {
            result  = T100DXGI_FORMAT_Y410;
        }
        break;
    case 102:
        {
            result  = T100DXGI_FORMAT_Y416;
        }
        break;
    case 103:
        {
            result  = T100DXGI_FORMAT_NV12;
        }
        break;

    case 104:
        {
            result  = T100DXGI_FORMAT_P010;
        }
        break;
    case 105:
        {
            result  = T100DXGI_FORMAT_P016;
        }
        break;
    case 106:
        {
            result  = T100DXGI_FORMAT_420_OPAQUE;
        }
        break;
    case 107:
        {
            result  = T100DXGI_FORMAT_YUY2;
        }
        break;

    case 108:
        {
            result  = T100DXGI_FORMAT_Y210;
        }
        break;
    case 109:
        {
            result  = T100DXGI_FORMAT_Y216;
        }
        break;
    case 110:
        {
            result  = T100DXGI_FORMAT_NV11;
        }
        break;
    case 111:
        {
            result  = T100DXGI_FORMAT_AI44;
        }
        break;

    case 112:
        {
            result  = T100DXGI_FORMAT_IA44;
        }
        break;
    case 113:
        {
            result  = T100DXGI_FORMAT_P8;
        }
        break;
    case 114:
        {
            result  = T100DXGI_FORMAT_A8P8;
        }
        break;
    case 115:
        {
            result  = T100DXGI_FORMAT_B4G4R4A4_UNORM;
        }
        break;

    case 130:
        {
            result  = T100DXGI_FORMAT_P208;
        }
        break;
    case 131:
        {
            result  = T100DXGI_FORMAT_V208;
        }
        break;
    case 132:
        {
            result  = T100DXGI_FORMAT_V408;
        }
        break;
    case -1:
        {
            result  = T100DXGI_FORMAT_FORCE_UINT;
        }
        break;
    }

    return result;
}

T100D3D12_INPUT_CLASSIFICATION T1003DEditorDescriptionFile::ConvertClassification(T100UINT value)
{
    T100D3D12_INPUT_CLASSIFICATION          result;

    switch(value){
    case 0:
        {
            result  = T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        }
        break;
    case 1:
        {
            result  = T100D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA;
        }
        break;
    }

    return result;
}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorDescriptionFile& desc)
{
    ifs >> desc.m_json;
    desc.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorDescriptionFile& desc)
{
    desc.encode();
    ofs << desc.m_json;
    return ofs;
}
