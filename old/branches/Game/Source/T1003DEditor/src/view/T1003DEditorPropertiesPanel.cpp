#include "T1003DEditorPropertiesPanel.h"

#include <wx/propgrid/advprops.h>
#include "T100EntityTypes.h"

BEGIN_EVENT_TABLE(T1003DEditorPropertiesPanel, wxPropertyGrid)

END_EVENT_TABLE()

T1003DEditorPropertiesPanel::T1003DEditorPropertiesPanel(wxWindow *parent, wxWindowID id,
                    const wxPoint& pos,
                    const wxSize& size,
                    long style,
                    const wxString& name)
    :wxPropertyGrid(parent, id, pos, size, style, name)
{
    //ctor
}

T1003DEditorPropertiesPanel::~T1003DEditorPropertiesPanel()
{
    //dtor
}

T100VOID T1003DEditorPropertiesPanel::update(T100UINT type)
{
    switch(type){
    case T100ENTITY_DOT:
        {
            loadDot();
        }
        break;
    case T100ENTITY_LINE:
        {
            loadLine();
        }
        break;
    case T100ENTITY_CITY:
        {
            loadCity();
        }
        break;
    }
}

T100VOID T1003DEditorPropertiesPanel::loadDot()
{
    Clear();

    wxColourProperty*       colour          = T100NEW wxColourProperty(wxT("Colour"), wxT("colour"));
    wxFileProperty*         file            = T100NEW wxFileProperty(wxT("ShaderFile"), wxT("file"));

    wxBoolProperty*         bundle          = T100NEW wxBoolProperty(wxT("Bundle"), wxT("Bundle"));

    wxPropertyCategory*     location        = T100NEW wxPropertyCategory(wxT("Location"));
    wxFloatProperty*        locationX       = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        locationY       = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        locationZ       = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    location->AddChild(locationX);
    location->AddChild(locationY);
    location->AddChild(locationZ);

    wxPropertyCategory*     rotation        = T100NEW wxPropertyCategory(wxT("Rotation"));
    wxFloatProperty*        rotationX       = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        rotationY       = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        rotationZ       = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    rotation->AddChild(rotationX);
    rotation->AddChild(rotationY);
    rotation->AddChild(rotationZ);

    wxPropertyCategory*     scaling         = T100NEW wxPropertyCategory(wxT("Scaling"));
    wxFloatProperty*        scalingX        = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        scalingY        = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        scalingZ        = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    scaling->AddChild(scalingX);
    scaling->AddChild(scalingY);
    scaling->AddChild(scalingZ);

    wxPropertyCategory*     category        = T100NEW wxPropertyCategory(wxT("Bundle"));
    wxPropertyCategory*     amount          = T100NEW wxPropertyCategory(wxT("Amount"));
    wxIntProperty*          amountX         = T100NEW wxIntProperty(wxT("X"), wxT("x"));
    wxIntProperty*          amountY         = T100NEW wxIntProperty(wxT("Y"), wxT("y"));
    wxIntProperty*          amountZ         = T100NEW wxIntProperty(wxT("Z"), wxT("z"));

    amount->AddChild(amountX);
    amount->AddChild(amountY);
    amount->AddChild(amountZ);

    wxPropertyCategory*     spacing         = T100NEW wxPropertyCategory(wxT("Spacing"));
    wxFloatProperty*        spacingX        = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        spacingY        = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        spacingZ        = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    spacing->AddChild(spacingX);
    spacing->AddChild(spacingY);
    spacing->AddChild(spacingZ);

    category->AddChild(bundle);
    category->AddChild(amount);
    category->AddChild(spacing);

    this->Append(colour);
    this->Append(file);
    this->Append(location);
    this->Append(rotation);
    this->Append(scaling);
    this->Append(category);
}

