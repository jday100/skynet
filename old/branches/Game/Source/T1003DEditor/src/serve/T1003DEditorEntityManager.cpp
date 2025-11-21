#include "T1003DEditorEntityManager.h"

#include "T100AllEntities.h"

T1003DEditorEntityManager::T1003DEditorEntityManager()
{
    //ctor
    init();
}

T1003DEditorEntityManager::~T1003DEditorEntityManager()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorEntityManager::init()
{
    m_type  = T100ENTITY_NONE;
}

T100VOID T1003DEditorEntityManager::uninit()
{

}

T100Entity* T1003DEditorEntityManager::getCurrent()
{
    T100Entity*         entity          = T100NULL;

    switch(m_type){
    case T100ENTITY_DOT:
        {
            T100Dot*    dot     = T100NEW T100Dot();
            dot->SetEditable();

            entity  = dot;
        }
        break;
    case T100ENTITY_LINE:
        {
            entity  = T100NEW T100Line();
        }
        break;
    case T100ENTITY_TRIANGLE:
        {
            entity  = T100NEW T100Triangle();
        }
        break;
    case T100ENTITY_CITY:
        {
            entity  = T100NEW T100City();
        }
        break;
    }

    return entity;
}

T100VOID T1003DEditorEntityManager::update(T100ENTITY_TYPE type)
{
    m_type  = type;
}
