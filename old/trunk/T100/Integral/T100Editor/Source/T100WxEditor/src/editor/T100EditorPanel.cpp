#include "../../include/editor/T100EditorPanel.h"

//(*InternalHeaders(T100EditorPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100EditorPanel)
//*)

BEGIN_EVENT_TABLE(T100EditorPanel,wxPanel)
	//(*EventTable(T100EditorPanel)
	//*)
END_EVENT_TABLE()

T100EditorPanel::T100EditorPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
	init();
}

void T100EditorPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100EditorPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

T100EditorPanel::~T100EditorPanel()
{
	//(*Destroy(T100EditorPanel)
	//*)
	uninit();
}

T100VOID T100EditorPanel::init()
{
    wxBoxSizer*         sizer;

    sizer   = T100NEW wxBoxSizer(wxVERTICAL);

    m_styledTextCtrl    = T100NEW wxStyledTextCtrl(this);

    sizer->Add(m_styledTextCtrl, 1, wxALL | wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100EditorPanel::uninit()
{
    T100SAFE_DELETE(m_styledTextCtrl)
}

