#include "T100ProjectDefaultPlaten.h"

#include "T100ProjectMDIMainFrame.h"

T100ProjectDefaultPlaten::T100ProjectDefaultPlaten(T100ProjectView* view)
    :T100ProjectPlatenBase(view)
{
    //ctor
}

T100ProjectDefaultPlaten::~T100ProjectDefaultPlaten()
{
    //dtor
}

T100BOOL T100ProjectDefaultPlaten::create()
{
    T100BOOL            result;

    result  = create_menu();

    return result;
}

T100BOOL T100ProjectDefaultPlaten::destroy()
{

}

T100BOOL T100ProjectDefaultPlaten::create_menu()
{
    T100ProjectMDIMainFrame*    frame           = T100NULL;

    if(!m_view)return T100FALSE;

    frame = (T100ProjectMDIMainFrame*)m_view->getFrame();
    if(!frame)return T100FALSE;

    wxMenuBar*  menuBar     = T100NEW wxMenuBar();
    wxMenu*     menuFile    = T100NEW wxMenu();
    wxMenu*     menuTools   = T100NEW wxMenu();
    wxMenu*     menuHelp    = T100NEW wxMenu();

    //File
    menuFile->Append(wxID_NEW);
    menuFile->Append(wxID_OPEN);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuBar->Append(menuFile, wxGetStockLabel(wxID_FILE));

    //Help
    menuHelp->Append(wxID_HELP);

    menuBar->Append(menuHelp, wxGetStockLabel(wxID_HELP));

    //MenuBar
    frame->SetMenuBar(menuBar);

    return T100TRUE;
}

T100BOOL T100ProjectDefaultPlaten::show()
{

}

T100BOOL T100ProjectDefaultPlaten::hide()
{

}
