#include "T100BasicScene.h"

#include "T100Cuboid.h"

#include "T100Render.h"

T100BasicScene::T100BasicScene()
    :T100Scene()
{
    //ctor
}

T100BasicScene::~T100BasicScene()
{
    //dtor
}

T100VOID T100BasicScene::SetRender(T100Render* render)
{
    m_render    = render;
}

T100Render* T100BasicScene::GetRender()
{
    return m_render;
}

T100VOID T100BasicScene::Load()
{
    T100Cuboid*         cuboid          = T100NULL;

    cuboid  = T100NEW T100Cuboid();
    cuboid->Create(50, 50, 50);

    m_render->Append(cuboid);
}
