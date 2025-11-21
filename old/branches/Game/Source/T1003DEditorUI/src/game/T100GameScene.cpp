#include "T100GameScene.h"

#include "entity/T100Dot.h"
#include "entity/T100City.h"
#include "math/T100VectorTools.h"

T100GameScene::T100GameScene(T100DX12Renderer* renderer) :
    T100DX12Scene(renderer)
{
    //ctor
    init();
}

T100GameScene::~T100GameScene()
{
    //dtor
    uninit();
}

T100VOID T100GameScene::init()
{

}

T100VOID T100GameScene::uninit()
{

}

T100VOID T100GameScene::AppendStaticEntities()
{
    /*
    T100UINT    x   = 50;

    m_direction.SetLength(100);
    m_direction.SetPosition(x, GetHeight() - x);
    m_direction.Load(this);

    m_horizontal.SetLength(-1);
    m_horizontal.SetRenderType(T100_RENDER_2D);
    m_horizontal.SetMotionType(T100_MOTION_MOVE);
    m_horizontal.SetVisible(T100FALSE);
    m_vertical.SetLength(-1);
    m_vertical.SetRenderType(T100_RENDER_2D);
    m_vertical.SetMotionType(T100_MOTION_MOVE);
    m_vertical.SetRotation(0, 0, -T100_PIDIV2);
    m_vertical.SetVisible(T100FALSE);

    m_vertical.SetPosition(GetWidth() / 2, 0, 0);
    m_horizontal.SetPosition(0, GetHeight() / 2, 0);

    AppendStaticEntity(&m_horizontal);
    AppendStaticEntity(&m_vertical);

    T100Line*   linex = T100NEW T100Line();

    linex->SetOrigin(0, 0, 0);
    linex->SetTerminus(Width, 0, 0);

    AppendStaticEntity(linex);

    T100Line*   liney = T100NEW T100Line();

    liney->SetOrigin(0, 0, 0);
    liney->SetTerminus(0, Height, 0);

    AppendStaticEntity(liney);

    T100Line*   linez = T100NEW T100Line();

    linez->SetOrigin(0, 0, 0);
    linez->SetTerminus(0, 0, Width);

    AppendStaticEntity(linez);
    */
}

T100VOID T100GameScene::AppendDynamicsEntities()
{

}

T100VOID T100GameScene::Append(T100Entity* entity)
{
    m_current   = entity;
    m_editable  = dynamic_cast<T100Editable*>(entity);
    T100DX12Scene::Append(entity);

    if(m_editable && m_editable->IsEditable()){
        T100DX12Scene::Append(m_editable->m_selection);
    }
}

T100VOID T100GameScene::Rotation(T100Vector3& rotation)
{
    m_direction.SetRotation(rotation);
}

T100VOID T100GameScene::AppendLight(T100Light* light)
{
    m_current   = light;
    m_editable  = dynamic_cast<T100Editable*>(light);
    T100DX12Scene::AppendLight(light);

    if(m_editable && m_editable->IsEditable()){
        T100DX12Scene::Append(m_editable->m_selection);
    }
}
