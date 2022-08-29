#include "T100DiskDialog.h"

#include <wx/sizer.h>
#include <wx/stattext.h>


T100DiskDialog::T100DiskDialog(wxWindow *parent, wxWindowID id, const wxString& title,
             const wxPoint& pos, const wxSize& size, long style, const wxString& name)
    :wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    create();
}

T100DiskDialog::~T100DiskDialog()
{
    //dtor
    destroy();
}

T100VOID T100DiskDialog::create()
{
wxSizer * const sizerTop = new wxBoxSizer(wxVERTICAL);

    // this sizer allows to configure the messages shown in the message box
    wxSizer * const
        sizerMsgs = new wxStaticBoxSizer(wxVERTICAL, this, "&Messages");
    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Title:"));
    //m_textTitle = new wxTextCtrl(this, wxID_ANY, "Test Message Box");
    //sizerMsgs->Add(m_textTitle, wxSizerFlags().Expand().Border(wxBOTTOM));

    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Main message:"));
    //m_textMsg = new wxTextCtrl(this, wxID_ANY, "Hello from a box!",
                               //wxDefaultPosition, wxDefaultSize,
                               //wxTE_MULTILINE);
    //sizerMsgs->Add(m_textMsg, wxSizerFlags(1).Expand().Border(wxBOTTOM));

    sizerMsgs->Add(new wxStaticText(this, wxID_ANY, "&Extended message:"));
    //m_textExtMsg = new wxTextCtrl(this, wxID_ANY, "",
                                  //wxDefaultPosition, wxDefaultSize,
                                  //wxTE_MULTILINE);
    //sizerMsgs->Add(m_textExtMsg, wxSizerFlags(1).Expand());

    sizerTop->Add(sizerMsgs, wxSizerFlags(1).Expand().Border());

    // if a derived class provides more message configurations, add these.
    //AddAdditionalTextOptions(sizerTop);

    // this one is for configuring the buttons
    wxSizer * const
    sizerBtnsBox = new wxStaticBoxSizer(wxVERTICAL, this, "&Buttons");

    wxFlexGridSizer * const sizerBtns = new wxFlexGridSizer(2, 5, 5);
    sizerBtns->AddGrowableCol(1);

    sizerBtns->Add(new wxStaticText(this, wxID_ANY, "Button(s)"));
    sizerBtns->Add(new wxStaticText(this, wxID_ANY, "Custom label"));



    sizerBtnsBox->Add(sizerBtns, wxSizerFlags(1).Expand());
    sizerTop->Add(sizerBtnsBox, wxSizerFlags().Expand().Border());


    // icon choice
    const wxString icons[] =
    {
        "&Not specified",
        "E&xplicitly none",
        "&Information icon",
        "&Question icon",
        "&Warning icon",
        "&Error icon",
        "A&uth needed icon"
    };



    // miscellaneous other stuff
    wxSizer * const
        sizerFlags = new wxStaticBoxSizer(wxHORIZONTAL, this, "&Other flags");






    sizerTop->Add(sizerFlags, wxSizerFlags().Expand().Border());

    // finally buttons to show the resulting message box and close this dialog
    sizerTop->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCLOSE),
                  wxSizerFlags().Right().Border());

    SetSizerAndFit(sizerTop);

}

T100VOID T100DiskDialog::destroy()
{

}
