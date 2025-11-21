#include "T1003DEditorMaterialGrid.h"

T1003DEditorMaterialGrid::T1003DEditorMaterialGrid(wxPropertyGrid* grid) :
    T1003DEditorGridBase(grid)
{
    //ctor
}

T1003DEditorMaterialGrid::~T1003DEditorMaterialGrid()
{
    //dtor
}

T100VOID T1003DEditorMaterialGrid::Update(T100Material* material)
{
    m_material  = material;

    m_propertyGridPtr->Clear();

    m_name  = T100NEW wxStringProperty(wxT("Name"), wxT("name"), material->Name);

    m_propertyGridPtr->Append(m_name);

    T100Vector4&        diffuse     = material->GetDiffuse();

    wxPropertyCategory*     diffuseCategory     = T100NEW wxPropertyCategory(wxT("Diffuse"));

    m_diffuseRed    = T100NEW wxFloatProperty(wxT("Red"), wxT("diffusered"), diffuse.RED);
    m_diffuseGreen  = T100NEW wxFloatProperty(wxT("Green"), wxT("diffusegreen"), diffuse.GREEN);
    m_diffuseBlue   = T100NEW wxFloatProperty(wxT("Blue"), wxT("diffuseblue"), diffuse.BLUE);
    m_diffuseAlpha  = T100NEW wxFloatProperty(wxT("Alpha"), wxT("diffusealpha"), diffuse.ALPHA);

    diffuseCategory->AppendChild(m_diffuseRed);
    diffuseCategory->AppendChild(m_diffuseGreen);
    diffuseCategory->AppendChild(m_diffuseBlue);
    diffuseCategory->AppendChild(m_diffuseAlpha);

    m_propertyGridPtr->Append(diffuseCategory);

    T100Vector4&        specular        = material->GetSpecular();

    wxPropertyCategory*     specularCategory        = T100NEW wxPropertyCategory(wxT("Specular"));

    m_specularRed       = T100NEW wxFloatProperty(wxT("Red"), wxT("specularred"), specular.RED);
    m_specularGreen     = T100NEW wxFloatProperty(wxT("Green"), wxT("speculargreen"), specular.GREEN);
    m_specularBlue      = T100NEW wxFloatProperty(wxT("Blue"), wxT("specularblue"), specular.BLUE);
    m_specularAlpha     = T100NEW wxFloatProperty(wxT("Alpha"), wxT("specularalpha"), specular.ALPHA);

    specularCategory->AppendChild(m_specularRed);
    specularCategory->AppendChild(m_specularGreen);
    specularCategory->AppendChild(m_specularBlue);
    specularCategory->AppendChild(m_specularAlpha);

    m_propertyGridPtr->Append(specularCategory);


    T100Vector4&        ambient         = material->GetAmbient();

    wxPropertyCategory*     ambientCategory     = T100NEW wxPropertyCategory(wxT("Ambient"));

    m_ambientRed        = T100NEW wxFloatProperty(wxT("Red"), wxT("ambientred"), ambient.RED);
    m_ambientGreen      = T100NEW wxFloatProperty(wxT("Green"), wxT("ambientgreen"), ambient.GREEN);
    m_ambientBlue       = T100NEW wxFloatProperty(wxT("Blue"), wxT("ambientblue"), ambient.BLUE);
    m_ambientAlpha      = T100NEW wxFloatProperty(wxT("Alpha"), wxT("ambientalpha"), ambient.ALPHA);

    ambientCategory->AppendChild(m_ambientRed);
    ambientCategory->AppendChild(m_ambientGreen);
    ambientCategory->AppendChild(m_ambientBlue);
    ambientCategory->AppendChild(m_ambientAlpha);

    m_propertyGridPtr->Append(ambientCategory);

    T100Vector4&        emissive        = material->GetEmissive();

    wxPropertyCategory*     emissiveCategory        = T100NEW wxPropertyCategory(wxT("Emissive"));

    m_emissiveRed       = T100NEW wxFloatProperty(wxT("Red"), wxT("emissivered"), emissive.RED);
    m_emissiveGreen     = T100NEW wxFloatProperty(wxT("Green"), wxT("emissivegreen"), emissive.GREEN);
    m_emissiveBlue      = T100NEW wxFloatProperty(wxT("Blue"), wxT("emissiveblue"), emissive.BLUE);
    m_emissiveAlpha     = T100NEW wxFloatProperty(wxT("Alpha"), wxT("emissivealpha"), emissive.ALPHA);

    emissiveCategory->AppendChild(m_emissiveRed);
    emissiveCategory->AppendChild(m_emissiveGreen);
    emissiveCategory->AppendChild(m_emissiveBlue);
    emissiveCategory->AppendChild(m_emissiveAlpha);

    m_propertyGridPtr->Append(emissiveCategory);

    T100Vector4&        transparent     = material->GetTransparent();

    wxPropertyCategory*     transparentCategory     = T100NEW wxPropertyCategory(wxT("Transparent"));

    m_transparentRed        = T100NEW wxFloatProperty(wxT("Red"), wxT("transparentred"), transparent.RED);
    m_transparentGreen      = T100NEW wxFloatProperty(wxT("Green"), wxT("transparentgreen"), transparent.GREEN);
    m_transparentBlue       = T100NEW wxFloatProperty(wxT("Blue"), wxT("transparentblue"), transparent.BLUE);
    m_transparentAlpha      = T100NEW wxFloatProperty(wxT("Alpha"), wxT("transparentalpha"), transparent.ALPHA);

    transparentCategory->AppendChild(m_transparentRed);
    transparentCategory->AppendChild(m_transparentGreen);
    transparentCategory->AppendChild(m_transparentBlue);
    transparentCategory->AppendChild(m_transparentAlpha);

    m_propertyGridPtr->Append(transparentCategory);
}

