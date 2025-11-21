#include "T1003DEditorRectangleGrid.h"

#include "entity/T100Rectangle.h"
#include "T100EntityGridAllDatas.h"
#include "T1003DEditorCallback.h"

T1003DEditorRectangleGrid::T1003DEditorRectangleGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorRectangleGrid::~T1003DEditorRectangleGrid()
{
    //dtor
}

T100VOID T1003DEditorRectangleGrid::Update(T100Entity* entityPtr)
{
    T100Rectangle*      rectanglePtr        = T100NULL;

    rectanglePtr    = dynamic_cast<T100Rectangle*>(entityPtr);

    if(!rectanglePtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateShader();


    //CreateEntity();
    //CreateShader();
    //CreateCategories();

}

T100VOID T1003DEditorRectangleGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    //OnEntityPGChanged(event);

    wxPGProperty*           property    = event.GetProperty();

    if(property){
        T100GridClientData*     data    = dynamic_cast<T100GridClientData*>(property->GetClientObject());
        if(data){
            data->Update(property);
            T1003DEditorCallback::SetDirty();
        }
    }
}

T100VOID T1003DEditorRectangleGrid::CreateShader()
{
    m_entityData.m_shader               = T100NEW wxPropertyCategory(wxT("Shader"));
    m_propertyGridPtr->Append(m_entityData.m_shader);

    m_entityData.m_shaderInherit        = T100NEW wxBoolProperty(wxT("Inherit"), wxT("inherit"), m_entityPtr->Shader.INHERIT);
    m_propertyGridPtr->Append(m_entityData.m_shaderInherit);

    T100EntityGridShaderInheritData*    shaderInheritData       = T100NEW T100EntityGridShaderInheritData(m_propertyGridPtr, m_entityPtr, m_entityData);
    m_entityData.m_shaderInherit->SetClientObject(shaderInheritData);

    shaderInheritData->CreateShader();
}
