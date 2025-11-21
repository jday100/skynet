#include "T100Actuator.h"

T100Actuator::T100Actuator() :
    wxEvtHandler()
{
    //ctor
}

T100Actuator::~T100Actuator()
{
    //dtor
}

void T100Actuator::Create(wxFrame* frame)
{
    m_editor.Create(frame);
}

void T100Actuator::OnFileNew(wxCommandEvent& event)
{
    m_editor.Open();
}
