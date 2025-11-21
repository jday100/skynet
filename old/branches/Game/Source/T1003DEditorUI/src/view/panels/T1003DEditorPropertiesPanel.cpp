#include "T1003DEditorPropertiesPanel.h"

#include <wx/sizer.h>
#include "entity/T100AllEntities.h"
#include "T1003DEditorCallback.h"

const long T1003DEditorPropertiesPanel::ID_BUTTON_CANCEL = wxNewId();
const long T1003DEditorPropertiesPanel::ID_BUTTON_CONFIRM = wxNewId();

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
    m_sizer     = T100NEW wxBoxSizer(wxVERTICAL);

    m_propertyGrid      = T100NEW wxPropertyGrid(this);
    m_sizer->Add(m_propertyGrid, 1, wxALL | wxEXPAND, 5);

    wxBoxSizer*     sizer   = T100NEW wxBoxSizer(wxHORIZONTAL);
    m_buttonCancel  = T100NEW wxButton(this, ID_BUTTON_CANCEL, _("Button"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON"));
    m_buttonConfirm = T100NEW wxButton(this, ID_BUTTON_CONFIRM, _("Button"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON"));
    sizer->Add(m_buttonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sizer->Add(m_buttonConfirm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_sizer->Add(sizer, 0, wxALL|wxALIGN_RIGHT, 5);

    SetSizer(m_sizer);
    m_sizer->Fit(this);
    m_sizer->SetSizeHints(this);

    m_propertyGrid->Connect(wxEVT_PG_CHANGED, (wxObjectEventFunction)&T1003DEditorPropertiesPanel::OnPGChanged, T100NULL, this);

    m_buttonCancel->SetLabel(L"Cancel");
    m_buttonConfirm->SetLabel(L"Append");

    Connect(ID_BUTTON_CANCEL,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorPropertiesPanel::OnButtonCancelClick);
    Connect(ID_BUTTON_CONFIRM,      wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorPropertiesPanel::OnButtonConfirmClick);

    m_buttonCancel->Hide();
    m_buttonConfirm->Hide();
}

T100VOID T1003DEditorPropertiesPanel::uninit()
{

}

T100VOID T1003DEditorPropertiesPanel::Clear()
{
    m_propertyGrid->Clear();

    if(m_gridPtr){
        T100SAFE_DELETE m_gridPtr;
        m_gridPtr   = T100NULL;
    }
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
    case T100ENTITY_MESH:
        {
            loadMeshGrid(entity);
        }
        break;
    case T100ENTITY_CITY:
        {
            loadCityGrid(entity);
        }
        break;
    case T100ENTITY_SPHERE:
        {
            loadSphereGrid(entity);
        }
        break;
    case T100ENTITY_RECTANGLE:
        {
            loadRectangleGrid(entity);
        }
        break;
    }
}

T100VOID T1003DEditorPropertiesPanel::UpdateMesh(T100Mesh* mesh)
{
    loadMeshGrid(mesh);
}

T100VOID T1003DEditorPropertiesPanel::Update(T100Scene* scene)
{
    loadSceneGrid(scene);
}

T100VOID T1003DEditorPropertiesPanel::Update(T100Camera* camera)
{
    loadCameraGrid(camera);
}

T100VOID T1003DEditorPropertiesPanel::Update(T100Light* light)
{
    loadLightGrid(light);
}

T100VOID T1003DEditorPropertiesPanel::Update(T100Material* material)
{
    loadMaterialGrid(material);
}

T100VOID T1003DEditorPropertiesPanel::loadDotGrid(T100Entity* entity)
{
    T1003DEditorDotGrid*  grid   = T100NEW T1003DEditorDotGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadLineGrid(T100Entity* entity)
{
    T1003DEditorLineGrid*  grid   = T100NEW T1003DEditorLineGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadTriangleGrid(T100Entity* entity)
{
    T1003DEditorTriangleGrid*  grid   = T100NEW T1003DEditorTriangleGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadPlaneGrid(T100Entity* entity)
{
    T1003DEditorPlaneGrid*  grid   = T100NEW T1003DEditorPlaneGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadMeshGrid(T100Entity* entity)
{
    T1003DEditorMeshGrid*  grid   = T100NEW T1003DEditorMeshGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadCityGrid(T100Entity* entity)
{
    T1003DEditorCityGrid*  grid   = T100NEW T1003DEditorCityGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadSphereGrid(T100Entity* entity)
{
    T1003DEditorSphereGrid*  grid   = T100NEW T1003DEditorSphereGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadRectangleGrid(T100Entity* entity)
{
    T1003DEditorRectangleGrid*  grid   = T100NEW T1003DEditorRectangleGrid(m_propertyGrid);

    grid->Update(entity);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadSceneGrid(T100Scene* scene)
{
    T1003DEditorSceneGrid*  grid   = T100NEW T1003DEditorSceneGrid(m_propertyGrid);

    grid->Update(scene);

    m_gridPtr   = grid;

    m_buttonCancel->Show(true);
    m_buttonConfirm->SetLabel(wxT("Update"));
    m_buttonConfirm->Show(true);
    //m_sizer->Fit(this);
    //m_sizer->SetSizeHints(this);

    //Refresh();
    SendSizeEvent();
}

T100VOID T1003DEditorPropertiesPanel::loadCameraGrid(T100Camera* camera)
{
}


T100VOID T1003DEditorPropertiesPanel::loadLightGrid(T100Light* light)
{
    T1003DEditorLightGrid*  grid   = T100NEW T1003DEditorLightGrid(m_propertyGrid);

    grid->Update(light);

    m_gridPtr   = grid;
}

T100VOID T1003DEditorPropertiesPanel::loadMaterialGrid(T100Material* material)
{
    T1003DEditorMaterialGrid*  grid   = T100NEW T1003DEditorMaterialGrid(m_propertyGrid);

    grid->Update(material);

    m_gridPtr   = grid;
}

void T1003DEditorPropertiesPanel::OnPGChanged(wxPropertyGridEvent& event)
{
    m_gridPtr->OnPGChanged(event);
}

void T1003DEditorPropertiesPanel::OnButtonCancelClick(wxCommandEvent& event)
{

}

void T1003DEditorPropertiesPanel::OnButtonConfirmClick(wxCommandEvent& event)
{
    T1003DEditorCallback::Append();
}
