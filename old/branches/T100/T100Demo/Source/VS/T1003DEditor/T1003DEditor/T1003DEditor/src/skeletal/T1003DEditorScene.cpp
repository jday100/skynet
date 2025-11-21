#include "skeletal/T1003DEditorScene.h"
#include "entity/T100AllEntities.h"

#include "T100MathTools.h"
#include "T100Game.h"

T1003DEditorScene::T1003DEditorScene(T100Game* game) :
    T100GameScene(game),
    m_direction(),
    m_horizontal(),
    m_vertical(),
    m_x(),
    m_y(),
    m_z()
{
    //ctor
    init();
}

T1003DEditorScene::~T1003DEditorScene()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorScene::init()
{
    //m_direction.SetColour(255, 255, 255);
    m_direction.SetLength(50);

    m_horizontal.SetLength(-1);
    m_horizontal.SetRenderType(T1003D_RENDER_SCREEN);
    m_horizontal.SetVisible(T100FALSE);

    m_vertical.SetLength(-1);
    m_vertical.SetRenderType(T1003D_RENDER_SCREEN);
    m_vertical.SetRotation(0, 0, -90);
    m_vertical.SetVisible(T100FALSE);

    m_x.SetLength(-1);
    m_y.SetLength(-1);
    m_z.SetLength(-1);

    m_y.SetRotation(0, 0, 90);
    m_z.SetRotation(0, -90, 0);
}

T100VOID T1003DEditorScene::uninit()
{

}

T100VOID T1003DEditorScene::Create()
{

    T100UINT    width;
    T100UINT    height;

    width   = m_rendererPtr->GetWidth();
    height  = m_rendererPtr->GetHeight();

    m_direction.SetPosition(20, height - 20, 0);

    m_direction.Load(this);
    AppendStaticMesh(&m_horizontal);
    AppendStaticMesh(&m_vertical);

    m_cameraPtr         = T100NEW T1003DCamera();

    m_cameraPtr->SetPosition(15, 8, -22);
    m_cameraPtr->SetAspectRatio(m_rendererPtr->GetAspectRatio());

    m_gamePtr->SetCameraPtr(m_cameraPtr);

    AppendStaticMesh(&m_x);
    AppendStaticMesh(&m_y);
    AppendStaticMesh(&m_z);
}

T100VOID T1003DEditorScene::Destroy()
{

}

T100VOID T1003DEditorScene::Reset()
{
    m_cameraPtr->SetPosition(15, 8, -22);
}

T100VOID T1003DEditorScene::AppendStaticMeshes()
{

}

T100VOID T1003DEditorScene::AppendDynamicsMeshes()
{

}
