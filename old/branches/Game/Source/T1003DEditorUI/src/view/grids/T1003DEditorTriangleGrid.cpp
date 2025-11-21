#include "T1003DEditorTriangleGrid.h"

#include "entity/T100Triangle.h"

T1003DEditorTriangleGrid::T1003DEditorTriangleGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorTriangleGrid::~T1003DEditorTriangleGrid()
{
    //dtor
}

T100VOID T1003DEditorTriangleGrid::Update(T100Entity* entityPtr)
{
    T100Triangle*       trianglePtr     = T100NULL;

    trianglePtr     = dynamic_cast<T100Triangle*>(entityPtr);

    if(!trianglePtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateEntity();
    CreateShader();
    CreateCategories();
}

T100VOID T1003DEditorTriangleGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;


    if(update){

    }else{
        OnEntityPGChanged(event);
    }
}
