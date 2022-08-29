#include "../../include/view/T100HardwareDialog.h"

//(*InternalHeaders(T100HardwareDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100HardwareDialog)
const long T100HardwareDialog::ID_LISTVIEW1 = wxNewId();
const long T100HardwareDialog::ID_BUTTON1 = wxNewId();
const long T100HardwareDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100HardwareDialog,wxDialog)
	//(*EventTable(T100HardwareDialog)
	//*)
END_EVENT_TABLE()

T100HardwareDialog::T100HardwareDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100HardwareDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100HardwareDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,300));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer3, 1, wxALL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();
	//*)

}

T100HardwareDialog::~T100HardwareDialog()
{
	//(*Destroy(T100HardwareDialog)
	//*)
}

