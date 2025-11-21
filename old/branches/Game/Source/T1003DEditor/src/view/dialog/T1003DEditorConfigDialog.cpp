#include "../../../include/view/dialog/T1003DEditorConfigDialog.h"

//(*InternalHeaders(T1003DEditorConfigDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T1003DEditorConfigDialog)
const long T1003DEditorConfigDialog::ID_COLOURPICKERCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T1003DEditorConfigDialog,wxDialog)
	//(*EventTable(T1003DEditorConfigDialog)
	//*)
END_EVENT_TABLE()

T1003DEditorConfigDialog::T1003DEditorConfigDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T1003DEditorConfigDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T1003DEditorConfigDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(184,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));

	Connect(ID_COLOURPICKERCTRL1,wxEVT_COMMAND_COLOURPICKER_CHANGED,(wxObjectEventFunction)&T1003DEditorConfigDialog::OnColourPickerCtrl1ColourChanged);
	//*)
}

T1003DEditorConfigDialog::~T1003DEditorConfigDialog()
{
	//(*Destroy(T1003DEditorConfigDialog)
	//*)
}


void T1003DEditorConfigDialog::OnColourPickerCtrl1ColourChanged(wxColourPickerEvent& event)
{
}
