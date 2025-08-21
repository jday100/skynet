#include "T100MainPanel.h"

#include "T100EditorPack.h"
#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100MainPanel, wxAuiNotebook)
    EVT_AUINOTEBOOK_PAGE_CHANGED(wxID_ANY, OnPageChanged)
    EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, OnPageClosing)
    EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, OnPageClosed)
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

T100Editor* T100MainPanel::GetCurrentEditor()
{
    T100EditorPack*     pack    = dynamic_cast<T100EditorPack*>(m_current);

    T100Editor*         result  = T100NULL;

    if(pack){
        result  = pack->GetEditor();
    }

    return result;
}

T100VOID T100MainPanel::Create(T100FileInfo* info)
{
    T100EditorPack*     pack    = T100NEW T100EditorPack(this);

    T100WSTRING         path    = info->GetPath();

    if(!path.empty()){
        pack->GetEditor()->LoadFile(path);
        pack->GetEditor()->SetPath(path);
    }

    AddPage(pack, info->GetFileName());

    m_current   = pack;
}

T100VOID T100MainPanel::Clear()
{
    wxAuiNotebook::DeleteAllPages();
}

T100VOID T100MainPanel::Save()
{
    T100BOOL        result      = T100FALSE;

    if(m_current){
        result  = GetCurrentEditor()->SaveFile(GetCurrentEditor()->GetPath());
    }
}

T100VOID T100MainPanel::OnPageChanged(wxAuiNotebookEvent& event)
{
    T100EditorPack*     pack        = T100NULL;

    pack    = dynamic_cast<T100Pack*>(GetCurrentPage());

    m_current   = pack;

    T100ProjectInvoking::OnPageChanged();
}

T100VOID T100MainPanel::OnPageClosing(wxAuiNotebookEvent& event)
{
    T100Pack*       pack        = T100NULL;

    pack    = dynamic_cast<T100Pack*>(GetCurrentPage());

    T100ProjectInvoking::OnPageClosing(pack);
}

T100VOID T100MainPanel::OnPageClosed(wxAuiNotebookEvent& event)
{
    T100ProjectInvoking::OnPageClosed();
}
