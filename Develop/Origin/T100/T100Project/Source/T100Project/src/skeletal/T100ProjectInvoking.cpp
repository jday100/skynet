#include "T100ProjectInvoking.h"

#include "T100ProjectSkeletal.h"

T100ProjectSkeletal*            T100ProjectInvoking::m_skeletal                 = T100NULL;

T100ProjectInvoking::T100ProjectInvoking()
{
    //ctor
}

T100ProjectInvoking::~T100ProjectInvoking()
{
    //dtor
}

T100VOID T100ProjectInvoking::Init(T100ProjectFrame* frame)
{
    m_skeletal      = T100NEW T100ProjectSkeletal();
    m_skeletal->Create(frame);
}

T100VOID T100ProjectInvoking::Uninit()
{
    m_skeletal->Destroy();
    T100SAFE_DELETE(m_skeletal);
}

T100VOID T100ProjectInvoking::OnWorkSpaceNew()
{
    m_skeletal->OnWorkSpaceNew();
}

T100VOID T100ProjectInvoking::OnWorkSpaceOpen()
{
    m_skeletal->OnWorkSpaceOpen();
}

T100VOID T100ProjectInvoking::OnWorkSpaceClose()
{
    m_skeletal->OnWorkSpaceClose();
}

T100VOID T100ProjectInvoking::OnWorkSpaceSave()
{
    m_skeletal->OnWorkSpaceSave();
}

T100VOID T100ProjectInvoking::OnWorkSpaceSaveAs()
{
    m_skeletal->OnWorkSpaceSaveAs();
}

T100VOID T100ProjectInvoking::OnProjectNew()
{
    m_skeletal->OnProjectNew();
}

T100VOID T100ProjectInvoking::OnProjectOpen()
{
    m_skeletal->OnProjectOpen();
}

T100VOID T100ProjectInvoking::OnProjectClose()
{
    m_skeletal->OnProjectClose();
}

T100VOID T100ProjectInvoking::OnProjectSave()
{
    m_skeletal->OnProjectSave();
}

T100VOID T100ProjectInvoking::OnProjectSaveAs()
{
    m_skeletal->OnProjectSaveAs();
}

T100VOID T100ProjectInvoking::OnFileNew()
{
    m_skeletal->OnFileNew();
}

T100VOID T100ProjectInvoking::OnFileOpen()
{
    m_skeletal->OnFileOpen();
}

T100VOID T100ProjectInvoking::OnFileClose()
{
    m_skeletal->OnFileClose();
}

T100VOID T100ProjectInvoking::OnFileSave()
{
    m_skeletal->OnFileSave();
}

T100VOID T100ProjectInvoking::OnFileSaveAs()
{
    m_skeletal->OnFileSaveAs();
}

T100VOID T100ProjectInvoking::OnEditUndo()
{
    m_skeletal->OnEditUndo();
}

T100VOID T100ProjectInvoking::OnEditRedo()
{
    m_skeletal->OnEditRedo();
}

T100VOID T100ProjectInvoking::OnEditCut()
{
    m_skeletal->OnEditCut();
}

T100VOID T100ProjectInvoking::OnEditCopy()
{
    m_skeletal->OnEditCopy();
}

T100VOID T100ProjectInvoking::OnEditPaste()
{
    m_skeletal->OnEditPaste();
}

T100VOID T100ProjectInvoking::OnSearchFind()
{
    m_skeletal->OnSearchFind();
}

T100VOID T100ProjectInvoking::OnSearchReplace()
{
    m_skeletal->OnSearchReplace();
}

T100VOID T100ProjectInvoking::OnCompileBuild()
{
    m_skeletal->OnCompileBuild();
}

T100VOID T100ProjectInvoking::OnSetupEditor()
{
    m_skeletal->OnSetupEditor();
}

T100VOID T100ProjectInvoking::OnSetupCompiler()
{
    m_skeletal->OnSetupCompiler();
}

T100VOID T100ProjectInvoking::OnHelpAbout()
{
    m_skeletal->OnHelpAbout();
}

T100VOID T100ProjectInvoking::OnResize()
{
    m_skeletal->OnResize();
}

T100VOID T100ProjectInvoking::OnQuit()
{

}

T100VOID T100ProjectInvoking::OnFolderNew()
{
    m_skeletal->OnFolderNew();
}

T100VOID T100ProjectInvoking::OnFolderSelected()
{
    m_skeletal->OnFolderSelected();
}

T100VOID T100ProjectInvoking::OnFileOpen(T100FileData* data)
{
    m_skeletal->OnFileOpen(data);
}

T100VOID T100ProjectInvoking::OnFolderOpen(T100FolderData* data)
{
    m_skeletal->OnFolderOpen(data);
}

T100VOID T100ProjectInvoking::OnProjectSelected()
{
    m_skeletal->OnProjectSelected();
}

T100VOID T100ProjectInvoking::OnPageClosed()
{
    m_skeletal->OnPageClosed();
}

T100VOID T100ProjectInvoking::OnItemExpanding()
{
    m_skeletal->OnItemExpanding();
}

T100VOID T100ProjectInvoking::OnModified()
{
    m_skeletal->OnModified();
}

T100VOID T100ProjectInvoking::OnProjectCreateWizardFinished()
{
    m_skeletal->OnProjectCreateWizardFinished();
}
