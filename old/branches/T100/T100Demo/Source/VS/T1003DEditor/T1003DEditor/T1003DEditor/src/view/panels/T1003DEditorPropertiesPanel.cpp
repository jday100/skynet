#include "view/panels/T1003DEditorPropertiesPanel.h"

#include <wx/sizer.h>
#include "entity/T100AllEntities.h"
#include "view/grids/T1003DEditorAllGrids.h"
#include "skeletal/T1003DEditorCallback.h"

BEGIN_EVENT_TABLE(T1003DEditorPropertiesPanel,wxPanel)

END_EVENT_TABLE()

T1003DEditorPropertiesPanel::T1003DEditorPropertiesPanel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name) :
    wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
    init();
}

T1003DEditorPropertiesPanel::~T1003DEditorPropertiesPanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorPropertiesPanel::init()
{
    m_sizer     = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_propertyGrid      = T100NEW wxPropertyGrid(this);
    m_sizer->Add(m_propertyGrid, 1, wxALL | wxEXPAND, 5);
    SetSizer(m_sizer);
    m_sizer->Fit(this);
    m_sizer->SetSizeHints(this);

    m_propertyGrid->Connect(wxEVT_PG_CHANGED, (wxObjectEventFunction)&T1003DEditorPropertiesPanel::OnPGChanged, T100NULL, this);

}

T100VOID T1003DEditorPropertiesPanel::uninit()
{

}

T100VOID T1003DEditorPropertiesPanel::Clear()
{
    m_propertyGrid->Clear();
}

T100VOID T1003DEditorPropertiesPanel::Update(T100INT value, T100Entity* entity)
{
    switch(value){
    case T100ENTITY_DOT:
        {
            loadDotGrid(entity);
        }
        break;
    case T100ENTITY_LINE:
        {
            loadLineGrid(entity);
        }
        break;
    case T100ENTITY_TRIANGLE:
        {
            loadTriangleGrid(entity);
        }
        break;
    case T100ENTITY_PLANE:
        {
            loadPlaneGrid(entity);
        }
        break;
    case T100ENTITY_CITY:
        {
            loadCityGrid(entity);
        }
        break;
    }
}

T100VOID T1003DEditorPropertiesPanel::Update(T1003DCamera* camera)
{
    loadCameraGrid(camera);
}

T100VOID T1003DEditorPropertiesPanel::Update(T1003DLight* light)
{
    loadLightGrid(light);
}

T100VOID T1003DEditorPropertiesPanel::loadDotGrid(T100Entity* entity)
{
    T100Dot*        dotPtr      = T100NULL;

    dotPtr  = dynamic_cast<T100Dot*>(entity);

    if(dotPtr){
        m_entityGridPtr     = T100NEW T1003DEditorDotGrid(m_propertyGrid);

        m_entityGridPtr->Update(dotPtr);
    }
}

T100VOID T1003DEditorPropertiesPanel::loadLineGrid(T100Entity* entity)
{
    T100Line*       linePtr     = T100NULL;

    linePtr = dynamic_cast<T100Line*>(entity);

    if(linePtr){
        m_entityGridPtr     = T100NEW T1003DEditorLineGrid(m_propertyGrid);

        m_entityGridPtr->Update(linePtr);
    }
}

T100VOID T1003DEditorPropertiesPanel::loadTriangleGrid(T100Entity* entity)
{
    T100Triangle*       trianglePtr     = T100NULL;

    trianglePtr     = dynamic_cast<T100Triangle*>(entity);

    if(trianglePtr){
        m_entityGridPtr     = T100NEW T1003DEditorTriangleGrid(m_propertyGrid);

        m_entityGridPtr->Update(trianglePtr);
    }
}

T100VOID T1003DEditorPropertiesPanel::loadPlaneGrid(T100Entity* entity)
{
    T100Plane*      plane       = T100NULL;

    plane   = dynamic_cast<T100Plane*>(entity);

    if(plane){
        m_entityGridPtr = T100NEW T1003DEditorPlaneGrid(m_propertyGrid);

        m_entityGridPtr->Update(plane);
    }
}

T100VOID T1003DEditorPropertiesPanel::loadCityGrid(T100Entity* entity)
{
    T100City*       cityPtr     = T100NULL;

    cityPtr = dynamic_cast<T100City*>(entity);

    if(cityPtr){
        m_entityGridPtr     = T100NEW T1003DEditorCityGrid(m_propertyGrid);

        m_entityGridPtr->Update(cityPtr);
    }
}

T100VOID T1003DEditorPropertiesPanel::loadCameraGrid(T1003DCamera* camera)
{
}


T100VOID T1003DEditorPropertiesPanel::loadLightGrid(T1003DLight* light)
{

}

void T1003DEditorPropertiesPanel::OnPGChanged(wxPropertyGridEvent& event)
{
    m_entityGridPtr->OnPGChanged(event);


    /*
    T100BOOL        update      = T100FALSE;
    T100WSTRING     name;

    name    = event.GetPropertyName().ToStdWstring();

    T100FLOAT   positionx;
    T100FLOAT   positiony;
    T100FLOAT   positionz;

    if(name == L"positionx"){
        positionx   = event.GetPropertyValue().GetDouble();
        positiony   = m_entity->GetPosition().Y;
        positionz   = m_entity->GetPosition().Z;

        m_entity->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }else if(name == L"positiony"){
        positionx   = m_entity->GetPosition().X;
        positiony   = event.GetPropertyValue().GetDouble();
        positionz   = m_entity->GetPosition().Z;

        m_entity->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }else if(name == L"positionz"){
        positionx   = m_entity->GetPosition().X;
        positiony   = m_entity->GetPosition().Y;
        positionz   = event.GetPropertyValue().GetDouble();

        m_entity->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }

    if(name == L"bundle"){
        SetupBundle(event.GetPropertyValue().GetBool());
        update  = T100TRUE;
    }

    if(name == L"amountx"){
        T100BOOL    flag    = m_entity->IsBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = {value, m_bundleAmountY.GetValue().GetInteger(), m_bundleAmountZ.GetValue().GetInteger()};

        m_entity->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entity);
            update  = T100TRUE;
        }
    }

    if(name == L"amounty"){
        T100BOOL    flag    = m_entity->IsBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = {m_bundleAmountX.GetValue().GetInteger(), value, m_bundleAmountZ.GetValue().GetInteger()};

        m_entity->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entity);
            update  = T100TRUE;
        }
    }

    if(name == L"amountz"){
        T100BOOL    flag    = m_entity->IsBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = {m_bundleAmountX.GetValue().GetInteger(), m_bundleAmountY.GetValue().GetInteger(), value};

        m_entity->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entity);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingx"){
        T100BOOL    flag    = m_entity->IsBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3f    result;

        result  = {value, m_bundleSpacingY.GetValue().GetDouble(), m_bundleSpacingZ.GetValue().GetDouble()};

        m_entity->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entity);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingy"){
        T100BOOL    flag    = m_entity->IsBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3f    result;

        result  = {m_bundleSpacingX.GetValue().GetDouble(), value, m_bundleSpacingZ.GetValue().GetDouble()};

        m_entity->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entity);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingz"){
        T100BOOL    flag    = m_entity->IsBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3f    result;

        result  = {m_bundleSpacingX.GetValue().GetDouble(), m_bundleSpacingY.GetValue().GetDouble(), value};

        m_entity->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entity);
            update  = T100TRUE;
        }
    }

    if(update){
        T1003DEditorCallback::SetDirty();
    }

    */
}
