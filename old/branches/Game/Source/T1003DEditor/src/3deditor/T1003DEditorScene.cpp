#include "T1003DEditorScene.h"

#include <iostream>
#include "dx12/DirectXMath.h"
#include "T100Matrix4.h"

#include "T100Dot.h"
#include "T100Line.h"
#include "T100City.h"
#include "T100Triangle.h"
#include "T100Rectangle.h"

using namespace DirectX;

T1003DEditorScene::T1003DEditorScene(T100DX12Renderer* dx12) :
    T100DX12Scene(dx12),
    m_direction()
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
    SetSpatialType(T100DX12_SCENE_RECTANGLE);
    SetOrigin(0, 0, 0);
    SetTerminus(1000, 1000, 1000);
}

T100VOID T1003DEditorScene::uninit()
{

}

T100VOID T1003DEditorScene::AppendStaticEntities()
{
    T100Rectangle*      rectangle       = T100NEW T100Rectangle();

    AppendDynamicsEntity(rectangle);
}

T100VOID T1003DEditorScene::AppendDynamicsEntities()
{

}

