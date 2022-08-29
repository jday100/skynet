#include "T100IDETextDocument.h"

#include "T100IDETextView.h"

IMPLEMENT_DYNAMIC_CLASS(T100IDETextDocument, wxDocument)

T100IDETextDocument::T100IDETextDocument()
{
    //ctor
}

T100IDETextDocument::~T100IDETextDocument()
{
    //dtor
}

T100EditCtrl* T100IDETextDocument::GetEdit() const
{
    wxView* view = GetFirstView();
    return view ? wxStaticCast(view, T100IDETextView)->GetEdit() : NULL;
}

T100BOOL T100IDETextDocument::OnCreate(const wxString& path, long flags)
{
    if ( !wxDocument::OnCreate(path, flags) )
        return T100FALSE;

    GetEdit()->Connect
    (
        wxEVT_TEXT,
        wxCommandEventHandler(T100IDETextDocument::OnTextChange),
        NULL,
        this
    );

    return T100TRUE;
}

T100BOOL T100IDETextDocument::DoSaveDocument(const wxString& filename)
{
    return GetEdit()->SaveFile(filename);
}

T100BOOL T100IDETextDocument::DoOpenDocument(const wxString& filename)
{
    if ( !GetEdit()->LoadFile(filename) )
        return T100FALSE;

    Modify(T100FALSE);

    return T100TRUE;
}

T100BOOL T100IDETextDocument::IsModified() const
{
    T100EditCtrl* wnd = GetEdit();
    return wxDocument::IsModified() || (wnd && wnd->IsModified());
}

T100VOID T100IDETextDocument::Modify(T100BOOL modified)
{
    wxDocument::Modify(modified);

    T100EditCtrl* wnd = GetEdit();
    if (wnd && !modified)
    {
        wnd->DiscardEdits();
    }
}

T100VOID T100IDETextDocument::OnTextChange(wxCommandEvent& event)
{
    Modify(T100TRUE);

    event.Skip();
}
