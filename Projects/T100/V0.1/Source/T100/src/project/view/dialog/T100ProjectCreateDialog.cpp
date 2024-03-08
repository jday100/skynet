#include "../../../../include/project/view/dialog/T100ProjectCreateDialog.h"

//(*InternalHeaders(T100ProjectCreateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100ProjectCommon.h"
#include "T100ProjectCallback.h"
#include "T100ProjectInfo.h"
#include "T100WxProjectCreateTask.h"

//(*IdInit(T100ProjectCreateDialog)
const long T100ProjectCreateDialog::ID_STATICTEXT1 = wxNewId();
const long T100ProjectCreateDialog::ID_TEXTCTRL1 = wxNewId();
const long T100ProjectCreateDialog::ID_STATICTEXT2 = wxNewId();
const long T100ProjectCreateDialog::ID_CHOICE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100ProjectCreateDialog,wxDialog)
	//(*EventTable(T100ProjectCreateDialog)
	//*)
END_EVENT_TABLE()

T100ProjectCreateDialog::T100ProjectCreateDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100ProjectCreateDialog)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_LEFT, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	BoxSizer1->Add(Choice1, 1, wxALL|wxALIGN_LEFT, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)

	BoxSizer1->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCANCEL),
                   wxSizerFlags().Right().Border());

    BoxSizer1->Fit(this);

    Connect(wxID_APPLY,     wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100ProjectCreateDialog::OnButtonApplyClick);

    create();
}

T100ProjectCreateDialog::~T100ProjectCreateDialog()
{
	//(*Destroy(T100ProjectCreateDialog)
	//*)

	destroy();
}

T100VOID T100ProjectCreateDialog::create()
{
    wxArrayString       options;

    options.Add(L"Empty Project");
    options.Add(L"C Project");
    options.Add(L"C++ Project");
    options.Add(L"NodeJS Project");

    Choice1->Append(options);
}

T100VOID T100ProjectCreateDialog::destroy()
{

}

void T100ProjectCreateDialog::OnButtonApplyClick(wxCommandEvent& event)
{
    T100BOOL            result;
    T100PROJECT::T100ProjectInfo*       info            = T100NULL;

    info    = T100NEW T100PROJECT::T100ProjectInfo();
    info->setName(TextCtrl1->GetValue().ToStdWstring());

    switch(Choice1->GetSelection()){
    case 0:
        {
            info->setType(T100PROJECT::T100PROJECT_TYPE_EMPTY);
        }
        break;
    }

    T100PROJECT::T100WxProjectCreateTask*    task            = T100NEW T100PROJECT::T100WxProjectCreateTask();

    task->setProjectInfo(info);
    task->run();

    /*
    T100BOOL            result;
    T100PROJECT::T100ProjectInfo*       info            = T100NULL;

    info    = T100NEW T100PROJECT::T100ProjectInfo();
    info->setName(TextCtrl1->GetValue().ToStdWstring());

    result  = T100PROJECT::T100ProjectCallback::dialog_project_create_apply(info);

    if(result){
        Close();
    }else{

    }
    */
}

