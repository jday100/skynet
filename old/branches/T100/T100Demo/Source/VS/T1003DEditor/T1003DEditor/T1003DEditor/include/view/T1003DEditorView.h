#ifndef T1003DEDITORVIEW_H
#define T1003DEDITORVIEW_H

#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/aui/aui.h>
#include "T100Common.h"

class T1003DEditorFrame;
class T1003DEditorSkeletal;
class T1003DEditorMainMenu;
class T1003DEditorMainPanel;
class T1003DEditorScenePanel;
class T1003DEditorEntityPanel;
class T1003DEditorManagerPanel;
class T1003DEditorPropertiesPanel;
class T1003DEditorConfigDialog;

class T1003DEditorView
{
    public:
        T1003DEditorView();
        virtual ~T1003DEditorView();

        T100VOID                            SetSkeletal(T1003DEditorSkeletal*);
        T1003DEditorSkeletal*               GetSkeletal();

        T1003DEditorMainMenu*               GetMainMenu();
        T1003DEditorMainPanel*              GetMainPanel();
        T1003DEditorScenePanel*             GetScenePanel();
        T1003DEditorEntityPanel*            GetEntityPanel();
        T1003DEditorPropertiesPanel*        GetPropertiesPanel();

        T100VOID                            ShowConfig();
        T100VOID                            ShowManager(T100BOOL);
        T100VOID                            ShowProperties(T100BOOL);

        T100VOID                            SetTitle(T100WSTRING = L"");
        T100VOID                            SetDirty(T100BOOL = T100TRUE);
        T100BOOL                            IsDirty();

        T100VOID                            SetStatus(T100UINT, wxString);

        T100VOID                            Clear();
        T100VOID                            Update();

        T100VOID                            Create(T1003DEditorFrame*);

        T100BOOL                            Open(T100WSTRING&);
        T100BOOL                            Save(T100WSTRING&);

        T100BOOL                            Import(T100WSTRING&);

        T100VOID                            Quit();

    protected:
        wxAuiManager*                       m_auiManager        = T100NULL;
        wxTimer                             m_timer;
        T1003DEditorFrame*                  m_frame             = T100NULL;
        T1003DEditorSkeletal*               m_skeletal          = T100NULL;
        T1003DEditorMainMenu*               m_mainMenu          = T100NULL;
        T1003DEditorMainPanel*              m_mainPanel         = T100NULL;
        T1003DEditorManagerPanel*           m_managerPanel      = T100NULL;
        T1003DEditorPropertiesPanel*        m_propertiesPanel   = T100NULL;

        T1003DEditorConfigDialog*           m_configDialog      = T100NULL;

    protected:
        void OnAuiPaneClose(wxAuiManagerEvent& event);
        void OnFrameClose(wxCloseEvent& event);
        void OnTimer(wxTimerEvent& event);

    private:
        T100WSTRING                         m_projectName;
        T100WSTRING                         m_title;
        T100BOOL                            m_dirty             = T100FALSE;
        T100VOID                            Destroy();
};

#endif // T1003DEDITORVIEW_H
