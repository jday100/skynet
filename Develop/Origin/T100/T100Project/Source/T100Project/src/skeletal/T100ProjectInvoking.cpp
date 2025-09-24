#include "T100ProjectInvoking.h"

#include "T100ProjectSkeletal.h"

T100ProjectSkeletal*        T100ProjectInvoking::m_skeletal                     = T100NULL;

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
    m_skeletal  = T100NEW T100ProjectSkeletal();
    m_skeletal->Create(frame);
}

T100VOID T100ProjectInvoking::Uninit()
{
    m_skeletal->Destroy();
    T100SAFE_DELETE(m_skeletal);
}

T100VOID T100ProjectInvoking::OnWorkSpaceCreate()
{
    m_skeletal->OnWorkSpaceCreate();
}

T100VOID T100ProjectInvoking::OnWorkSpaceCreateDone(T100WorkSpaceInfo* info)
{
    m_skeletal->OnWorkSpaceCreateDone(info);
}

T100VOID T100ProjectInvoking::OnWorkSpaceRemove()
{
    m_skeletal->OnWorkSpaceRemove();
}

T100VOID T100ProjectInvoking::OnWorkSpaceOpen()
{
    m_skeletal->OnWorkSpaceOpen();
}

T100VOID T100ProjectInvoking::OnWorkSpaceOpenDone()
{
    m_skeletal->OnWorkSpaceOpenDone();
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

T100VOID T100ProjectInvoking::OnWorkSpaceQuit()
{
    m_skeletal->OnWorkSpaceQuit();
}

T100VOID T100ProjectInvoking::OnWorkSpaceMouseRightDown()
{
    m_skeletal->OnWorkSpaceMouseRightDown();
}


T100VOID T100ProjectInvoking::OnProjectCreate()
{
    m_skeletal->OnProjectCreate();
}

T100VOID T100ProjectInvoking::OnProjectCreateDone(T100ProjectInfo* info)
{
    m_skeletal->OnProjectCreateDone(info);
}

T100VOID T100ProjectInvoking::OnProjectRemove()
{
    m_skeletal->OnProjectRemove();
}

T100VOID T100ProjectInvoking::OnProjectOpen(T100ProjectData* data)
{
    m_skeletal->OnProjectOpen(data);
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

T100VOID T100ProjectInvoking::OnProjectActivated()
{
    m_skeletal->OnProjectActivated();
}

T100VOID T100ProjectInvoking::OnProjectSelect()
{
    m_skeletal->OnProjectSelect();
}


T100VOID T100ProjectInvoking::OnFileCreate()
{
    m_skeletal->OnFileCreate();
}

T100VOID T100ProjectInvoking::OnFileRemove()
{
    m_skeletal->OnFileRemove();
}

T100VOID T100ProjectInvoking::OnFileOpen()
{
    m_skeletal->OnFileOpen();
}

T100VOID T100ProjectInvoking::OnFileOpenDone(T100FileData* data)
{
    m_skeletal->OnFileOpenDone(data);
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

T100VOID T100ProjectInvoking::OnFileSelect()
{
    m_skeletal->OnFileSelect();
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


T100VOID T100ProjectInvoking::OnViewWorkSpaceTree(T100BOOL value)
{
    m_skeletal->OnViewWorkSpaceTree(value);
}

T100VOID T100ProjectInvoking::OnViewSearchResult(T100BOOL value)
{
    m_skeletal->OnViewSearchResult(value);
}

T100VOID T100ProjectInvoking::OnViewCompileOutput(T100BOOL value)
{
    m_skeletal->OnViewCompileOutput(value);
}


T100VOID T100ProjectInvoking::OnSearchFind()
{
    m_skeletal->OnSearchFind();
}

T100VOID T100ProjectInvoking::OnSearchReplace()
{
    m_skeletal->OnSearchReplace();
}


T100VOID T100ProjectInvoking::OnCompileRun()
{
    m_skeletal->OnCompileRun();
}

T100VOID T100ProjectInvoking::OnCompileBuildAndRun()
{
    m_skeletal->OnCompileBuildAndRun();
}

T100VOID T100ProjectInvoking::OnCompileBuild()
{
    m_skeletal->OnCompileBuild();
}

T100VOID T100ProjectInvoking::OnCompileClean()
{
    m_skeletal->OnCompileClean();
}

T100VOID T100ProjectInvoking::OnCompileRebuild()
{
    m_skeletal->OnCompileRebuild();
}


T100VOID T100ProjectInvoking::OnDebugStart()
{
    m_skeletal->OnDebugStart();
}

T100VOID T100ProjectInvoking::OnDebugStop()
{
    m_skeletal->OnDebugStop();
}


T100VOID T100ProjectInvoking::OnDebugPrint(const T100WSTRING& value)
{
    m_skeletal->OnDebugPrint(value);
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


T100VOID T100ProjectInvoking::OnFolderCreate()
{

}

T100VOID T100ProjectInvoking::OnFolderRemove()
{

}

T100VOID T100ProjectInvoking::OnFolderList(T100FolderData* data)
{
    m_skeletal->OnFolderList(data);
}

T100VOID T100ProjectInvoking::OnFolderClose()
{

}

T100VOID T100ProjectInvoking::OnMainPanelPageChanged()
{
    m_skeletal->OnMainPanelPageChanged();
}

T100VOID T100ProjectInvoking::OnMainPanelPageClosed(T100Pack* pack)
{
    m_skeletal->OnMainPanelPageClosed(pack);
}

T100VOID T100ProjectInvoking::OnMainPanelPageClosing(T100Pack* pack)
{
    m_skeletal->OnMainPanelPageClosing(pack);
}

T100VOID T100ProjectInvoking::OnModified(const T100WSTRING& path)
{
    m_skeletal->OnModified(path);
}

T100VOID T100ProjectInvoking::OnModuleCreate()
{
    m_skeletal->OnModuleCreate();
}

T100VOID T100ProjectInvoking::OnModuleCreateDone(T100ModuleInfo* info)
{
    m_skeletal->OnModuleCreateDone(info);
}

T100VOID T100ProjectInvoking::OnAuiPaneClose(wxAuiPaneInfo* info)
{
    m_skeletal->OnAuiPaneClose(info);
}
