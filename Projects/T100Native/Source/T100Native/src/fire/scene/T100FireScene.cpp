#include "T100FireScene.h"
#include "T100Sky.h"
#include "T100Land.h"

#include "T100Cuboid.h"
#include "T100Sphere.h"

#include "T100Light.h"
#include "T100Camera.h"

#include "T100Render.h"

T100FireScene::T100FireScene()
    :T100Scene()
{
    //ctor
}

T100FireScene::~T100FireScene()
{
    //dtor
}

T100VOID T100FireScene::SetRender(T100Render* render)
{
    m_render    = render;
}

T100Render* T100FireScene::GetRender()
{
    return m_render;
}

T100VOID T100FireScene::Load()
{
    T100Sky*            sky         = T100NULL;
    T100Land*           land        = T100NULL;

    T100Cuboid*         cuboid      = T100NULL;
    T100Sphere*         sphere      = T100NULL;

    T100Light*          light       = T100NULL;
    T100Camera*         camera      = T100NULL;

    sky     = T100NEW T100Sky();
    land    = T100NEW T100Land();

    cuboid  = T100NEW T100Cuboid();
    sphere  = T100NEW T100Sphere();

    light   = T100NEW T100Light();
    camera  = T100NEW T100Camera();

    m_render->Append(sky);
    m_render->Append(land);
    m_render->Append(cuboid);
    m_render->Append(sphere);

    m_render->AppendLight(light);
    m_render->AppendCamera(camera);
}
