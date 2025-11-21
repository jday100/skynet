#include "view/grids/T1003DEditorLineGrid.h"

#include "entity/T100Line.h"

T1003DEditorLineGrid::T1003DEditorLineGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorLineGrid::~T1003DEditorLineGrid()
{
    //dtor
}

T100VOID T1003DEditorLineGrid::Update(T100Entity* entityPtr)
{
    T100Line*       linePtr         = T100NULL;

    linePtr     = dynamic_cast<T100Line*>(entityPtr);

    if(!linePtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();

    m_lengthPtr     = T100NEW wxFloatProperty(wxT("Length"), wxT("length"), linePtr->GetLength());

    m_propertyGridPtr->Append(m_lengthPtr);

    CreateEntity();

    m_terminusPtr   = T100NEW wxPropertyCategory(wxT("Terminus"));

    T100Vector3f    terminus    = linePtr->GetTerminus();

    m_terminusXPtr  = T100NEW wxFloatProperty(wxT("X"), wxT("terminusx"), terminus.X);
    m_terminusYPtr  = T100NEW wxFloatProperty(wxT("Y"), wxT("terminusy"), terminus.Y);
    m_terminusZPtr  = T100NEW wxFloatProperty(wxT("Z"), wxT("terminusz"), terminus.Z);

    m_terminusPtr->AppendChild(m_terminusXPtr);
    m_terminusPtr->AppendChild(m_terminusYPtr);
    m_terminusPtr->AppendChild(m_terminusZPtr);

    m_propertyGridPtr->Append(m_terminusPtr);

    CreateCategories();
}

void T1003DEditorLineGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;


    if(update){

    }else{
        OnEntityPGChanged(event);
    }
}
