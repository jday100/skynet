#include "T1003DEditorEntityManager.h"

#include "T100Triangle.h"
#include "T100City.h"

T1003DEditorEntityManager::T1003DEditorEntityManager()
{
    //ctor
}

T1003DEditorEntityManager::~T1003DEditorEntityManager()
{
    //dtor
}

T100Entity* T1003DEditorEntityManager::getCurrent()
{
    T100Entity*         entity          = T100NULL;

    entity  = T100NEW T100City();

    return entity;
}
