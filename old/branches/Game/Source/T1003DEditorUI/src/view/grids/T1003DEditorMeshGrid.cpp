#include "T1003DEditorMeshGrid.h"

#include "entity/T100Mesh.h"
#include "T1003DEditorCallback.h"

T1003DEditorMeshGrid::T1003DEditorMeshGrid(wxPropertyGrid* grid) :
    T1003DEditorEntityGrid(grid)
{
    //ctor
}

T1003DEditorMeshGrid::~T1003DEditorMeshGrid()
{
    //dtor
}

T100VOID T1003DEditorMeshGrid::Update(T100Entity* entityPtr)
{
    T100Mesh*       meshPtr     = T100NULL;

    meshPtr     = dynamic_cast<T100Mesh*>(entityPtr);

    if(!meshPtr)return;

    m_entityPtr = entityPtr;

    m_propertyGridPtr->Clear();

    CreateName();
    CreateEntity();

    wxFileProperty*     m_filePtr = T100NEW wxFileProperty(wxT("File"), wxT("file"));

    m_propertyGridPtr->Append(m_filePtr);

    CreateShader();
    CreateCategories();
}

T100VOID T1003DEditorMeshGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    T100BOOL        update      = T100FALSE;
    T100WSTRING     name;

    name    = event.GetPropertyName().ToStdWstring();

    if(name == L"file"){
        T1003DEditorCallback::SetBundle(T100FALSE, m_entityPtr);
    }



    OnEntityPGChanged(event);
}
