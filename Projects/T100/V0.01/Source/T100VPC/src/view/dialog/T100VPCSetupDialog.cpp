#include "T100VPCSetupDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>


BEGIN_EVENT_TABLE(T100VPCSetupDialog,wxDialog)

END_EVENT_TABLE()


T100VPCSetupDialog::T100VPCSetupDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
    create();
}

T100VPCSetupDialog::~T100VPCSetupDialog()
{
    //dtor
    destroy();
}

void T100VPCSetupDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);

    wxSizer * const sizerTop = new wxBoxSizer(wxVERTICAL);


    // this sizer allows to configure the messages shown in the message box
    wxSizer * const
        sizerMsgs = new wxStaticBoxSizer(wxVERTICAL, this, "&Messages");
    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Title:"));

    wxTextCtrl* m_textTitle;
    m_textTitle = new wxTextCtrl(this, wxID_ANY, "Test Message Box");
    sizerMsgs->Add(m_textTitle, wxSizerFlags().Expand().Border(wxBOTTOM));


    sizerTop->Add(sizerMsgs, wxSizerFlags(1).Expand().Border());



    // finally buttons to show the resulting message box and close this dialog
    sizerTop->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCLOSE),
                  wxSizerFlags().Right().Border());


    SetSizerAndFit(sizerTop);


    /*
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);

    wxSizer * const sizerTop = new wxBoxSizer(wxVERTICAL);


    // this sizer allows to configure the messages shown in the message box
    wxSizer * const
        sizerMsgs = new wxStaticBoxSizer(wxVERTICAL, this, "&Messages");
    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Title:"));

    wxTextCtrl* m_textTitle;
    m_textTitle = new wxTextCtrl(this, wxID_ANY, "Test Message Box");
    sizerMsgs->Add(m_textTitle, wxSizerFlags().Expand().Border(wxBOTTOM));

    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Main message:"));
    wxTextCtrl* m_textMsg;
    m_textMsg = new wxTextCtrl(this, wxID_ANY, "Hello from a box!",
                               wxDefaultPosition, wxDefaultSize,
                               wxTE_MULTILINE);
    sizerMsgs->Add(m_textMsg, wxSizerFlags(1).Expand().Border(wxBOTTOM));

    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Extended message:"));

    wxTextCtrl* m_textExtMsg;
    m_textExtMsg = new wxTextCtrl(this, wxID_ANY, "",
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTE_MULTILINE);
    sizerMsgs->Add(m_textExtMsg, wxSizerFlags(1).Expand());

    sizerTop->Add(sizerMsgs, wxSizerFlags(1).Expand().Border());


    // this one is for configuring the buttons
    wxSizer * const
    sizerBtnsBox = new wxStaticBoxSizer(wxVERTICAL, this, "&Buttons");

    wxFlexGridSizer * const sizerBtns = new wxFlexGridSizer(2, 5, 5);
    sizerBtns->AddGrowableCol(1);

    sizerBtns->Add(new wxStaticText(this, wxID_ANY, "Button(s)"));
    sizerBtns->Add(new wxStaticText(this, wxID_ANY, "Custom label"));



    sizerBtnsBox->Add(sizerBtns, wxSizerFlags(1).Expand());
    sizerTop->Add(sizerBtnsBox, wxSizerFlags().Expand().Border());




    // miscellaneous other stuff
    wxSizer * const
        sizerFlags = new wxStaticBoxSizer(wxHORIZONTAL, this, "&Other flags");

    wxCheckBox* m_chkCentre;
    m_chkCentre = new wxCheckBox(this, wxID_ANY, "Centre on &parent");
    sizerFlags->Add(m_chkCentre, wxSizerFlags(1).Border());


    sizerTop->Add(sizerFlags, wxSizerFlags().Expand().Border());

    // finally buttons to show the resulting message box and close this dialog
    sizerTop->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCLOSE),
                  wxSizerFlags().Right().Border());


    SetSizerAndFit(sizerTop);
    */
}

T100VOID T100VPCSetupDialog::create()
{
    load();
}

T100VOID T100VPCSetupDialog::destroy()
{
    save();
}

T100BOOL T100VPCSetupDialog::load()
{

}

T100BOOL T100VPCSetupDialog::save()
{

}
