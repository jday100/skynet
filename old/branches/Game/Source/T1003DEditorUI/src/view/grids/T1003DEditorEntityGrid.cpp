#include "T1003DEditorEntityGrid.h"

#include "T1003DEditorCallback.h"

T1003DEditorEntityGrid::T1003DEditorEntityGrid(wxPropertyGrid* grid) :
    T1003DEditorGridBase(grid)
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
    T100Vector4u    value   = m_entityPtr->GetColour();
    wxColour        colour(value.RED, value.GREEN, value.BLUE, value.ALPHA);
    m_colourPtr     = T100NEW wxColourProperty(wxT("Colour"), wxT("colour"), colour);

    m_propertyGridPtr->Append(m_colourPtr);

    m_shaderFilePtr = T100NEW wxFileProperty(wxT("ShaderFile"), wxT("shaderfile"), m_entityPtr->VertexShaderFile.FILE);

    m_propertyGridPtr->Append(m_shaderFilePtr);

    wxArrayString   names;
    wxArrayInt      values;
    T100UINT        temp        = -1;

    T1003DEditorCallback::GetMaterialList(names, values, m_entityPtr->GetMaterial(), temp);

    m_materialPtr   = T100NEW wxEnumProperty(wxT("Material"), wxT("material"), names, values, temp);

    m_propertyGridPtr->Append(m_materialPtr);


    m_visiblePtr    = T100NEW wxBoolProperty(wxT("Visible"), wxT("visible"), m_entityPtr->GetVisible());

    m_propertyGridPtr->Append(m_visiblePtr);

    m_bundlePtr    = T100NEW wxBoolProperty(wxT("Bundle"), wxT("bundle"), m_entityPtr->GetBundle());

    m_propertyGridPtr->Append(m_bundlePtr);
}

T100VOID T1003DEditorEntityGrid::CreateShader()
{
    m_shader      = T100NEW wxPropertyCategory(wxT("Shader"));
    m_propertyGridPtr->Append(m_shader);

    m_shaderInherit     = T100NEW wxBoolProperty(wxT("Inherit"), wxT("shaderinherit"));
    m_shader->AppendChild(m_shaderInherit);

    CreateParameters();
    CreateSettings();
    CreateVertexShader();
    CreatePixelShader();
}

