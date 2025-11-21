#include "T1003DEditorLightGrid.h"

#include "T1003DEditorCallback.h"

T1003DEditorLightGrid::T1003DEditorLightGrid(wxPropertyGrid* grid) :
    T1003DEditorGridBase(grid)
{
    //ctor
}

T1003DEditorLightGrid::~T1003DEditorLightGrid()
{
    //dtor
}

T100VOID T1003DEditorLightGrid::Update(T100Light* light)
{
    m_lightPtr  = light;

    m_propertyGridPtr->Clear();

    T100Entity*     entity;

    entity  = light;

    m_name  = T100NEW wxStringProperty(wxT("Name"), wxT("name"), entity->Name);

    m_propertyGridPtr->Append(m_name);

    static const wxChar* enumTypeLabels[] = {
        wxT("Directional"),
        wxT("Point"),
        wxT("Spot"),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1, 2
    };

    m_type   = T100NEW wxEnumProperty(wxT("Type"), wxT("type"), enumTypeLabels, enumTypeValues, m_lightPtr->LightType);

    m_propertyGridPtr->Append(m_type);

    CreateType();
}

T100VOID T1003DEditorLightGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;
    T100WSTRING     name;

    name    = event.GetPropertyName().ToStdWstring();

    if(name == L"type"){
        T100UINT    value   = event.GetPropertyValue().GetInteger();
        m_lightPtr->LightType    = ConvertType(value);
        Update(m_lightPtr);
        update  = T100TRUE;
    }

    T100FLOAT       positionx;
    T100FLOAT       positiony;
    T100FLOAT       positionz;

    if(name == L"positionx" ||
       name == L"positiony" ||
       name == L"positionz"){

        positionx   = m_positionX->GetValue().GetDouble();
        positiony   = m_positionY->GetValue().GetDouble();
        positionz   = m_positionZ->GetValue().GetDouble();

        m_lightPtr->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }

    if(update){
        T1003DEditorCallback::SetDirty();
    }
}

T100_LIGHT_TYPE T1003DEditorLightGrid::ConvertType(T100UINT value)
{
    switch(value){
    case 0:
        {
            return T100_LIGHT_DIRECTIONAL;
        }
        break;
    case 1:
        {
            return T100_LIGHT_POINT;
        }
        break;
    case 2:
        {
            return T100_LIGHT_SPOT;
        }
        break;
    }
    return T100_LIGHT_POINT;
}

T100VOID T1003DEditorLightGrid::CreateType()
{
    switch(m_lightPtr->LightType){
    case T100_LIGHT_DIRECTIONAL:
        {
            wxPropertyCategory*     category    = T100NEW wxPropertyCategory(wxT("Direction"));
            T100Vector3             direction   = m_lightPtr->GetDirection();

            m_directionX    = T100NEW wxFloatProperty(wxT("X"), wxT("directionx"), direction.X);
            m_directionY    = T100NEW wxFloatProperty(wxT("Y"), wxT("directiony"), direction.Y);
            m_directionZ    = T100NEW wxFloatProperty(wxT("Z"), wxT("directionz"), direction.Z);

            category->AppendChild(m_directionX);
            category->AppendChild(m_directionY);
            category->AppendChild(m_directionZ);

            m_propertyGridPtr->Append(category);

        }
        break;
    case T100_LIGHT_POINT:
        {
            wxPropertyCategory*     category    = T100NEW wxPropertyCategory(wxT("Position"));
            T100Vector3             position    = m_lightPtr->GetPosition();

            m_positionX     = T100NEW wxFloatProperty(wxT("X"), wxT("positionx"), position.X);
            m_positionY     = T100NEW wxFloatProperty(wxT("Y"), wxT("positiony"), position.Y);
            m_positionZ     = T100NEW wxFloatProperty(wxT("Z"), wxT("positionz"), position.Z);

            category->AppendChild(m_positionX);
            category->AppendChild(m_positionY);
            category->AppendChild(m_positionZ);

            m_propertyGridPtr->Append(category);
        }
        break;
    case T100_LIGHT_SPOT:
        {
            wxPropertyCategory*     positionCategory    = T100NEW wxPropertyCategory(wxT("Position"));
            T100Vector3             position    = m_lightPtr->GetPosition();

            m_positionX     = T100NEW wxFloatProperty(wxT("X"), wxT("positionx"), position.X);
            m_positionY     = T100NEW wxFloatProperty(wxT("Y"), wxT("positiony"), position.Y);
            m_positionZ     = T100NEW wxFloatProperty(wxT("Z"), wxT("positionz"), position.Z);

            positionCategory->AppendChild(m_positionX);
            positionCategory->AppendChild(m_positionY);
            positionCategory->AppendChild(m_positionZ);

            m_propertyGridPtr->Append(positionCategory);

            wxPropertyCategory*     directionCategory    = T100NEW wxPropertyCategory(wxT("Direction"));
            T100Vector3             direction   = m_lightPtr->GetDirection();

            m_directionX    = T100NEW wxFloatProperty(wxT("X"), wxT("directionx"), direction.X);
            m_directionY    = T100NEW wxFloatProperty(wxT("Y"), wxT("directiony"), direction.Y);
            m_directionZ    = T100NEW wxFloatProperty(wxT("Z"), wxT("directionz"), direction.Z);

            directionCategory->AppendChild(m_directionX);
            directionCategory->AppendChild(m_directionY);
            directionCategory->AppendChild(m_directionZ);

            m_propertyGridPtr->Append(directionCategory);

        }
        break;
    }
}
