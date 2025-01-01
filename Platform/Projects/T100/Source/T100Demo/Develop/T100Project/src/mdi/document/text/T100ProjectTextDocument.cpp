#include "T100ProjectTextDocument.h"

IMPLEMENT_DYNAMIC_CLASS(T100ProjectTextDocument, T100ProjectMDIDocument)

T100ProjectTextDocument::T100ProjectTextDocument()
    :T100ProjectMDIDocument()
{
    //ctor
    create();
}

T100ProjectTextDocument::~T100ProjectTextDocument()
{
    //dtor
    destroy();
}

T100VOID T100ProjectTextDocument::create()
{

}

T100VOID T100ProjectTextDocument::destroy()
{

}

T100BOOL T100ProjectTextDocument::OnCreate(const wxString& path, long flags)
{
    if( !wxDocument::OnCreate(path, flags) ){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100ProjectTextDocument::DoSaveDocument(const wxString& filename)
{
    return T100FALSE;
}

T100BOOL T100ProjectTextDocument::DoOpenDocument(const wxString& filename)
{
    return T100FALSE;
}

T100BOOL T100ProjectTextDocument::IsModifed() const
{
    return T100FALSE;
}

T100VOID T100ProjectTextDocument::Modify(T100BOOL modified)
{

}