T100VOID T1003DEditorPropertiesPanel::loadLine()
{
    Clear();
    wxPropertyCategory*     start           = T100NEW wxPropertyCategory(wxT("Start"));
    wxFloatProperty*        startX          = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        startY          = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        startZ          = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    start->AddChild(startX);
    start->AddChild(startY);
    start->AddChild(startZ);

    wxPropertyCategory*     end             = T100NEW wxPropertyCategory(wxT("End"));
    wxFloatProperty*        endX            = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        endY            = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        endZ            = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    end->AddChild(endX);
    end->AddChild(endY);
    end->AddChild(endZ);

    wxColourProperty*       colour          = T100NEW wxColourProperty(wxT("Colour"), wxT("colour"));
    wxFileProperty*         file            = T100NEW wxFileProperty(wxT("ShaderFile"), wxT("file"));

    wxBoolProperty*         bundle          = T100NEW wxBoolProperty(wxT("Bundle"), wxT("Bundle"));

    wxPropertyCategory*     location        = T100NEW wxPropertyCategory(wxT("Location"));
    wxFloatProperty*        locationX       = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        locationY       = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        locationZ       = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    location->AddChild(locationX);
    location->AddChild(locationY);
    location->AddChild(locationZ);

    wxPropertyCategory*     rotation        = T100NEW wxPropertyCategory(wxT("Rotation"));
    wxFloatProperty*        rotationX       = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        rotationY       = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        rotationZ       = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    rotation->AddChild(rotationX);
    rotation->AddChild(rotationY);
    rotation->AddChild(rotationZ);

    wxPropertyCategory*     scaling         = T100NEW wxPropertyCategory(wxT("Scaling"));
    wxFloatProperty*        scalingX        = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        scalingY        = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        scalingZ        = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    scaling->AddChild(scalingX);
    scaling->AddChild(scalingY);
    scaling->AddChild(scalingZ);

    wxPropertyCategory*     category        = T100NEW wxPropertyCategory(wxT("Bundle"));
    wxPropertyCategory*     amount          = T100NEW wxPropertyCategory(wxT("Amount"));
    wxIntProperty*          amountX         = T100NEW wxIntProperty(wxT("X"), wxT("x"));
    wxIntProperty*          amountY         = T100NEW wxIntProperty(wxT("Y"), wxT("y"));
    wxIntProperty*          amountZ         = T100NEW wxIntProperty(wxT("Z"), wxT("z"));

    amount->AddChild(amountX);
    amount->AddChild(amountY);
    amount->AddChild(amountZ);

    wxPropertyCategory*     spacing         = T100NEW wxPropertyCategory(wxT("Spacing"));
    wxFloatProperty*        spacingX        = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        spacingY        = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        spacingZ        = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    spacing->AddChild(spacingX);
    spacing->AddChild(spacingY);
    spacing->AddChild(spacingZ);

    category->AddChild(bundle);
    category->AddChild(amount);
    category->AddChild(spacing);

    this->Append(start);
    this->Append(end);
    this->Append(colour);
    this->Append(file);
    this->Append(location);
    this->Append(rotation);
    this->Append(scaling);
    this->Append(category);
}

T100VOID T1003DEditorPropertiesPanel::loadCity()
{
    Clear();

    wxFileProperty*         vertexFile      = T100NEW wxFileProperty(wxT("VertexShaderFile"), wxT("file"), wxT("shader_mesh_simple_vert.cso"));
    wxFileProperty*         pixelFile1      = T100NEW wxFileProperty(wxT("PixelShaderFile1"), wxT("file"), wxT("shader_mesh_simple_pixel.cso"));
    wxFileProperty*         pixelFile2      = T100NEW wxFileProperty(wxT("PixelShaderFile2"), wxT("file"), wxT("shader_mesh_alt_pixel.cso"));
    wxFileProperty*         meshFile        = T100NEW wxFileProperty(wxT("MeshDataFile"), wxT("file"), wxT("occcity.bin"));

    wxPropertyCategory*     location        = T100NEW wxPropertyCategory(wxT("Location"));
    wxFloatProperty*        locationX       = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        locationY       = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        locationZ       = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    location->AddChild(locationX);
    location->AddChild(locationY);
    location->AddChild(locationZ);

    wxPropertyCategory*     rotation        = T100NEW wxPropertyCategory(wxT("Rotation"));
    wxFloatProperty*        rotationX       = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        rotationY       = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        rotationZ       = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    rotation->AddChild(rotationX);
    rotation->AddChild(rotationY);
    rotation->AddChild(rotationZ);

    wxPropertyCategory*     scaling         = T100NEW wxPropertyCategory(wxT("Scaling"));
    wxFloatProperty*        scalingX        = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        scalingY        = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        scalingZ        = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    scaling->AddChild(scalingX);
    scaling->AddChild(scalingY);
    scaling->AddChild(scalingZ);

    wxPropertyCategory*     category        = T100NEW wxPropertyCategory(wxT("Bundle"));
    wxBoolProperty*         bundle          = T100NEW wxBoolProperty(wxT("Bundle"), wxT("Bundle"));

    wxPropertyCategory*     amount          = T100NEW wxPropertyCategory(wxT("Amount"));
    wxIntProperty*          amountX         = T100NEW wxIntProperty(wxT("X"), wxT("x"));
    wxIntProperty*          amountY         = T100NEW wxIntProperty(wxT("Y"), wxT("y"));
    wxIntProperty*          amountZ         = T100NEW wxIntProperty(wxT("Z"), wxT("z"));

    amount->AddChild(amountX);
    amount->AddChild(amountY);
    amount->AddChild(amountZ);

    wxPropertyCategory*     spacing         = T100NEW wxPropertyCategory(wxT("Spacing"));
    wxFloatProperty*        spacingX        = T100NEW wxFloatProperty(wxT("X"), wxT("x"));
    wxFloatProperty*        spacingY        = T100NEW wxFloatProperty(wxT("Y"), wxT("y"));
    wxFloatProperty*        spacingZ        = T100NEW wxFloatProperty(wxT("Z"), wxT("z"));

    spacing->AddChild(spacingX);
    spacing->AddChild(spacingY);
    spacing->AddChild(spacingZ);

    category->AddChild(bundle);
    category->AddChild(amount);
    category->AddChild(spacing);

    this->Append(vertexFile);
    this->Append(pixelFile1);
    this->Append(pixelFile2);
    this->Append(meshFile);
    this->Append(location);
    this->Append(rotation);
    this->Append(scaling);
    this->Append(category);
}
