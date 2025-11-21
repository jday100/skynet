#include "../../include/wx/T100SourceImportDialog.h"

//(*InternalHeaders(T100SourceImportDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100SourceImportInfo.h"
#include "T100DiagramInvoking.h"

//(*IdInit(T100SourceImportDialog)
const long T100SourceImportDialog::ID_STATICTEXT1 = wxNewId();
const long T100SourceImportDialog::ID_DIRPICKERCTRL1 = wxNewId();
const long T100SourceImportDialog::ID_STATICTEXT2 = wxNewId();
const long T100SourceImportDialog::ID_DIRPICKERCTRL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100SourceImportDialog,wxDialog)
	//(*EventTable(T100SourceImportDialog)
	//*)
END_EVENT_TABLE()

T100SourceImportDialog::T100SourceImportDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100SourceImportDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100SourceImportDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("GCC:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DirPickerCtrl1 = new wxDirPickerCtrl(this, ID_DIRPICKERCTRL1, wxEmptyString, wxEmptyString, wxDefaultPosition, wxSize(300,-1), wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_DIRPICKERCTRL1"));
	BoxSizer2->Add(DirPickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Source:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DirPickerCtrl2 = new wxDirPickerCtrl(this, ID_DIRPICKERCTRL2, wxEmptyString, wxEmptyString, wxDefaultPosition, wxSize(300,-1), wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_DIRPICKERCTRL2"));
	BoxSizer3->Add(DirPickerCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();
	//*)

	BoxSizer1->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCANCEL), 0, wxALL | wxALIGN_RIGHT, 5);

	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&OnApply);
}

T100SourceImportDialog::~T100SourceImportDialog()
{
	//(*Destroy(T100SourceImportDialog)
	//*)
}

T100VOID T100SourceImportDialog::OnApply(wxCommandEvent& event)
{
    if(T100TRUE){
        T100SourceImportInfo*       info    = T100NEW T100SourceImportInfo();

        info->Compiler   = DirPickerCtrl1->GetPath().ToStdWstring();
        info->Source     = DirPickerCtrl2->GetPath().ToStdWstring();

        T100DiagramInvoking::OnSourceImport(info);
        Close();
    }
}
