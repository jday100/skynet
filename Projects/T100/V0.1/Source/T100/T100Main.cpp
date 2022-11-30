/***************************************************************
 * Name:      T100Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (2020-2023)
 * License:
 **************************************************************/

#include "T100Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <thread>
#include "T100String.h"
#include "T100ThisAppSetup.h"
#include "T100FontView.h"
#include "T100FontFrame.h"
#include "T100FontPanel.h"

#include "T100VPCView.h"


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(T100Frame)
const long T100Frame::idMenuQuit = wxNewId();
const long T100Frame::idMenuAbout = wxNewId();
const long T100Frame::ID_STATUSBAR1 = wxNewId();
//*)

const long T100Frame::ID_THREAD_FONT = wxNewId();
const long T100Frame::ID_THREAD_VPC = wxNewId();

BEGIN_EVENT_TABLE(T100Frame,wxFrame)
    //(*EventTable(T100Frame)
    //*)
    EVT_THREAD(ID_THREAD_FONT, T100Frame::OnThreadFont)
    EVT_THREAD(ID_THREAD_VPC, T100Frame::OnThreadVPC)

END_EVENT_TABLE()

T100Frame::T100Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100Frame::OnAbout);
    //*)
}

T100Frame::~T100Frame()
{
    //(*Destroy(T100Frame)
    //*)
}

void T100Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100Frame::OnThreadFont(wxThreadEvent& event)
{
    T100BOOL        result          = T100TRUE;
    T100STRING      file;
    T100INT         index;

    T100FontBuilder::T100FontPanel*         panel           = T100NULL;

    m_builder   = T100NEW T100FontBuilder::T100FontBuilder();
    m_builder->show();

    file    = T100ThisAppSetup::getTestStores(L"test_font.fnt");
    panel   = m_builder->getView()->getFrame()->FontPanel;

    panel->setCallback(this, (T100WxWidgets::T100FRAME_CALLBACK)&T100Frame::font_quit);

    index   = panel->FontNameChoice->FindString(L"System");
    if(0 <= index){
        panel->FontNameChoice->SetSelection(index);
        panel->FontNameChoice->SendSelectionChangedEvent(wxEVT_COMMAND_CHOICE_SELECTED);
    }else{
        result = T100FALSE;
    }

    if(result){
        panel->NameCodeRadioButton1->SetValue(T100TRUE);
        wxCommandEvent  code1(wxEVT_COMMAND_RADIOBUTTON_SELECTED, panel->ID_RADIOBUTTON_NAMECODE1);
        panel->NameCodeRadioButton1->GetEventHandler()->ProcessEvent(code1);
        //wxQueueEvent(panel->NameCodeRadioButton1->GetEventHandler(), event.Clone());

        panel->FontSizeComboBox->SetSelection(0);
        panel->FontSizeComboBox->SendSelectionChangedEvent(wxEVT_COMMAND_COMBOBOX_SELECTED);

        panel->CountryListBox->SetSelection(1);
        panel->CountryListBox->SendSelectionChangedEvent(wxEVT_COMMAND_LISTBOX_SELECTED);

        panel->CodeBeginComboBox->SetSelection(0);
        panel->CodeBeginComboBox->SendSelectionChangedEvent(wxEVT_COMMAND_COMBOBOX_SELECTED);

        panel->CodeEndComboBox->SetSelection(0);
        panel->CodeEndComboBox->SendSelectionChangedEvent(wxEVT_COMMAND_COMBOBOX_SELECTED);

        panel->AppendButton->HitTest(0, 0);
        wxCommandEvent  append(wxEVT_COMMAND_BUTTON_CLICKED, panel->ID_BUTTON_APPEND);
        panel->AppendButton->GetEventHandler()->ProcessEvent(append);

        panel->FileComboBox->SetValue(file.to_wstring());
        panel->FileComboBox->SendSelectionChangedEvent(wxEVT_COMMAND_COMBOBOX_SELECTED);

        panel->RunButton->HitTest(0, 0);
        wxCommandEvent  run(wxEVT_COMMAND_BUTTON_CLICKED, panel->ID_BUTTON_RUN);
        panel->RunButton->GetEventHandler()->ProcessEvent(run);
    }
}

void T100Frame::OnThreadVPC(wxThreadEvent& event)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100STRING      file;

    m_vpc   = T100NEW T100VPC::T100VPC();

    m_vpc->getView()->setCallback(this, (T100WxWidgets::T100FRAME_CALLBACK)&T100Frame::vpc_quit);

    //vpc->show();
    m_vpc->run();
}

T100BOOL T100Frame::font_quit(void* d)
{
    m_condition.notify_all();

    if(m_builder){
        m_builder->quit();
    }
}

T100BOOL T100Frame::vpc_quit(void* d)
{
    m_condition.notify_all();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}

T100VOID T100Frame::wait()
{
    std::unique_lock<std::mutex>        locker(m_mutex);
    m_condition.wait(locker);
    locker.unlock();
}

T100WORD T100Frame::getReturn()
{
    if(m_vpc){
        return m_vpc->getReturn();
    }
    return 0;
}
