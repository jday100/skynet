#include "T100Rectangle.h"

#include "T100Unicode.h"
#include "T100DX12Studio.h"
#include "T100DX12Model.h"

T100ENTITY_TYPE         T100Rectangle::Type             = T100ENTITY_RECTANGLE;
T100WSTRING             T100Rectangle::Name             = L"Rectangle";

T100Rectangle::T100Rectangle() :
    T100Editable()
{
    //ctor
    init();
}

T100Rectangle::~T100Rectangle()
{
    //dtor
    uninit();
}

T100VOID T100Rectangle::init()
{
    T100Entity::Name    = L"Rectangle";
    T100Entity::Type    = T100ENTITY_RECTANGLE;

    Shader.INHERIT                  = T100FALSE;

    VertexShaderFile.TYPE           = T100SHADER_FILE_SOURCE;
    VertexShaderFile.FILE           = L"scene_dl_vs.hlsl";
    VertexShaderFile.ENTRY          = L"VSMain";
    VertexShaderFile.TARGET         = L"vs_5_1";

    PixelShaderFile.TYPE            = T100SHADER_FILE_SOURCE;
    PixelShaderFile.FILE            = L"scene_dl_ps.hlsl";
    PixelShaderFile.ENTRY           = L"PSMain";
    PixelShaderFile.TARGET          = L"ps_5_1";

    MeshDataFile                    = L"occcity.bin";

    m_bundle.USED                   = T100TRUE;
    m_bundle.AMOUNT.X               = 8;
    m_bundle.AMOUNT.Z               = 15;
    m_bundle.SPACING.X              = 16;
    m_bundle.SPACING.Y              = 16;
    m_bundle.SPACING.Z              = 16;
}

T100VOID T100Rectangle::uninit()
{

}

T100VOID T100Rectangle::Load(T100DX12Scene* scene)
{
    vertex  = T100NEW Vertex[36];

    vertex[0]   = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[1]   = {{1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[2]   = {{-1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[3]   = {{-1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[4]   = {{1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[5]   = {{1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    vertex[6]   = {{1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[7]   = {{1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[8]   = {{1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[9]   = {{1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[10]  = {{1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[11]  = {{1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    vertex[12]  = {{1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[13]  = {{1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[14]  = {{-1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[15]  = {{-1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[16]  = {{1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[17]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    vertex[18]  = {{-1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[19]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[20]  = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[21]  = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[22]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[23]  = {{-1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    vertex[24]  = {{-1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[25]  = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[26]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[27]  = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[28]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[29]  = {{-1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    vertex[30]  = {{-1, 1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[31]  = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[32]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[33]  = {{-1, 1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[34]  = {{-1, -1, 1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[35]  = {{-1, -1, -1}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};


    Length  = sizeof(Vertex) * 36;

    if(m_editable){
        m_selection = T100NEW T100Rectangle();
        m_selection->SetColour(255, 0, 0, 0);

        m_selection->Shader.INHERIT             = Shader.INHERIT;

        m_selection->VertexShaderFile.TYPE      = VertexShaderFile.TYPE;
        m_selection->VertexShaderFile.FILE      = VertexShaderFile.FILE;
        m_selection->VertexShaderFile.ENTRY     = VertexShaderFile.ENTRY;
        m_selection->VertexShaderFile.TARGET    = VertexShaderFile.TARGET;

        m_selection->PixelShaderFile.TYPE       = PixelShaderFile.TYPE;
        m_selection->PixelShaderFile.FILE       = PixelShaderFile.FILE;
        m_selection->PixelShaderFile.ENTRY      = PixelShaderFile.ENTRY;
        m_selection->PixelShaderFile.TARGET     = PixelShaderFile.TARGET;

        m_selection->VertexDescriptions         = VertexDescriptions;
        m_selection->ShaderParameters           = ShaderParameters;

        m_selection->Load(scene);
    }
}

T100DX12Model* T100Rectangle::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model   = T100NEW T100DX12Model();

    model->Type                 = T100DX12_MODEL_RECTANGLE;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);

    model->m_visible    = m_visible;

    model->vertex       = vertex;
    model->Length       = Length;

    studio->GetScene()->CompileShaderFile(VertexShaderFile.FILE, VertexShaderFile.ENTRY, VertexShaderFile.TARGET, model->vertexShader);
    studio->GetScene()->CompileShaderFile1(PixelShaderFile.FILE, PixelShaderFile.ENTRY, PixelShaderFile.TARGET, model->pixelShader);

    model->VertexDescriptions           = const_cast<D3D12_INPUT_ELEMENT_DESC*>((D3D12_INPUT_ELEMENT_DESC*)StandardVertexDescription);
    model->VertexDescriptionsLength     = StandardVertexDescriptionNumElements;
    model->m_numIndices = 36;

    T100WSTRING         name            = StandardVertexDescription[0].SemanticName;
    model->VertexDescriptions[0].SemanticName       = T100Unicode::to_string8(name).c_str();
    name            = StandardVertexDescription[1].SemanticName;
    model->VertexDescriptions[1].SemanticName       = T100Unicode::to_string8(name).c_str();


    model->VertexDescriptionsPtr        = &VertexDescriptions;
    model->ShaderParametersPtr          = &ShaderParameters;

    model->RenderType   = model->ConvertRenderType(m_renderType);
    model->MotionType   = model->ConvertMotionType(m_motionType);

    memcpy(&model->Bundle, &m_bundle, sizeof(T100BUNDLE));

    //test
    studio->GetScene()->LoadMeshFile(MeshDataFile, &model->pMeshData, &model->MeshDataLength);

    m_model     = model;

    if(m_editable){
        m_model->m_selection    = m_selection->Convert(studio);
        m_model->m_editable     = T100TRUE;
    }

    return model;
}

T100VOID T100Rectangle::ToJSON(JSON& json)
{
    EntityToJSON(json);
}

T100VOID T100Rectangle::FromJSON(JSON& json)
{
    EntityFromJSON(json);
}
