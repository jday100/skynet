#include "T100EditorServe.h"

#include "T100Editor.h"
#include "T100Entity.h"
#include "T100Cuboid.h"
#include "T100Sphere.h"
#include "T100ModelTypes.h"

T100EditorServe::T100EditorServe(T100Editor* editor)
    :m_editor(editor)
{
    //ctor
}

T100EditorServe::~T100EditorServe()
{
    //dtor
}

T100VOID T100EditorServe::SetEntityID(T100INT value)
{
    m_entity_id = value;
}

T100VOID T100EditorServe::SetRender(T100Render* render)
{
    m_render    = render;
}

T100VOID T100EditorServe::Create(T100INT x, T100INT y)
{
    T100Entity*     entity          = T100NULL;

    switch(m_entity_id){
    case T100MODEL_CUBOID:
        {
            entity      = T100NEW T100Cuboid();
        }
        break;
    case T100MODEL_SPHERE:
        {
            entity      = T100NEW T100Sphere();
        }
        break;
    }

    m_current   = entity;

    T100FLOAT       a, b, c;

    m_render->project(x, y, a, b, c);
    m_current->SetOrigin(a, b, c);
}

T100VOID T100EditorServe::Second()
{

}

T100VOID T100EditorServe::Finished(T100INT x, T100INT y)
{
    T100FLOAT       a, b, c;

    if(m_current){
        m_render->project(x, y, a, b, c);
        m_current->SetTerminus(a, b, c);
    }
}
