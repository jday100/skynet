#include "T1003DEditorSphereGrid.h"

#include "entity/T100Sphere.h"

T1003DEditorSphereGrid::T1003DEditorSphereGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorSphereGrid::~T1003DEditorSphereGrid()
{
    //dtor
}

T100VOID T1003DEditorSphereGrid::Update(T100Entity* entityPtr)
{
    T100Sphere*        spherePtr          = T100NULL;

    spherePtr      = dynamic_cast<T100Sphere*>(entityPtr);

    if(!spherePtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateEntity();
    CreateShader();
    CreateCategories();
}

T100VOID T1003DEditorSphereGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    OnEntityPGChanged(event);
}
