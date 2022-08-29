#include "T100IDETextView.h"

#include <wx/stockitem.h>
#include "T100App.h"
#include "T100IDEFrameText.h"


IMPLEMENT_DYNAMIC_CLASS(T100IDETextView, wxView)

wxBEGIN_EVENT_TABLE(T100IDETextView, wxView)
wxEND_EVENT_TABLE()

T100IDETextView::T100IDETextView()
{
    //ctor
}

T100IDETextView::~T100IDETextView()
{
    //dtor
}

T100EditCtrl* T100IDETextView::GetEdit() const
{
    return m_editor;
}

T100BOOL T100IDETextView::OnCreate(wxDocument* doc, long flags)
{
    if ( !wxView::OnCreate(doc, flags) )
        return T100TRUE;

    wxFrame* frame = T100NEW T100IDEFrameText(doc, this, wxStaticCast(wxGetApp().GetTopWindow(), wxMDIParentFrame));

    wxASSERT(frame == GetFrame());

    m_editor = T100NEW T100EditCtrl(frame, wxID_ANY, wxDefaultPosition,
                            wxDefaultSize, wxTE_MULTILINE, wxEmptyString);

    CreateMenu(frame);
    frame->Show();

    return T100TRUE;
}

T100VOID T100IDETextView::OnDraw(wxDC* dc)
{

}

T100BOOL T100IDETextView::OnClose(T100BOOL deleteWindow)
{
    if ( !wxView::OnClose(deleteWindow) )
        return T100FALSE;

    Activate(T100FALSE);


    if ( deleteWindow )
    {
        GetFrame()->Destroy();
        SetFrame(T100NULL);
    }

    return T100TRUE;
}

T100VOID T100IDETextView::CreateMenu(wxFrame* frame)
{
    wxMenuBar*  menuBar     = T100NEW wxMenuBar();

    wxMenu*     menuFile    = T100NEW wxMenu;

    menuFile->Append(wxID_NEW);
    menuFile->Append(wxID_OPEN);

    menuFile->Append(wxID_CLOSE);
    menuFile->Append(wxID_SAVE);
    menuFile->Append(wxID_SAVEAS);
    menuFile->Append(wxID_REVERT, _("Re&vert..."));

    if ( /*supportsPrinting*/ 0 )
    {
        menuFile->AppendSeparator();
        menuFile->Append(wxID_PRINT);
        menuFile->Append(wxID_PRINT_SETUP, "Print &Setup...");
        menuFile->Append(wxID_PREVIEW);
    }

    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuBar->Append(menuFile, wxGetStockLabel(wxID_FILE));

    if( /*edit*/ 1 ){
        wxMenu*     menuEdit    = T100NEW wxMenu;

        menuEdit->Append(wxID_UNDO);
        menuEdit->Append(wxID_REDO);
        menuEdit->AppendSeparator();
        menuEdit->Append(wxID_CUT);
        menuEdit->Append(wxID_COPY);
        menuEdit->Append(wxID_PASTE);
        menuEdit->Append(wxID_SELECTALL);

        menuBar->Append(menuEdit, wxGetStockLabel(wxID_EDIT));
    }

    wxMenu*     menuHelp    = T100NEW wxMenu;

    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuHelp, wxGetStockLabel(wxID_HELP));

    frame->SetMenuBar(menuBar);
}
