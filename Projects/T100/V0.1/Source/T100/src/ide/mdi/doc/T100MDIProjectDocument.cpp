#include "T100MDIProjectDocument.h"

#include "T100Project.h"
#include "T100ProjectServe.h"
#include "T100ProjectView.h"
#include "T100MDIProjectView.h"


namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDIProjectDocument, T100MDIDocumentBase)

T100MDIProjectDocument::T100MDIProjectDocument()
    :T100MDIDocumentBase()
{
    //ctor
    create();
}

T100MDIProjectDocument::~T100MDIProjectDocument()
{
    //dtor
    destroy();
}

T100VOID T100MDIProjectDocument::create()
{

}

T100VOID T100MDIProjectDocument::destroy()
{

}

T100BOOL T100MDIProjectDocument::OnCreate(const wxString& path, long flags)
{
    if( !wxDocument::OnCreate(path, flags) ){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100MDIProjectDocument::DoSaveDocument(const wxString& filename)
{
    return GetProject()->getServe()->SaveFile(filename.ToStdWstring());
}

T100BOOL T100MDIProjectDocument::DoOpenDocument(const wxString& filename)
{
    if( !GetProject()->getServe()->LoadFile(filename.ToStdWstring()) )
        return T100FALSE;

    Modify(T100FALSE);

    return T100TRUE;
}

T100BOOL T100MDIProjectDocument::IsModified() const
{
    T100PROJECT::T100Project*   project     = GetProject();
    return wxDocument::IsModified() || (project && project->getServe()->IsModified());
}

T100VOID T100MDIProjectDocument::Modify(T100BOOL modified)
{
    wxDocument::Modify(modified);

    T100PROJECT::T100Project*   project     = GetProject();
    if( project && !modified )
    {
        project->getServe()->DiscardEdits();
    }
}

T100PROJECT::T100Project* T100MDIProjectDocument::GetProject() const
{
    wxView*                         view            = T100NULL;
    T100MDIProjectView*             mdi_view        = T100NULL;
    T100PROJECT::T100Project*       project         = T100NULL;

    view    = GetFirstView();
    if(!view)return T100NULL;

    mdi_view    = wxStaticCast(view, T100MDIProjectView);
    if(!mdi_view)return T100NULL;

    project = mdi_view->GetProject();

    return project;
}

}
