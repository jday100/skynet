#include "serve/T1003DEditorEntityManager.h"

#include <wx/wx.h>
#include "entity/T100AllEntities.h"
#include "game/T100GameCallback.h"

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
    m_appendState   = T100FALSE;
    m_type          = 0;
    m_dotCount      = 0;
    m_lineCount     = 0;
    m_triangleCount = 0;
    m_planeCount    = 0;
    m_cityCount     = 0;
}

T100VOID T1003DEditorEntityManager::uninit()
{

}

T100VOID T1003DEditorEntityManager::Update(T100INT value)
{
    m_type  = value;

    if(m_appendState){
        T100GameCallback::Remove(m_entity);
        T100SAFE_DELETE m_entity;
        m_entity    = T100NULL;
    }

    switch(value){
    case T100ENTITY_DOT:
        {
            T100Dot*    dot    = T100NEW T100Dot();
            dot->SetEditable();
            m_entity    = dot;
            int     i       = ++m_dotCount;
            m_entity->Name  = wxString::Format(L"%s%u", T100Dot::Name, i);
        }
        break;
    case T100ENTITY_LINE:
        {
            T100Line*   line    = T100NEW T100Line();
            m_entity        = line;
            int     i       = ++m_lineCount;
            line->SetLength(1);
            m_entity->Name  = wxString::Format(L"%s%u", T100Line::Name, i);
        }
        break;
    case T100ENTITY_TRIANGLE:
        {
            m_entity    = T100NEW T100Triangle();
            int     i       = ++m_triangleCount;
            m_entity->Name  = wxString::Format(L"%s%u", T100Triangle::Name, i);
        }
        break;
    case T100ENTITY_PLANE:
        {
            m_entity    = T100NEW T100Plane();
            int     i       = ++m_planeCount;
            m_entity->Name  = wxString::Format(L"%s%u", T100Plane::Name, i);
        }
        break;
    case T100ENTITY_CITY:
        {
            m_entity    = T100NEW T100City();
            int     i       = ++m_cityCount;
            m_entity->Name  = wxString::Format(L"%s%u", T100City::Name, i);
        }
        break;
    }

    m_entity->SetColour(255, 255, 255, 0);
    m_entity->SetEditable(T100TRUE);
    m_appendState   = T100TRUE;
}

T100Entity* T1003DEditorEntityManager::GetCurrent()
{
    return m_entity;
}

T100Editable* T1003DEditorEntityManager::GetEditable()
{
    return dynamic_cast<T100Editable*>(m_entity);
}


T100VOID T1003DEditorEntityManager::Clear()
{
    m_appendState   = T100FALSE;
    m_entity        = T100NULL;
}
