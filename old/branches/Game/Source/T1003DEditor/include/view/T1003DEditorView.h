#ifndef T1003DEDITORVIEW_H
#define T1003DEDITORVIEW_H

#include "T100Common.h"

class T1003DEditorSkeletal;
class wxAuiManager;
class T1003DEditorFrame;
class T1003DEditorMainPanel;
class T1003DEditorEntityPanel;
class T1003DEditorPropertiesPanel;
class T100Entity;
class T1003DEditorEntityManager;

class T1003DEditorView
{
    public:
        T1003DEditorView();
        virtual ~T1003DEditorView();

        T100VOID                            SetCursor();
        T100VOID                            SetTitle();

        T100BOOL                            Open(T100WSTRING&);
        T100BOOL                            Save(T100WSTRING&);

        T100VOID                            Create(T1003DEditorFrame*);

        T100VOID                            SetSkeletal(T1003DEditorSkeletal*);
        T1003DEditorSkeletal*               GetSkeletal();

        T1003DEditorMainPanel*              getMainPanel();
        T1003DEditorEntityPanel*            getEntityPanel();
        T1003DEditorPropertiesPanel*        getPropertiesPanel();

        T100Entity*                         getEntity();
        T1003DEditorEntityManager*          getEntityManager();

        T100VOID                            ShowConfigDialog();

    protected:
        T1003DEditorSkeletal*               m_skeletal          = T100NULL;
        wxAuiManager*                       m_aui_manager       = T100NULL;
        T1003DEditorEntityManager*          m_entity_manager    = T100NULL;
        T1003DEditorFrame*                  m_frame             = T100NULL;
        T1003DEditorMainPanel*              m_main              = T100NULL;
        T1003DEditorEntityPanel*            m_entity_panel      = T100NULL;
        T1003DEditorPropertiesPanel*        m_properties_panel  = T100NULL;

    private:
        T100VOID                            Destroy();
};

#endif // T1003DEDITORVIEW_H