T100VOID T1003DEditorMaterialGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update          = T100FALSE;
    T100WSTRING     name;

    name    = event.GetPropertyName().ToStdWstring();

    T100FLOAT       red;
    T100FLOAT       green;
    T100FLOAT       blue;
    T100FLOAT       alpha;

    if(name == L"diffusered" ||
       name == L"diffusegreen" ||
       name == L"diffuseblue" ||
       name == L"diffusealpha"){

        red     = m_diffuseRed->GetValue().GetDouble();
        green   = m_diffuseGreen->GetValue().GetDouble();
        blue    = m_diffuseBlue->GetValue().GetDouble();
        alpha   = m_diffuseAlpha->GetValue().GetDouble();

        m_material->SetDiffuse(red, green, blue, alpha);
        update  = T100TRUE;
    }else if(name == L"specularred" ||
       name == L"speculargreen" ||
       name == L"specularblue" ||
       name == L"specularalpha"){

        red     = m_specularRed->GetValue().GetDouble();
        green   = m_specularGreen->GetValue().GetDouble();
        blue    = m_specularBlue->GetValue().GetDouble();
        alpha   = m_specularAlpha->GetValue().GetDouble();

        m_material->SetSpecular(red, green, blue, alpha);
        update  = T100TRUE;
    }else if(name == L"ambientred" ||
       name == L"ambientgreen" ||
       name == L"ambientblue" ||
       name == L"ambientalpha"){

        red     = m_ambientRed->GetValue().GetDouble();
        green   = m_ambientGreen->GetValue().GetDouble();
        blue    = m_ambientBlue->GetValue().GetDouble();
        alpha   = m_ambientAlpha->GetValue().GetDouble();

        m_material->SetAmbient(red, green, blue, alpha);
        update  = T100TRUE;
    }else if(name == L"emissivered" ||
       name == L"emissivegreen" ||
       name == L"emissiveblue" ||
       name == L"emissivealpha"){

        red     = m_emissiveRed->GetValue().GetDouble();
        green   = m_emissiveGreen->GetValue().GetDouble();
        blue    = m_emissiveBlue->GetValue().GetDouble();
        alpha   = m_emissiveAlpha->GetValue().GetDouble();

        m_material->SetEmissive(red, green, blue, alpha);
        update  = T100TRUE;
    }else if(name == L"transparentred" ||
       name == L"transparentgreen" ||
       name == L"transparentblue" ||
       name == L"transparentalpha"){

        red     = m_transparentRed->GetValue().GetDouble();
        green   = m_transparentGreen->GetValue().GetDouble();
        blue    = m_transparentBlue->GetValue().GetDouble();
        alpha   = m_transparentAlpha->GetValue().GetDouble();

        m_material->SetTransparent(red, green, blue, alpha);
        update  = T100TRUE;
    }
}

