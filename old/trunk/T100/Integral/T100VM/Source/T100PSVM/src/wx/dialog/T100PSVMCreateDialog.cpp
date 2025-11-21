#include "../../../include/wx/dialog/T100PSVMCreateDialog.h"

//(*InternalHeaders(T100PSVMCreateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/msgdlg.h>

//(*IdInit(T100PSVMCreateDialog)
const long T100PSVMCreateDialog::ID_STATICTEXT1 = wxNewId();
const long T100PSVMCreateDialog::ID_FILEPICKERCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PSVMCreateDialog,wxDialog)
	//(*EventTable(T100PSVMCreateDialog)
	//*)
END_EVENT_TABLE()

T100PSVMCreateDialog::T100PSVMCreateDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100PSVMCreateDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PSVMCreateDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;

	Create(parent, id, _("Create"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Firmware:"), wxDefaultPosition, wxSize(70,-1), 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FilePickerCtrlFirmware = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
	FilePickerCtrlFirmware->SetMinSize(wxSize(300,-1));
	BoxSizer2->Add(FilePickerCtrlFirmware, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&T100PSVMCreateDialog::OnFilePickerCtrlFirmwareFileChanged);
	//*)

	BoxSizer1->Add(CreateStdDialogButtonSizer(wxCANCEL | wxAPPLY), 0, wxALL | wxALIGN_RIGHT, 5);
    BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&OnApply);
}

T100PSVMCreateDialog::~T100PSVMCreateDialog()
{
	//(*Destroy(T100PSVMCreateDialog)
	//*)
}

T100STRING T100PSVMCreateDialog::GetValue()
{
    return FilePickerCtrlFirmware->GetPath().ToStdString();
}

void T100PSVMCreateDialog::OnFilePickerCtrlFirmwareFileChanged(wxFileDirPickerEvent& event)
{
}

void T100PSVMCreateDialog::OnApply(wxCommandEvent& event)
{
    if(FilePickerCtrlFirmware->GetPath().empty()){
        wxMessageBox(wxT("Please select a file"), wxT("Error"),
                 wxICON_ERROR | wxOK, this);
        return;
    }
    Close();
    SetReturnCode(wxID_OK);
}
