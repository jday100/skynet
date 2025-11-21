#include "T1003DEditorCityGrid.h"

#include "entity/T100City.h"

T1003DEditorCityGrid::T1003DEditorCityGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorCityGrid::~T1003DEditorCityGrid()
{
    //dtor
}

T100VOID T1003DEditorCityGrid::Update(T100Entity* entityPtr)
{
    T100City*       cityPtr         = T100NULL;

    cityPtr     = dynamic_cast<T100City*>(entityPtr);

    if(!cityPtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateEntity();
    CreateShader();
    CreateCategories();
}

T100VOID T1003DEditorCityGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;


    if(update){

    }else{
        OnEntityPGChanged(event);
    }
}
