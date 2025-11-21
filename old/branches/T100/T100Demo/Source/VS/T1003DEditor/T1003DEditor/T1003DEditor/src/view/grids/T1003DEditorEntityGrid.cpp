#include "view/grids/T1003DEditorEntityGrid.h"

#include "skeletal/T1003DEditorCallback.h"

T1003DEditorEntityGrid::T1003DEditorEntityGrid(wxPropertyGrid* grid) :
    m_propertyGridPtr(grid)
{
    //ctor
}

T1003DEditorEntityGrid::~T1003DEditorEntityGrid()
{
    //dtor
}

T100VOID T1003DEditorEntityGrid::CreateName()
{
    m_namePtr       = T100NEW wxStringProperty(wxT("Name"), wxT("name"), m_entityPtr->Name);

    m_propertyGridPtr->Append(m_namePtr);
}

T100VOID T1003DEditorEntityGrid::CreateEntity()
{
    T100Vector4u&   value   = m_entityPtr->GetColour();
    wxColour        colour(value.RED, value.GREEN, value.BLUE, value.ALPHA);
    m_colourPtr     = T100NEW wxColourProperty(wxT("Colour"), wxT("colour"), colour);

    m_propertyGridPtr->Append(m_colourPtr);

    m_shaderFilePtr = T100NEW wxFileProperty(wxT("ShaderFile"), wxT("shaderfile"), m_entityPtr->VertexShaderFile.FILE);

    m_propertyGridPtr->Append(m_shaderFilePtr);

    m_visiblePtr    = T100NEW wxBoolProperty(wxT("Visible"), wxT("visible"), m_entityPtr->IsVisible());

    m_propertyGridPtr->Append(m_visiblePtr);

    m_bundlePtr    = T100NEW wxBoolProperty(wxT("Bundle"), wxT("bundle"), m_entityPtr->IsBundle());

    m_propertyGridPtr->Append(m_bundlePtr);
}


T100VOID T1003DEditorEntityGrid::CreateCategories()
{
    m_positionPtr   = T100NEW wxPropertyCategory(wxT("Position"));

    T100Vector3f&   position    = m_entityPtr->GetPosition();

    m_positionXPtr  = T100NEW wxFloatProperty(wxT("X"), wxT("positionx"), position.X);
    m_positionYPtr  = T100NEW wxFloatProperty(wxT("Y"), wxT("positiony"), position.Y);
    m_positionZPtr  = T100NEW wxFloatProperty(wxT("Z"), wxT("positionz"), position.Z);

    m_positionPtr->AddChild(m_positionXPtr);
    m_positionPtr->AddChild(m_positionYPtr);
    m_positionPtr->AddChild(m_positionZPtr);

    m_propertyGridPtr->Append(m_positionPtr);

    m_rotationPtr   = T100NEW wxPropertyCategory(wxT("Rotation"));

    T100Vector3f&   rotation    = m_entityPtr->GetRotation();

    m_rotationXPtr  = T100NEW wxFloatProperty(wxT("X"), wxT("rotationx"), rotation.X);
    m_rotationYPtr  = T100NEW wxFloatProperty(wxT("Y"), wxT("rotationy"), rotation.Y);
    m_rotationZPtr  = T100NEW wxFloatProperty(wxT("Z"), wxT("rotationz"), rotation.Z);

    m_rotationPtr->AddChild(m_rotationXPtr);
    m_rotationPtr->AddChild(m_rotationYPtr);
    m_rotationPtr->AddChild(m_rotationZPtr);

    m_propertyGridPtr->Append(m_rotationPtr);

    m_scalingPtr    = T100NEW wxPropertyCategory(wxT("Scaling"));

    T100Vector3f&   scaling     = m_entityPtr->GetScaling();

    m_scalingXPtr   = T100NEW wxFloatProperty(wxT("X"), wxT("scalingx"), scaling.X);
    m_scalingYPtr   = T100NEW wxFloatProperty(wxT("Y"), wxT("scalingy"), scaling.Y);
    m_scalingZPtr   = T100NEW wxFloatProperty(wxT("Z"), wxT("scalingz"), scaling.Z);

    m_scalingPtr->AddChild(m_scalingXPtr);
    m_scalingPtr->AddChild(m_scalingYPtr);
    m_scalingPtr->AddChild(m_scalingZPtr);

    m_propertyGridPtr->Append(m_scalingPtr);

    CreateBundle();
}


