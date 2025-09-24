#ifndef T100PROJECTVIEWBASE_H
#define T100PROJECTVIEWBASE_H

#include <atomic>
#include <wx/aui/aui.h>
#include "T100MainMenu.h"
#include "T100MainPanel.h"
#include "T100ProjectTree.h"
#include "T100CompilePanel.h"
#include "T100DebugPanel.h"

#include "T100WxFileInfo.h"
#include "T100WorkSpaceInfo.h"

class T100ProjectFrame;

class T100ProjectViewBase
{
    public:
        T100ProjectViewBase();
        virtual ~T100ProjectViewBase();

        T100VOID                    SetDirty();
        T100VOID                    ClearDirty();
        T100BOOL                    IsDirty();

        T100VOID                    UpdateTitle();

        T100VOID                    ShowViewWorkSpaceTree(T100BOOL);
        T100VOID                    ShowViewSearchResult(T100BOOL);
        T100VOID                    ShowViewCompileOutput(T100BOOL);

        T100VOID                    ShowWorkSpaceCreateWizard();
        T100VOID                    ShowWorkSpacePopupMenu(T100BOOL);
        T100BOOL                    ShowWorkSpaceNotExistsDialog();
        T100INT                     ShowWorkSpaceFileExistsDialog();
        T100VOID                    ShowWorkSpaceFileNotExistsDailog();
        T100VOID                    ShowWorkSpaceCreateFailureDialog();
        T100VOID                    ShowWorkSpaceOpenFailureDialog();
        T100INT                     ShowWorkSpaceNotSaveDialog();

        T100VOID                    ShowProjectCreateWizard();
        T100VOID                    ShowProjectCreateFailureDialog();

        T100VOID                    ShowFileOpenFailureDialog();

        T100VOID                    ShowSetupCompilerDialog();

        T100INT                     ShowFolderDialog(T100WSTRING&);
        T100INT                     ShowFileNameDialog(T100WxFileInfo&);

        T100INT                     ShowModuleCreateDialog();

    protected:
        std::atomic_bool            m_dirty;
        T100WSTRING                 m_projectTitle  = L"T100Project";

        wxAuiManager*               m_manager       = T100NULL;
        T100ProjectFrame*           m_frame         = T100NULL;
        T100MainMenu*               m_mainMenu      = T100NULL;
        T100MainPanel*              m_mainPanel     = T100NULL;
        T100ProjectTree*            m_projectTree   = T100NULL;
        T100CompilePanel*           m_compilePanel  = T100NULL;
        T100DebugPanel*             m_debugPanel    = T100NULL;

    private:
};

#endif // T100PROJECTVIEWBASE_H
