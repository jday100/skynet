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

const T100WSTRING T100MainPanel::GetCurrentLabel()
{
    if(m_current){
        return m_current->GetLabel();
    }
    return L"";
}

const T100WSTRING T100MainPanel::GetCurrentFilePath()
{
    if(m_current){
        return m_current->GetPath();
    }
    return L"";
}

T100Editor* T100MainPanel::GetCurrentEditor()
{
    T100Editor*         editor      = T100NULL;
    T100EditorPack*     pack        = dynamic_cast<T100EditorPack*>(m_current);

    if(pack){
        editor  = pack->GetEditor();
    }
    return editor;
}

T100VOID T100MainPanel::UpdateCurrentLabel()
{
    T100WSTRING     label;

    if(m_current){
        T100EditorPack*     editor      = T100NULL;
        T100INT             index       = GetPageIndex(m_current);

        if(index < 0){
            return;
        }

        editor  = dynamic_cast<T100EditorPack*>(m_current);
        if(editor){
            if(editor->GetEditor()->GetModify()){
                label   = L"*" + m_current->GetLabel();
            }else{
                label   = m_current->GetLabel();
            }

            SetPageText(index, label);
        }
    }
}

T100BOOL T100MainPanel::Select(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100Pack*       pack         = T100NULL;

    pack    = m_packs[info->GetPath()];

    if(pack){

    }else{
        return T100FALSE;
    }

    T100INT         index       = GetPageIndex(pack);

    if(index >= 0){

    }else{
        return T100FALSE;
    }

    SetSelection(index);
    return T100TRUE;
}

T100BOOL T100MainPanel::Open(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WSTRING         path        = info->GetPath();
    T100EditorPack*     pack        = T100NEW T100EditorPack(this);

    if(pack){
        pack->SetLabel(info->GetLabel());
        pack->SetPath(path);
    }else{
        return T100FALSE;
    }

    if(AddPage(pack, info->GetLabel(), T100TRUE)){
        T100INT     index       = GetPageIndex(pack);
        m_current                       = pack;
        m_packs[info->GetPath()]        = pack;
    }else{
        T100SAFE_DELETE(pack);
        return T100FALSE;
    }

    if(path.empty()){

    }else{
        pack->GetEditor()->Lock();
        if(pack->GetEditor()->LoadFile(path)){
            pack->GetEditor()->Unlock();
            pack->GetEditor()->SetPath(path);
        }else{
            T100SAFE_DELETE(pack);
            return T100FALSE;
        }
    }

    return T100TRUE;
}

T100BOOL T100MainPanel::Close(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100Pack*       pack         = T100NULL;

    pack    = m_packs[info->GetPath()];

    if(pack){

    }else{
        return T100FALSE;
    }

    T100INT         index       = GetPageIndex(pack);

    if(index >= 0){

    }else{
        return T100FALSE;
    }

    return DeletePage(index);
}

T100BOOL T100MainPanel::Save()
{
    if(!m_current){
        return T100FALSE;
    }

    T100Editor*     editor      = T100NULL;

    editor  = GetCurrentEditor();

    if(!editor){
        return T100FALSE;
    }

    if(editor->SaveFile(editor->GetPath())){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100MainPanel::SaveAs(T100WxFileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    if(!m_current){
        return T100FALSE;
    }

    T100Editor*     editor      = T100NULL;

    editor  = GetCurrentEditor();

    if(!editor){
        return T100FALSE;
    }

    if(editor->SaveFile(info->GetPath())){
        editor->SetLabel(info->GetLabel());
        editor->SetPath(info->GetPath());
        m_current->SetLabel(info->GetLabel());
        m_current->SetPath(info->GetPath());
        UpdateCurrentLabel();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100MainPanel::Clear()
{
    m_packs.clear();
    return DeleteAllPages();
}

T100VOID T100MainPanel::OnPageChanged(wxAuiNotebookEvent& event)
{
    T100Pack*       pack        = T100NULL;

    pack    = dynamic_cast<T100Pack*>(GetCurrentPage());

    m_current   = pack;

    T100ProjectInvoking::OnMainPanelPageChanged();
}

T100VOID T100MainPanel::OnPageClosing(wxAuiNotebookEvent& event)
{
    T100Pack*       pack        = T100NULL;

    pack    = dynamic_cast<T100Pack*>(GetCurrentPage());

    T100ProjectInvoking::OnMainPanelPageClosing(pack);
}

T100VOID T100MainPanel::OnPageClosed(wxAuiNotebookEvent& event)
{
    T100Pack*       pack        = T100NULL;

    pack    = dynamic_cast<T100Pack*>(GetCurrentPage());

    if(pack){

    }else{
        m_current   = T100NULL;
    }

    T100ProjectInvoking::OnMainPanelPageClosed(pack);
}