T100VOID T1003DEditorEntityGrid::OnEntityPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;
    T100WSTRING     name;

    name    = event.GetPropertyName().ToStdWstring();

    T100FLOAT   positionx;
    T100FLOAT   positiony;
    T100FLOAT   positionz;

    if(name == L"positionx"){
        positionx   = event.GetPropertyValue().GetDouble();
        positiony   = m_entityPtr->GetPosition().Y;
        positionz   = m_entityPtr->GetPosition().Z;

        m_entityPtr->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }else if(name == L"positiony"){
        positionx   = m_entityPtr->GetPosition().X;
        positiony   = event.GetPropertyValue().GetDouble();
        positionz   = m_entityPtr->GetPosition().Z;

        m_entityPtr->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }else if(name == L"positionz"){
        positionx   = m_entityPtr->GetPosition().X;
        positiony   = m_entityPtr->GetPosition().Y;
        positionz   = event.GetPropertyValue().GetDouble();

        m_entityPtr->SetPosition(positionx, positiony, positionz);
        update  = T100TRUE;
    }

    T100FLOAT   rotationx;
    T100FLOAT   rotationy;
    T100FLOAT   rotationz;

    if(name == L"rotationx"){
        rotationx   = event.GetPropertyValue().GetDouble();
        rotationy   = m_entityPtr->GetRotation().Y;
        rotationz   = m_entityPtr->GetRotation().Z;

        m_entityPtr->SetRotation(rotationx, rotationy, rotationz);
        update  = T100TRUE;
    }else if(name == L"rotationy"){
        rotationx   = m_entityPtr->GetRotation().X;
        rotationy   = event.GetPropertyValue().GetDouble();
        rotationz   = m_entityPtr->GetRotation().Z;

        m_entityPtr->SetRotation(rotationx, rotationy, rotationz);
        update  = T100TRUE;
    }else if(name == L"rotationz"){
        rotationx   = m_entityPtr->GetRotation().X;
        rotationy   = m_entityPtr->GetRotation().Y;
        rotationz   = event.GetPropertyValue().GetDouble();

        m_entityPtr->SetRotation(rotationx, rotationy, rotationz);
        update  = T100TRUE;
    }

    T100FLOAT   scalingx;
    T100FLOAT   scalingy;
    T100FLOAT   scalingz;

    if(name == L"scalingx"){
        scalingx    = event.GetPropertyValue().GetDouble();
        scalingy    = m_entityPtr->GetScaling().Y;
        scalingz    = m_entityPtr->GetScaling().Z;

        m_entityPtr->SetScaling(scalingx, scalingy, scalingz);
        update  = T100TRUE;
    }else if(name == L"scalingy"){
        scalingx    = m_entityPtr->GetScaling().X;
        scalingy    = event.GetPropertyValue().GetDouble();
        scalingz    = m_entityPtr->GetScaling().Z;

        m_entityPtr->SetScaling(scalingx, scalingy, scalingz);
        update  = T100TRUE;
    }else if(name == L"scalingz"){
        scalingx    = m_entityPtr->GetScaling().X;
        scalingy    = m_entityPtr->GetScaling().Y;
        scalingz    = event.GetPropertyValue().GetDouble();

        m_entityPtr->SetScaling(rotationx, scalingy, scalingz);
        update  = T100TRUE;
    }

    if(name == L"bundle"){
        SetupBundle(event.GetPropertyValue().GetBool());
        update  = T100TRUE;
    }

    if(name == L"amountx"){
        T100BOOL    flag    = m_entityPtr->IsBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = {value, m_amountYPtr->GetValue().GetInteger(), m_amountZPtr->GetValue().GetInteger()};

        m_entityPtr->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"amounty"){
        T100BOOL    flag    = m_entityPtr->IsBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = {m_amountXPtr->GetValue().GetInteger(), value, m_amountZPtr->GetValue().GetInteger()};

        m_entityPtr->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"amountz"){
        T100BOOL    flag    = m_entityPtr->IsBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = { static_cast<T100UINT>(m_amountXPtr->GetValue().GetInteger()), static_cast<T100UINT>(m_amountYPtr->GetValue().GetInteger()), value};

        m_entityPtr->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingx"){
        T100BOOL    flag    = m_entityPtr->IsBundle();
        T100FLOAT   value   = static_cast<float>(event.GetValue().GetDouble());

        T100Vector3f    result;

        result  = { static_cast<float>(value, m_spacingYPtr->GetValue().GetDouble()), static_cast<float>(m_spacingZPtr->GetValue().GetDouble())};

        m_entityPtr->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingy"){
        T100BOOL    flag    = m_entityPtr->IsBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3f    result;

        result  = { static_cast<float>(m_spacingXPtr->GetValue().GetDouble()), value, static_cast<float>(m_spacingZPtr->GetValue().GetDouble())};

        m_entityPtr->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingz"){
        T100BOOL    flag    = m_entityPtr->IsBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3f    result;

        result  = { static_cast<float>(m_spacingXPtr->GetValue().GetDouble()), static_cast<float>(m_spacingYPtr->GetValue().GetDouble()), value};

        m_entityPtr->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(update){
        T1003DEditorCallback::SetDirty();
    }

}

