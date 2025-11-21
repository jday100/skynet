#include "T1003DEditorEntityManager.h"

#include <wx/wx.h>
#include "entity/T100AllEntities.h"

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
    m_type              = 0;
    m_dotCount          = 0;
    m_lineCount         = 0;
    m_triangleCount     = 0;
    m_planeCount        = 0;
    m_cityCount         = 0;
    m_meshCount         = 0;
    m_sphereCount       = 0;
    m_rectangleCount    = 0;
}

T100VOID T1003DEditorEntityManager::uninit()
{

}

T100VOID T1003DEditorEntityManager::Update(T100INT value)
{
    m_type  = value;

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
            T100Line* line  = T100NEW T100Line();
            line->SetLength(1);
            m_entity        = line;
            int     i       = ++m_lineCount;
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
    case T100ENTITY_MESH:
        {
            T100Mesh*   mesh    = T100NEW T100Mesh();
            m_entity        = mesh;
            int     i       = ++m_meshCount;
            mesh->Name      = wxString::Format(L"%s%u", T100Mesh::Name, i);
        }
        break;
    case T100ENTITY_SPHERE:
        {
            T100Sphere*    sphere    = T100NEW T100Sphere();
            sphere->SetEditable();
            m_entity    = sphere;
            int     i       = ++m_sphereCount;
            m_entity->Name  = wxString::Format(L"%s%u", T100Sphere::Name, i);
        }
        break;
    case T100ENTITY_RECTANGLE:
        {
            T100Rectangle*  rectangle   = T100NEW T100Rectangle();
            rectangle->SetEditable();
            m_entity    = rectangle;
            int     i       = ++m_rectangleCount;
            m_entity->Name  = wxString::Format(L"%s%u", T100Rectangle::Name, i);
        }
        break;
    }

    //m_entity->SetColour(255, 0, 0, 0);
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
    T100SAFE_DELETE m_entity;
}
