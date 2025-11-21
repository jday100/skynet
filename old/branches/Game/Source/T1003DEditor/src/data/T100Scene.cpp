#include "T100Scene.h"

T100Scene::T100Scene() :
    VertexDescriptions()
{
    //ctor
    init();
}

T100Scene::~T100Scene()
{
    //dtor
    uninit();
}

T100VOID T100Scene::init()
{
    Length      = 1000;
    Width       = 1000;
    Height      = 1000;

    VertexDescriptions.Amount   = 2;
    VertexDescriptions.Descs    = T100NEW T100D3D12_INPUT_ELEMENT_DESC[2];

    VertexDescriptions.Descs[0] = {
        L"POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
    };
    VertexDescriptions.Descs[1] = {
        L"COLOR", 0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
    };

    T100D3D12_INPUT_ELEMENT_DESC& desc  = VertexDescriptions.Descs[0];

    ShaderParameters.Amount         = 2;
    ShaderParameters.Parameters     = T100NEW T100ShaderParameter[2];

    ShaderParameters.Parameters[0]  = {
        L"",
        T100D3D12_DESCRIPTOR_RANGE_TYPE_CBV,
        1, 0, 0,
        T100D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC,
        0,
        1,
        T100D3D12_SHADER_VISIBILITY_ALL
    };

    ShaderParameters.Parameters[1]  = {
        L"",
        T100D3D12_DESCRIPTOR_RANGE_TYPE_SRV,
        1, 0, 0,
        T100D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC,
        0,
        1,
        T100D3D12_SHADER_VISIBILITY_ALL
    };

    VertexShaderFile.TYPE       = T100SHADER_FILE_SOURCE;
    VertexShaderFile.FILE       = L"scene/scene_vs.hlsl";
    VertexShaderFile.ENTRY      = L"VSMain";
    VertexShaderFile.TARGET     = L"vs_5_0";

    PixelShaderFile.TYPE        = T100SHADER_FILE_SOURCE;
    PixelShaderFile.FILE        = L"scene/scene_ps.hlsl";
    PixelShaderFile.ENTRY       = L"PSMain";
    PixelShaderFile.TARGET      = L"ps_5_0";
}

T100VOID T100Scene::uninit()
{

}

T100VOID T100Scene::ToJSON(JSON& json)
{
    json["type"]        = Type;
    json["length"]      = Length;
    json["width"]       = Width;
    json["height"]      = Height;
    json["radius"]      = Radius;

    JSON        vertex;

    vertex["type"]      = VertexShaderFile.TYPE;
    vertex["file"]      = VertexShaderFile.FILE;
    vertex["entry"]     = VertexShaderFile.ENTRY;
    vertex["target"]    = VertexShaderFile.TARGET;

    json["vertex"]      = vertex;

    JSON        pixel;

    pixel["type"]       = PixelShaderFile.TYPE;
    pixel["file"]       = PixelShaderFile.FILE;
    pixel["entry"]      = PixelShaderFile.ENTRY;
    pixel["target"]     = PixelShaderFile.TARGET;

    json["pixel"]       = pixel;

    JSON        descs;

    T100UINT    damount  = VertexDescriptions.Amount;

    for(T100UINT i = 0; i < damount; i++){
        T100D3D12_INPUT_ELEMENT_DESC&   desc    = VertexDescriptions.Descs[i];
        JSON        thisDesc;

        thisDesc["name"]        = std::wstring(desc.SemanticName);
        thisDesc["index"]       = desc.SemanticIndex;
        thisDesc["format"]      = desc.Format;
        thisDesc["slot"]        = desc.InputSlot;
        thisDesc["offset"]      = desc.AlignedByteOffset;
        thisDesc["class"]       = desc.InputSlotClass;
        thisDesc["rate"]        = desc.InstanceDataStepRate;

        descs.push_back(thisDesc);
    }

    json["descriptions"]["amount"]          = damount;
    json["descriptions"]["descriptions"]    = descs;

    JSON        paras;
    T100UINT    pamount     = ShaderParameters.Amount;

    for(T100UINT i = 0; i < pamount; i++){
        T100ShaderParameter&    para        = ShaderParameters.Parameters[i];
        JSON    thisPara;

        thisPara["type"]        = para.RangeType;
        thisPara["length"]      = para.DescriptorsLength;
        thisPara["register"]    = para.BaseShaderRegister;
        thisPara["space"]       = para.RegisterSpace;
        thisPara["flags"]       = para.Flags;
        thisPara["offset"]      = para.OffsetInDescriptorsFromTableStart;
        thisPara["ranges"]      = para.NumRanges;
        thisPara["visibility"]  = para.Visibility;

        paras.push_back(thisPara);
    }

    json["parameters"]["amount"]        = pamount;
    json["parameters"]["parameters"]    = paras;
}

