#include "T100DiagramInvoking.h"

#include "T100Thread.h"
#include "T100DiagramSkeletal.h"

T100DiagramSkeletal*        T100DiagramInvoking::m_skeletal                     = T100NULL;

T100DiagramInvoking::T100DiagramInvoking()
{
    //ctor
}

T100DiagramInvoking::~T100DiagramInvoking()
{
    //dtor
}

T100VOID T100DiagramInvoking::Init(T100DiagramFrame* frame)
{
    m_skeletal      = T100NEW T100DiagramSkeletal();
    m_skeletal->Create(frame);
}

T100VOID T100DiagramInvoking::Uninit()
{
    m_skeletal->Destroy();
    T100SAFE_DELETE(m_skeletal);
}

T100VOID T100DiagramInvoking::OnFileCreate()
{
    m_skeletal->OnFileCreate();
}

T100VOID T100DiagramInvoking::OnFileOpen()
{
    m_skeletal->OnFileOpen();
}

T100VOID T100DiagramInvoking::OnFileClose()
{
    m_skeletal->OnFileClose();
}

T100VOID T100DiagramInvoking::OnFileSave()
{
    m_skeletal->OnFileSave();
}

T100VOID T100DiagramInvoking::OnFileSaveAs()
{
    m_skeletal->OnFileSaveAs();
}

T100VOID T100DiagramInvoking::OnFileQuit()
{
    m_skeletal->OnFileQuit();
}

T100VOID T100DiagramInvoking::OnEditUndo()
{
    m_skeletal->OnEditUndo();
}

T100VOID T100DiagramInvoking::OnEditRedo()
{
    m_skeletal->OnEditRedo();
}

T100VOID T100DiagramInvoking::OnEditCut()
{
    m_skeletal->OnEditCut();
}

T100VOID T100DiagramInvoking::OnEditCopy()
{
    m_skeletal->OnEditCopy();
}

T100VOID T100DiagramInvoking::OnEditPaste()
{
    m_skeletal->OnEditPaste();
}

T100VOID T100DiagramInvoking::OnViewManager(T100BOOL flag)
{
    m_skeletal->OnViewManager(flag);
}

T100VOID T100DiagramInvoking::OnViewProperty(T100BOOL flag)
{
    m_skeletal->OnViewProperty(flag);
}

T100VOID T100DiagramInvoking::OnSearchFind()
{
    m_skeletal->OnSearchFind();
}

T100VOID T100DiagramInvoking::OnDevelopImport()
{
    m_skeletal->OnDevelopImport();
}

T100VOID T100DiagramInvoking::OnSetupConfig()
{
    m_skeletal->OnSetupConfig();
}

T100VOID T100DiagramInvoking::OnHelpAbout()
{
    m_skeletal->OnHelpAbout();
}

T100VOID T100DiagramInvoking::OnAuiPaneClose(wxAuiPaneInfo* info)
{
    m_skeletal->OnAuiPaneClose(info);
}

T100VOID T100DiagramInvoking::OnItemSelect(T100UINT index)
{
    m_skeletal->OnItemSelect(index);
}

T100VOID T100DiagramInvoking::OnItemAppend()
{
    m_skeletal->OnItemAppend();
}

T100VOID T100DiagramInvoking::OnTieSelect(T100UINT index)
{
    m_skeletal->OnTieSelect(index);
}

T100VOID T100DiagramInvoking::OnTieStart(wxPoint& value)
{
    m_skeletal->OnTieStart(value);
}

T100VOID T100DiagramInvoking::OnTieEnd(wxPoint& value)
{
    m_skeletal->OnTieEnd(value);
}

T100VOID T100DiagramInvoking::OnSelect(T100INT x, T100INT y)
{
    m_skeletal->OnSelect(x, y);
}

T100VOID T100DiagramInvoking::OnModified()
{
    m_skeletal->OnModified();
}

T100VOID T100DiagramInvoking::OnMouseDClick(T100INT x, T100INT y)
{
    m_skeletal->OnMouseDClick(x, y);
}

T100VOID T100DiagramInvoking::OnCanvasState(T100STRING value)
{
    m_skeletal->OnCanvasState(value);
}

T100VOID T100DiagramInvoking::OnCanvasPosition(T100STRING value)
{
    m_skeletal->OnCanvasPosition(value);
}

T100VOID T100DiagramInvoking::OnSourceImport(T100SourceImportInfo* info)
{
    //m_skeletal->OnSourceImport(info);
    T100Thread      thread(&T100DiagramSkeletal::OnSourceImport, m_skeletal, info);

    thread.Detach();
}
