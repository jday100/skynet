#include "T100CreateProgressDialog.h"

//(*InternalHeaders(T100CreateProgressDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)


//(*IdInit(T100CreateProgressDialog)
const long T100CreateProgressDialog::ID_GAUGE1 = wxNewId();
//*)

const long T100CreateProgressDialog::ID_THREAD_PROGRESS = wxNewId();

BEGIN_EVENT_TABLE(T100CreateProgressDialog,wxDialog)
	//(*EventTable(T100CreateProgressDialog)
	//*)
	EVT_THREAD(ID_THREAD_PROGRESS, T100CreateProgressDialog::OnThreadProgress)
END_EVENT_TABLE()

T100CreateProgressDialog::T100CreateProgressDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100CreateProgressDialog)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(1275,74));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Gauge1 = new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(1265,50), 0, wxDefaultValidator, _T("ID_GAUGE1"));
	BoxSizer1->Add(Gauge1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&T100CreateProgressDialog::OnInit);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100CreateProgressDialog::OnClose);
	//*)

	BoxSizer1->Add(CreateStdDialogButtonSizer(wxCANCEL),
                   wxSizerFlags().Right().Border());

    Connect(wxID_CANCEL,    wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100CreateProgressDialog::OnButtonCancelClick);

    create();
}

T100CreateProgressDialog::~T100CreateProgressDialog()
{
	//(*Destroy(T100CreateProgressDialog)
	//*)

	destroy();
}

T100VOID T100CreateProgressDialog::create()
{

}

T100VOID T100CreateProgressDialog::destroy()
{
}

void T100CreateProgressDialog::OnInit(wxInitDialogEvent& event)
{
    m_thread        = T100NEW T100WXCreateThread();

    m_thread->m_filename  = m_filename;
    m_thread->m_length    = m_length;
    m_thread->m_type      = m_type;
    m_thread->m_storage   = m_storage;

    m_thread->setValue(this);
    m_thread->setCallback((T100THREAD_CALLBACK)&T100CreateProgressDialog::progress);
    m_thread->start();
}

void T100CreateProgressDialog::OnClose(wxCloseEvent& event)
{
    m_thread->wait();
    Destroy();
}

void T100CreateProgressDialog::OnButtonCancelClick(wxCommandEvent& event)
{

}

void T100CreateProgressDialog::OnThreadProgress(wxThreadEvent& event)
{
    T100INT32   value;

    value   = event.GetInt();

    Gauge1->SetValue(value);
    Gauge1->Refresh();

    if(value >= 100){
        //m_thread->wait();
        //Destroy();
    }
}

void T100CreateProgressDialog::progress(T100VOID* frame, T100BYTE range)
{
    wxThreadEvent       event(wxEVT_THREAD, T100CreateProgressDialog::ID_THREAD_PROGRESS);

    event.SetInt(range);

    wxQueueEvent((wxEvtHandler*)frame, event.Clone());
}
