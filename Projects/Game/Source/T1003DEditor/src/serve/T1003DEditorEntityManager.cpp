#include "T1003DEditorEntityManager.h"

#include "T100Dot.h"

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
    T100Dot*        dot     = T100NEW T100Dot();

    dot->row        = 1;
    dot->column     = 1;
    dot->load();

    return dot;
}
