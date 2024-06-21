#include "../../../include/editor/view/T100SceneEditorFrame.h"

//(*InternalHeaders(T100SceneEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100SceneEditorFrame)
const long T100SceneEditorFrame::ID_MENUITEM1 = wxNewId();
const long T100SceneEditorFrame::ID_MENUITEM2 = wxNewId();
const long T100SceneEditorFrame::ID_MENUITEM3 = wxNewId();
const long T100SceneEditorFrame::ID_MENUITEM4 = wxNewId();
const long T100SceneEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100SceneEditorFrame,wxFrame)
	//(*EventTable(T100SceneEditorFrame)
	//*)
END_EVENT_TABLE()

T100SceneEditorFrame::T100SceneEditorFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100SceneEditorFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100SceneEditorFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("New"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuItem2 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Load"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem2);
	MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM3, _("Save"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem3);
	Menu1->AppendSeparator();
	MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Close"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem4);
	MenuBar1->Append(Menu1, _("File"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	//*)

	TurnOn();
}

T100SceneEditorFrame::~T100SceneEditorFrame()
{
	//(*Destroy(T100SceneEditorFrame)
	//*)

	TurnOff();
}

T100VOID T100SceneEditorFrame::TurnOn()
{

}

T100VOID T100SceneEditorFrame::TurnOff()
{
    AuiManager1->UnInit();
}

T100VOID T100SceneEditorFrame::SetRender(T100WxRender* render)
{
    m_render    = render;
}

T100WxRender* T100SceneEditorFrame::GetRender()
{
    return m_render;
}
