#include "T100IDEViewFile.h"

#include <wx/stockitem.h>
#include <wx/filedlg.h>
#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackFile.h"

const long T100IDEViewFile::ID_MENUITEM_FILE_NEW        = wxNewId();
const long T100IDEViewFile::ID_MENUITEM_FILE_DELETE     = wxNewId();
const long T100IDEViewFile::ID_MENUITEM_FILE_OPEN       = wxNewId();
const long T100IDEViewFile::ID_MENUITEM_FILE_CLOSE      = wxNewId();
const long T100IDEViewFile::ID_MENUITEM_FILE_SAVE       = wxNewId();
const long T100IDEViewFile::ID_MENUITEM_FILE_SAVE_AS    = wxNewId();


T100IDEViewFile::T100IDEViewFile(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewFile::~T100IDEViewFile()
{
    //dtor
}

T100BOOL T100IDEViewFile::create_menu()
{
    T100IDEFrameNew*    frame       = T100NULL;
    wxMenuBar*          menubar     = T100NULL;

    frame   = m_view->getFrame();

    if(!frame){
        return T100FALSE;
    }

    menubar = frame->GetMenuBar();

    if(!menubar){
        return T100FALSE;
    }

    wxMenu*         menu    = T100NEW wxMenu();

    menu->Append(wxID_NEW);
    menu->Append(wxID_OPEN);
    menu->AppendSeparator();
    menu->Append(wxID_EXIT);

    m_view->getManager()->getDocManager()->FileHistoryUseMenu(menu);

    menubar->Append(menu, wxGetStockLabel(wxID_FILE));

    return T100TRUE;
}

T100BOOL T100IDEViewFile::create_menu_old()
{
    T100IDEFrameNew*    frame       = T100NULL;
    wxMenuBar*          menubar     = T100NULL;

    frame   = m_view->getFrame();

    if(!frame){
        return T100FALSE;
    }

    menubar = frame->GetMenuBar();

    if(!menubar){
        return T100FALSE;
    }

    wxMenu*         menu    = T100NEW wxMenu();
    wxMenuItem*     item;

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_FILE_NEW,        _("New"),           wxEmptyString, wxITEM_NORMAL);

    menu->Append(item);
    menu->AppendSeparator();

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_FILE_OPEN,       _("Open"),          wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_FILE_CLOSE,      _("Close"),         wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    menu->AppendSeparator();

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_FILE_SAVE,       _("Save"),          wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_FILE_SAVE_AS,    _("Save as…"),      wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menu->AppendSeparator();
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_FILE_DELETE,     _("Remove"),        wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("File"));

    frame->Connect(ID_MENUITEM_FILE_NEW,        wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewFile::OnMenuFileNewSelected);
    frame->Connect(ID_MENUITEM_FILE_DELETE,     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewFile::OnMenuFileDeleteSelected);
    frame->Connect(ID_MENUITEM_FILE_OPEN,       wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewFile::OnMenuFileOpenSelected);
    frame->Connect(ID_MENUITEM_FILE_CLOSE,      wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewFile::OnMenuFileCloseSelected);
    frame->Connect(ID_MENUITEM_FILE_SAVE,       wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewFile::OnMenuFileSaveSelected);
    frame->Connect(ID_MENUITEM_FILE_SAVE_AS,    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewFile::OnMenuFileSaveAsSelected);

    return T100TRUE;
}

T100BOOL T100IDEViewFile::create()
{
    T100BOOL        result;
    T100IDEServe*   serve     = T100NULL;

    serve = dynamic_cast<T100IDEServe*>(m_view->getServe());

    if(!serve){
        //exception
        return T100FALSE;
    }

    if(serve->getFile()->exist()){

    }else{
        result = serve->getFile()->create();
    }


    return result;
}

T100BOOL T100IDEViewFile::open(T100STDSTRING& file)
{
    wxFileDialog dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    wxString path;
    wxString name;
    wxString full;

    path = dialog.GetDirectory();
    name = dialog.GetFilename();

    full = path;
    full += "\\";
    full += name;

    file = full.ToStdString();

    return T100TRUE;
}

T100BOOL T100IDEViewFile::close()
{
    return T100FALSE;
}

void T100IDEViewFile::OnMenuFileNewSelected(wxCommandEvent& event)
{
    T100IDECallbackFile::frame_menu_new();
}

void T100IDEViewFile::OnMenuFileDeleteSelected(wxCommandEvent& event)
{
    T100IDECallbackFile::frame_menu_delete();
}

void T100IDEViewFile::OnMenuFileOpenSelected(wxCommandEvent& event)
{
    T100IDECallbackFile::frame_menu_open();
}

void T100IDEViewFile::OnMenuFileCloseSelected(wxCommandEvent& event)
{
    T100IDECallbackFile::frame_menu_close();
}

void T100IDEViewFile::OnMenuFileSaveSelected(wxCommandEvent& event)
{
    T100IDECallbackFile::frame_menu_save();
}

void T100IDEViewFile::OnMenuFileSaveAsSelected(wxCommandEvent& event)
{
    T100IDECallbackFile::frame_menu_save_as();
}
