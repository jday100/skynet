#include "T100Editor.h"

#include <wx/frame.h>

T100Editor::T100Editor()
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

T100VOID T100Editor::SetFrame(wxFrame* frame)
{
    m_frame     = frame;
}

T100BOOL T100Editor::Create()
{
    if(m_panel){
        return T100FALSE;
    }

    m_panel     = T100NEW T100EditorPanel(m_frame);

    m_frame->Maximize();
    m_panel->Show();

    return T100TRUE;
}
