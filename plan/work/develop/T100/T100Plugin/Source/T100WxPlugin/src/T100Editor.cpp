#include "T100Editor.h"

#include "main.h"
#include <wx/menu.h>
#include <wx/frame.h>
#include "T100Actuator.h"

#include <wx/msgdlg.h>

T100Editor::T100Editor()
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

void T100Editor::Create(wxFrame* frame)
{
    m_frame         = frame;

    long    id      = wxNewId();

    wxMenuItem*     file    = new wxMenuItem(nullptr, id, L"New");

    frame->GetMenuBar()->GetMenu(0)->Insert(0, file);

    frame->Connect(id, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100Actuator::OnFileNew, nullptr, g_actuator);
}

void T100Editor::Open()
{
    //wxMessageBox("Ok");

    if(m_panel){
        return;
    }

    m_panel = new T100EditorPanel(m_frame);
    m_panel->Show();
}