T100VOID T1003DEditorEntityGrid::SetupBundle(T100BOOL flag)
{
    if(flag){
        T100Vector3u        result;
        T100UINT            x;
        T100UINT            y;
        T100UINT            z;

        x   = m_amountXPtr->GetValue().GetInteger();
        y   = m_amountYPtr->GetValue().GetInteger();
        z   = m_amountZPtr->GetValue().GetInteger();

        x   = x == 0 ? 1 : x;
        y   = y == 0 ? 1 : y;
        z   = z == 0 ? 1 : z;

        m_amountXPtr->SetValueFromInt(x);
        m_amountYPtr->SetValueFromInt(y);
        m_amountZPtr->SetValueFromInt(z);

        result  = {x, y, z};

        m_entityPtr->SetBundleAmount(result);
    }

    T1003DEditorCallback::SetBundle(flag, m_entityPtr);
}

T100VOID T1003DEditorEntityGrid::CreateBundle()
{
    m_categoryPtr   = T100NEW wxPropertyCategory(wxT("Bundle"));
    m_amountPtr     = T100NEW wxPropertyCategory(wxT("Amount"));
    m_spacingPtr    = T100NEW wxPropertyCategory(wxT("Spacing"));

    T100Vector3u    amount  = m_entityPtr->GetBundleAmount();

    m_amountXPtr    = T100NEW wxIntProperty(wxT("X"), wxT("amountx"), amount.X);
    m_amountYPtr    = T100NEW wxIntProperty(wxT("Y"), wxT("amounty"), amount.Y);
    m_amountZPtr    = T100NEW wxIntProperty(wxT("Z"), wxT("amountz"), amount.Z);

    m_amountPtr->AppendChild(m_amountXPtr);
    m_amountPtr->AppendChild(m_amountYPtr);
    m_amountPtr->AppendChild(m_amountZPtr);

    T100Vector3f    spacing = m_entityPtr->GetBundleSpacing();

    m_spacingXPtr   = T100NEW wxFloatProperty(wxT("X"), wxT("spacingx"), spacing.X);
    m_spacingYPtr   = T100NEW wxFloatProperty(wxT("Y"), wxT("spacingy"), spacing.Y);
    m_spacingZPtr   = T100NEW wxFloatProperty(wxT("Z"), wxT("spacingz"), spacing.Z);

    m_spacingPtr->AppendChild(m_spacingXPtr);
    m_spacingPtr->AppendChild(m_spacingYPtr);
    m_spacingPtr->AppendChild(m_spacingZPtr);

    m_categoryPtr->AppendChild(m_amountPtr);
    m_categoryPtr->AppendChild(m_spacingPtr);

    m_propertyGridPtr->Append(m_categoryPtr);
}
