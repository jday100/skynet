#include "T100MainPanel.h"

#include <wx/settings.h>

#include "T100EditorPack.h"
#include "T100ProjectConfig.h"
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

    T100Editor*         editor  = T100NULL;

    if(pack){
        editor  = pack->GetEditor();
    }
    return editor;
}

T100BOOL T100MainPanel::Open(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100EditorPack*     pack    = T100NEW T100EditorPack(this);
    T100WSTRING         path    = info->GetPath();

    if(pack){
        /*
        pack->GetEditor()->SetFont(wxFont(T100ProjectConfig::T100PROJECT_EDITOR_FONT));
        wxFont      font    = pack->GetEditor()->GetFont();
        font.SetPixelSize(wxSize(100, 100));
        font.SetPointSize(100);
        pack->GetEditor()->SetFont(font);
        pack->GetEditor()->Refresh();
        */

        wxFont      font    = wxSystemSettings::GetFont(wxSystemFont::wxSYS_SYSTEM_FONT);

        font.SetPixelSize(wxSize(100, 100));
        font.SetPointSize(100);
        pack->GetEditor()->SetFont(font);
        pack->GetEditor()->Refresh();

        wxFont TextCtrl1Font(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("MV Boli"),wxFONTENCODING_DEFAULT);
        pack->GetEditor()->SetFont(TextCtrl1Font);
    }else{
        return T100FALSE;
    }

    if(path.empty()){

    }else{
        if(pack->GetEditor()->LoadFile(path)){
            pack->GetEditor()->SetPath(path);
        }else{
            T100SAFE_DELETE(pack);
            return T100FALSE;
        }
    }

    if(AddPage(pack, info->GetLabel(), T100TRUE)){
        m_current                   = pack;
        m_packs[info->GetPath()]    = pack;
    }else{
        T100SAFE_DELETE(pack);
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100MainPanel::Close(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100Pack*       pack    = m_packs[info->GetPath()];

    if(!pack){
        return T100FALSE;
    }

    if(DeletePage(pack->GetIndex())){

    }else{
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100MainPanel::Save()
{
    if(m_current){

    }else{
        return T100FALSE;
    }

    T100Editor*     editor      = T100NULL;

    editor  = GetCurrentEditor();

    if(editor){

    }else{
        return T100FALSE;
    }

    editor->SaveFile(editor->GetPath());

    return T100TRUE;
}

T100BOOL T100MainPanel::SaveAll()
{

}

T100BOOL T100MainPanel::Clear()
{
    m_packs.clear();
    return DeleteAllPages();
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
    T100Pack*       pack        = T100NULL;

    pack    = dynamic_cast<T100Pack*>(GetCurrentPage());

    if(pack){

    }else{
        m_current   = T100NULL;
    }

    T100ProjectInvoking::OnPageClosed(pack);
}
