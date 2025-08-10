#ifndef T100PROJECTVIEWBASE_H
#define T100PROJECTVIEWBASE_H

#include <atomic>
#include <wx/aui/aui.h>
#include "T100Common.h"
#include "T100ProjectViewMainMenu.h"
#include "T100ProjectTree.h"
#include "T100MainPanel.h"

class T100ProjectFrame;

class T100ProjectViewBase
{
    public:
        T100ProjectViewBase();
        virtual ~T100ProjectViewBase();

        virtual T100VOID                SetDirty();
        virtual T100VOID                ClearDirty();
        virtual T100BOOL                IsDirty();

        wxAuiManager*                   GetAuiManager();
        T100ProjectFrame*               GetFrame();
        T100ProjectViewMainMenu*        GetMainMenu();
        T100ProjectTree*                GetProjectTree();
        T100MainPanel*                  GetMainPanel();

        T100INT                         ShowDirDialog(T100WSTRING&);

        T100VOID                        ShowProjectCreateWizard();

        T100VOID                        ShowAboutDialog();

    protected:
        std::atomic_bool                m_dirty;
        wxAuiManager*                   m_manager       = T100NULL;
        T100ProjectFrame*               m_frame         = T100NULL;
        T100ProjectViewMainMenu*        m_mainMenu      = T100NULL;

        T100ProjectTree*                m_projectTree   = T100NULL;
        T100MainPanel*                  m_mainPanel     = T100NULL;

    private:
        T100VOID                        init();
        T100VOID                        uninit();
};

#endif // T100PROJECTVIEWBASE_H
