#ifndef T1003DEDITORVIEW_H
#define T1003DEDITORVIEW_H

#include <wx/aui/aui.h>
#include <wx/panel.h>
#include "T100Common.h"

class T1003DEditor;
class T1003DEditorFrame;
class T1003DEditorMainPanel;
class T1003DEditorEntityPanel;
class T1003DEditorPropertiesPanel;

class T1003DEditorView
{
    public:
        T1003DEditorView(T1003DEditorFrame*);
        virtual ~T1003DEditorView();

        T100VOID                            setEditor(T1003DEditor*);
        wxPanel*                            getPanel();

    protected:
        wxAuiManager*                       m_manager           = T100NULL;
        T1003DEditor*                       m_editor            = T100NULL;
        T1003DEditorFrame*                  m_frame             = T100NULL;
        T1003DEditorMainPanel*              m_main              = T100NULL;
        T1003DEditorEntityPanel*            m_entity_panel      = T100NULL;
        T1003DEditorPropertiesPanel*        m_properties_panel  = T100NULL;

    private:
        T100VOID                            create();
        T100VOID                            destroy();
};

#endif // T1003DEDITORVIEW_H