T100VOID T1003DEditorEntityGrid::CreateCategories()
{
    m_positionPtr   = T100NEW wxPropertyCategory(wxT("Position"));

    T100Vector3     position    = m_entityPtr->GetPosition();

    m_positionXPtr  = T100NEW wxFloatProperty(wxT("X"), wxT("positionx"), position.X);
    m_positionYPtr  = T100NEW wxFloatProperty(wxT("Y"), wxT("positiony"), position.Y);
    m_positionZPtr  = T100NEW wxFloatProperty(wxT("Z"), wxT("positionz"), position.Z);

    m_positionPtr->AddChild(m_positionXPtr);
    m_positionPtr->AddChild(m_positionYPtr);
    m_positionPtr->AddChild(m_positionZPtr);

    m_propertyGridPtr->Append(m_positionPtr);

    m_rotationPtr   = T100NEW wxPropertyCategory(wxT("Rotation"));

    T100Vector3     rotation    = m_entityPtr->GetRotation();

    m_rotationXPtr  = T100NEW wxFloatProperty(wxT("X"), wxT("rotationx"), rotation.X);
    m_rotationYPtr  = T100NEW wxFloatProperty(wxT("Y"), wxT("rotationy"), rotation.Y);
    m_rotationZPtr  = T100NEW wxFloatProperty(wxT("Z"), wxT("rotationz"), rotation.Z);

    m_rotationPtr->AddChild(m_rotationXPtr);
    m_rotationPtr->AddChild(m_rotationYPtr);
    m_rotationPtr->AddChild(m_rotationZPtr);

    m_propertyGridPtr->Append(m_rotationPtr);

    m_scalingPtr    = T100NEW wxPropertyCategory(wxT("Scaling"));

    T100Vector3     scaling     = m_entityPtr->GetScaling();

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
        T100BOOL    flag    = m_entityPtr->GetBundle();
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
        T100BOOL    flag    = m_entityPtr->GetBundle();
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
        T100BOOL    flag    = m_entityPtr->GetBundle();
        T100UINT    value   = event.GetValue().GetInteger();

        T100Vector3u    result;

        result  = {m_amountXPtr->GetValue().GetInteger(), m_amountYPtr->GetValue().GetInteger(), value};

        m_entityPtr->SetBundleAmount(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingx"){
        T100BOOL    flag    = m_entityPtr->GetBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3     result;

        result  = {value, m_spacingYPtr->GetValue().GetDouble(), m_spacingZPtr->GetValue().GetDouble()};

        m_entityPtr->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingy"){
        T100BOOL    flag    = m_entityPtr->GetBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3     result;

        result  = {m_spacingXPtr->GetValue().GetDouble(), value, m_spacingZPtr->GetValue().GetDouble()};

        m_entityPtr->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"spacingz"){
        T100BOOL    flag    = m_entityPtr->GetBundle();
        T100FLOAT   value   = event.GetValue().GetDouble();

        T100Vector3     result;

        result  = {m_spacingXPtr->GetValue().GetDouble(), m_spacingYPtr->GetValue().GetDouble(), value};

        m_entityPtr->SetBundleSpacing(result);

        if(flag){
            T1003DEditorCallback::SetBundle(flag, m_entityPtr);
            update  = T100TRUE;
        }
    }

    if(name == L"shaderfile"){
        T100BOOL        flag    = m_entityPtr->GetBundle();
        T100WSTRING     file    = event.GetValue().GetString().ToStdWstring();

        m_entityPtr->VertexShaderFile.FILE      = file;

        T1003DEditorCallback::SetBundle(flag, m_entityPtr);
        update  = T100TRUE;
    }

    if(name == L"material"){
        T100WSTRING     name;

        name    = event.GetProperty()->GetDisplayedString().ToStdWstring();

        m_entityPtr->SetMaterial(name);

        update  = T100TRUE;
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

    m_amountPtr->AddChild(m_amountXPtr);
    m_amountPtr->AddChild(m_amountYPtr);
    m_amountPtr->AddChild(m_amountZPtr);

    T100Vector3     spacing = m_entityPtr->GetBundleSpacing();

    m_spacingXPtr   = T100NEW wxFloatProperty(wxT("X"), wxT("spacingx"), spacing.X);
    m_spacingYPtr   = T100NEW wxFloatProperty(wxT("Y"), wxT("spacingy"), spacing.Y);
    m_spacingZPtr   = T100NEW wxFloatProperty(wxT("Z"), wxT("spacingz"), spacing.Z);

    m_spacingPtr->AddChild(m_spacingXPtr);
    m_spacingPtr->AddChild(m_spacingYPtr);
    m_spacingPtr->AddChild(m_spacingZPtr);

    m_categoryPtr->AddChild(m_amountPtr);
    m_categoryPtr->AddChild(m_spacingPtr);

    m_propertyGridPtr->Append(m_categoryPtr);
}

T100VOID T1003DEditorEntityGrid::CreateVertexShader()
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    m_vertex    = T100NEW wxPropertyCategory(wxT("Vertex"));

    m_vertexShaderInherit       = T100NEW wxBoolProperty(wxT("Inherit"), wxT("vertexshaderinherit"));
    m_vertex->AppendChild(m_vertexShaderInherit);

    m_vertexShaderFileType  = T100NEW wxEnumProperty(wxT("FileType"), wxT("shadervertexfiletype"), enumTypeLabels, enumTypeValues, m_entityPtr->VertexShaderFile.TYPE);

    m_vertex->AppendChild(m_vertexShaderFileType);

    m_shader->AppendChild(m_vertex);

    m_vertexShaderFile      = T100NEW wxFileProperty(wxT("FileName"), wxT("shadervertexfilename"));

    m_vertex->AppendChild(m_vertexShaderFile);

    switch(m_entityPtr->VertexShaderFile.TYPE){
    case T100SHADER_FILE_SOURCE:
        {
            m_vertexShaderEntry     = T100NEW wxStringProperty(wxT("Entry"), wxT("shadervertexentry"));
            m_vertexShaderTarget    = T100NEW wxStringProperty(wxT("Target"), wxT("shadervertextarget"));

            m_vertex->AppendChild(m_vertexShaderEntry);
            m_vertex->AppendChild(m_vertexShaderTarget);
        }
        break;
    }
}

T100VOID T1003DEditorEntityGrid::CreatePixelShader()
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };


    m_pixel     = T100NEW wxPropertyCategory(wxT("Pixel"));

    m_pixelShaderInherit        = T100NEW wxBoolProperty(wxT("Inherit"), wxT("pixelshaderinherit"));
    m_pixel->AppendChild(m_pixelShaderInherit);

    m_pixelShaderFileType   = T100NEW wxEnumProperty(wxT("FileType"), wxT("shaderpixelfiletype"), enumTypeLabels, enumTypeValues, m_entityPtr->PixelShaderFile.TYPE);

    m_pixel->AppendChild(m_pixelShaderFileType);

    m_shader->AppendChild(m_pixel);

    m_pixelShaderFile       = T100NEW wxFileProperty(wxT("FileName"), wxT("shaderpixelfilename"));

    m_pixel->AppendChild(m_pixelShaderFile);

    switch(m_entityPtr->PixelShaderFile.TYPE){
    case T100SHADER_FILE_SOURCE:
        {
            m_pixelShaderEntry      = T100NEW wxStringProperty(wxT("Entry"), wxT("shaderpixelentry"));
            m_pixelShaderTarget     = T100NEW wxStringProperty(wxT("Target"), wxT("shaderpixeltarget"));

            m_pixel->AppendChild(m_pixelShaderEntry);
            m_pixel->AppendChild(m_pixelShaderTarget);
        }
        break;
    }
}

T100VOID T1003DEditorEntityGrid::CreateParameters()
{

}

T100VOID T1003DEditorEntityGrid::CreateSettings()
{

}
