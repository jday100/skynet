#include "view/grids/T1003DEditorDotGrid.h"

#include "entity/T100Dot.h"

T1003DEditorDotGrid::T1003DEditorDotGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorDotGrid::~T1003DEditorDotGrid()
{
    //dtor
}

T100VOID T1003DEditorDotGrid::Update(T100Entity* entityPtr)
{
    T100Dot*        dotPtr          = T100NULL;

    dotPtr      = dynamic_cast<T100Dot*>(entityPtr);

    if(!dotPtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateEntity();
    CreateCategories();
}

T100VOID T1003DEditorDotGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    OnEntityPGChanged(event);
}
