#include "T100Scene.h"

#include "T100Triangle.h"

T100Scene::T100Scene()
{
    //ctor
}

T100Scene::~T100Scene()
{
    //dtor
}

T100BOOL T100Scene::Load()
{
    T100Triangle*       triangle        = T100NEW T100Triangle();

    entities.push_back(triangle);
}
