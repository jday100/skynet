#include "T100MDITextDocument.h"

#include "T100MDITextView.h"
#include "T100Editor.h"
#include "T100EditorView.h"

namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDITextDocument, T100MDIDocumentBase)

T100MDITextDocument::T100MDITextDocument()
    :T100MDIDocumentBase()
{
    //ctor
    create();
}

T100MDITextDocument::~T100MDITextDocument()
{
    //dtor
    destroy();
}

T100VOID T100MDITextDocument::create()
{

}

T100VOID T100MDITextDocument::destroy()
{

}

T100BOOL T100MDITextDocument::OnCreate(const wxString& path, long flags)
{
    if( !wxDocument::OnCreate(path, flags) ){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100MDITextDocument::DoSaveDocument(const wxString& filename)
{
    return GetEditor()->getView()->getEditCtrl()->SaveFile(filename);
}

T100BOOL T100MDITextDocument::DoOpenDocument(const wxString& filename)
{
    if ( !GetEditor()->getView()->getEditCtrl()->LoadFile(filename) )
        return T100FALSE;

    Modify(T100FALSE);

    return T100TRUE;
}

T100BOOL T100MDITextDocument::IsModified() const
{
    T100Editor::T100Editor* editor = GetEditor();
    return wxDocument::IsModified() || (editor && editor->getView()->getEditCtrl()->IsModified());
}

T100VOID T100MDITextDocument::Modify(T100BOOL modified)
{
    wxDocument::Modify(modified);

    T100Editor::T100Editor* editor = GetEditor();
    if (editor && !modified)
    {
        editor->getView()->getEditCtrl()->DiscardEdits();
    }
}

T100Editor::T100Editor* T100MDITextDocument::GetEditor() const
{
    wxView*             view        = T100NULL;
    T100MDITextView*    text        = T100NULL;
    T100Editor::T100Editor*         editor      = T100NULL;

    view    = GetFirstView();
    if(!view)return T100NULL;

    text    = wxStaticCast(view, T100MDITextView);
    if(!text)return T100NULL;

    editor  = text->GetEditor();

    return editor;
}

}
