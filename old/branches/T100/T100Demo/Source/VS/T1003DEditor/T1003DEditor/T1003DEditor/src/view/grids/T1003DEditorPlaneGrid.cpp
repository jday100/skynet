#include "view/grids/T1003DEditorPlaneGrid.h"

#include "entity/T100Plane.h"

T1003DEditorPlaneGrid::T1003DEditorPlaneGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorPlaneGrid::~T1003DEditorPlaneGrid()
{
    //dtor
}

T100VOID T1003DEditorPlaneGrid::Update(T100Entity* entityPtr)
{
    T100Plane*      planePtr        = T100NULL;

    planePtr    = dynamic_cast<T100Plane*>(entityPtr);

    if(!planePtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateEntity();
    CreateCategories();
}

T100VOID T1003DEditorPlaneGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;


    if(update){

    }else{
        OnEntityPGChanged(event);
    }
}
