#include "T100MDIPaintDocument.h"

#include "T100Painter.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"
#include "T100MDIPaintView.h"


namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDIPaintDocument, wxDocument)

T100MDIPaintDocument::T100MDIPaintDocument()
{
    //ctor
    create();
}

T100MDIPaintDocument::~T100MDIPaintDocument()
{
    //dtor
    destroy();
}

T100VOID T100MDIPaintDocument::create()
{

}

T100VOID T100MDIPaintDocument::destroy()
{

}

T100BOOL T100MDIPaintDocument::OnCreate(const wxString& path, long flags)
{
    if( !wxDocument::OnCreate(path, flags) ){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100MDIPaintDocument::DoSaveDocument(const wxString& filename)
{
    return GetPainter()->getServe()->SaveFile(filename.ToStdWstring());
}

T100BOOL T100MDIPaintDocument::DoOpenDocument(const wxString& filename)
{
    if ( !GetPainter()->getServe()->LoadFile(filename.ToStdWstring()) )
        return T100FALSE;

    Modify(T100FALSE);

    return T100TRUE;
}

T100BOOL T100MDIPaintDocument::IsModified() const
{
    T100Painter::T100Painter* painter = GetPainter();
    return wxDocument::IsModified() || (painter && painter->getServe()->IsModified());
}

T100VOID T100MDIPaintDocument::Modify(T100BOOL modified)
{
    wxDocument::Modify(modified);

    T100Painter::T100Painter* painter = GetPainter();
    if (painter && !modified)
    {
        painter->getServe()->DiscardEdits();
    }
}

T100Painter::T100Painter* T100MDIPaintDocument::GetPainter() const
{
    wxView*             view        = T100NULL;
    T100MDIPaintView*   paint       = T100NULL;
    T100Painter::T100Painter*       painter         = T100NULL;

    view    = GetFirstView();
    if(!view)return T100NULL;

    paint   = wxStaticCast(view, T100MDIPaintView);
    if(!paint)return T100NULL;

    painter = paint->GetPainter();

    return painter;
}

}