T100VOID T100Scene::FromJSON(JSON& json)
{
    Type        = ConvertSceneType(json["type"]);
    Length      = json["length"];
    Width       = json["width"];
    Height      = json["Height"];
    Radius      = json["radius"];

    JSON        vertex      = json["vertex"];

    VertexShaderFile.TYPE   = ConvertShaderFileType(vertex["type"]);
    VertexShaderFile.FILE   = vertex["file"].get<std::wstring>();
    VertexShaderFile.ENTRY  = vertex["entry"].get<std::wstring>();
    VertexShaderFile.TARGET = vertex["target"].get<std::wstring>();

    JSON        pixel       = json["pixel"];

    PixelShaderFile.TYPE    = ConvertShaderFileType(pixel["type"]);
    PixelShaderFile.FILE    = pixel["file"].get<std::wstring>();
    PixelShaderFile.ENTRY   = pixel["entry"].get<std::wstring>();
    PixelShaderFile.TARGET  = pixel["target"].get<std::wstring>();

    JSON        descs       = json["descriptions"]["descriptions"];
    VertexDescriptions.Amount       = json["descriptions"]["amount"];
    VertexDescriptions.Descs    = T100NEW T100D3D12_INPUT_ELEMENT_DESC[VertexDescriptions.Amount];

    T100UINT    damount   = 0;
    for(JSON::iterator it = descs.begin(); it != descs.end(); ++it){
        JSON&   thisDesc    = it.value();
        T100D3D12_INPUT_ELEMENT_DESC& desc  = VertexDescriptions.Descs[damount++];

        desc.SemanticName           = thisDesc["name"].get<std::wstring>().c_str();
        desc.SemanticIndex          = thisDesc["index"];
        desc.Format                 = thisDesc["format"];
        desc.InputSlot              = thisDesc["slot"];
        desc.AlignedByteOffset      = thisDesc["offset"];
        desc.InputSlotClass         = thisDesc["class"];
        desc.InstanceDataStepRate   = thisDesc["rate"];
    }

    JSON        paras       = json["parameters"]["parameters"];
    ShaderParameters.Amount       = json["parameters"]["amount"];
    ShaderParameters.Parameters    = T100NEW T100ShaderParameter[ShaderParameters.Amount];

    T100UINT    pamount     = 0;
    for(JSON::iterator it = paras.begin(); it != paras.end(); ++it){
        JSON&   thisPara    = it.value();
        T100ShaderParameter& para   = ShaderParameters.Parameters[pamount++];

        para.RangeType              = thisPara["type"];
        para.DescriptorsLength      = thisPara["length"];
        para.BaseShaderRegister     = thisPara["register"];
        para.RegisterSpace          = thisPara["space"];
        para.Flags                  = thisPara["flags"];
        para.OffsetInDescriptorsFromTableStart  = thisPara["offset"];
        para.NumRanges              = thisPara["ranges"];
        para.Visibility             = thisPara["visibility"];
    }

}

T100DX12_SCENE_SPATIAL_TYPE T100Scene::ConvertSceneType(T100UINT value)
{
    switch(value){
    case 0:
        {
            return T100DX12_SCENE_RECTANGLE;
        }
        break;
    case 1:
        {
            return T100DX12_SCENE_SPHERE;
        }
        break;
    }
}

T100SHADER_FILE_TYPE T100Scene::ConvertShaderFileType(T100UINT value)
{
    switch(value){
    case 0:
        {
            return T100SHADER_FILE_NONE;
        }
        break;
    case 1:
        {
            return T100SHADER_FILE_SOURCE;
        }
        break;
    case 2:
        {
            return T100SHADER_FILE_COMPILED;
        }
        break;
    }
}
