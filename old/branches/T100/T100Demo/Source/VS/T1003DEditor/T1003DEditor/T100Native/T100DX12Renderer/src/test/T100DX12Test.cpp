#include "test/T100DX12Test.h"

#include "link/T1003DCamera.h"
#include "entity/T100AllEntities.h"

T100DX12Test::T100DX12Test()
{
    //ctor
}

T100DX12Test::~T100DX12Test()
{
    //dtor
}

T100VOID T100DX12Test::Create(T1003DWindowHandle handle, T100UINT width, T100UINT height)
{
    m_renderer.Create(handle, width, height);
}

T100VOID T100DX12Test::Start()
{
    City();
    m_renderer.Start();
}

T100VOID T100DX12Test::Stop()
{
    m_renderer.Stop();
}

T100VOID T100DX12Test::Update()
{
    m_renderer.Update();
}

T100VOID T100DX12Test::Render()
{
    m_renderer.Render();
}

T100VOID T100DX12Test::init()
{
    T100Line*   line = T100NEW T100Line();

    line->VertexShaderFile.REALPATH = L".\\resources\\entity\\line.hlsl";
    line->PixelShaderFile.REALPATH  = L".\\resources\\entity\\line.hlsl";
    line->SetLength(10);
    line->Load();

    //line->SetRenderType(T1003D_RENDER_SCREEN);
    //line->SetMotionType(T1003D_MOTION_STILL);
    //line->SetPosition(0, 10, 0);

    //line->SetVisible(T100FALSE);

    m_renderer.Append(line);



    T1003DCamera*   camera  = T100NEW T1003DCamera();

    camera->SetPosition(0, 5, -30);
    camera->SetLookAt(0, 0, 1);
    camera->SetUp(0, 1, 0);

    camera->SetAspectRatio(m_renderer.GetAspectRatio());

    m_renderer.SetCameraPtr(camera);

    T100Vector3f    source;
    T100Vector3f    result;
    T100FLOAT       x   = 0;
    T100FLOAT       y   = 0;
    T100FLOAT       width;
    T100FLOAT       height;
    T100FLOAT       minz;
    T100FLOAT       maxz;
    T100Matrix4f    project;
    T100Matrix4f    view;
    T100Matrix4f    world;

    width   = m_renderer.GetWidth();
    height  = m_renderer.GetHeight();

    minz    = camera->GetNearPlane();
    maxz    = camera->GetFarPlane();

    camera->GetProjectionMatrix(project);
    camera->GetViewMatrix(view);
    camera->GetTranslation(world);

    camera->Unproject(source, x, y, width, height, minz, maxz, project, view, world, result);


}

T100VOID T100DX12Test::City()
{
    T1003DCamera*   camera  = T100NEW T1003DCamera();

    camera->SetPosition(0, 5, -30);
    camera->SetAspectRatio(m_renderer.GetAspectRatio());

    m_renderer.SetCameraPtr(camera);

    T100City*   city    = T100NEW T100City();

    city->VertexShaderFile.TYPE         = T100SHADER_FILE_COMPILED;
    city->VertexShaderFile.REALPATH     = L"./resources/entity/shader_mesh_simple_vert.cso";

    city->PixelShaderFile1.TYPE         = T100SHADER_FILE_COMPILED;
    city->PixelShaderFile1.REALPATH     = L"./resources/entity/shader_mesh_simple_pixel.cso";

    city->PixelShaderFile2.TYPE         = T100SHADER_FILE_COMPILED;
    city->PixelShaderFile2.REALPATH     = L"./resources/entity/shader_mesh_alt_pixel.cso";

    city->MeshDataFile.REALPATH         = L"./resources/entity/occcity.bin";

    city->Load();

    m_renderer.Append(city);

}
