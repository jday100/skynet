#include "T100MainPanel.h"

#include "T100Editor.h"

BEGIN_EVENT_TABLE(T100MainPanel, wxAuiNotebook)
    EVT_AUINOTEBOOK_PAGE_CHANGED(wxID_ANY, OnPageChanged)
END_EVENT_TABLE()

T100MainPanel::T100MainPanel(wxWindow* parent,
                  wxWindowID id,
                  const wxPoint& pos,
                  const wxSize& size,
                  long style) :
    wxAuiNotebook(parent, id, pos, size, style)
{
    //ctor
}

T100MainPanel::~T100MainPanel()
{
    //dtor
}

T100VOID T100MainPanel::Create(T100FileInfo* info)
{
    T100Editor*     editor      = T100NEW T100Editor(this);

    T100WSTRING     path        = info->GetPath();

    if(!path.empty()){
        editor->LoadFile(info->GetPath());
    }

    AddPage(editor, info->GetFileName());

    m_current   = editor;
}

T100VOID T100MainPanel::Clear()
{
    wxAuiNotebook::DeleteAllPages();
}

T100VOID T100MainPanel::Save()
{
    if(m_current){
        m_current->SaveFile();
    }
}

T100VOID T100MainPanel::OnPageChanged(wxAuiNotebookEvent& event)
{
    T100INT     index;

    index   = event.GetSelection();

    if(wxNOT_FOUND == index){

    }else{
        m_current   = dynamic_cast<T100Editor*>(GetPage(index));
    }
}
