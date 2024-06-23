#ifndef T100EDITORVIEW_H
#define T100EDITORVIEW_H

#include "T100Common.h"
#include "T100EditorRender.h"
#include "T100SceneEditorFrame.h"
#include "T100SceneEditorEntityPanel.h"
class T100Editor;

class T100EditorView
{
    public:
        T100EditorView(T100Editor*);
        virtual ~T100EditorView();

        T100VOID                            Show();

        T100Editor*                         GetEditor();
        T100EditorRender*                   GetRender();
        T100SceneEditorFrame*               GetFrame();

    protected:
        T100Editor*                         m_editor            = T100NULL;
        T100EditorRender*                   m_render            = T100NULL;
        T100SceneEditorFrame*               m_frame             = T100NULL;
        T100SceneEditorEntityPanel*         m_entity_panel      = T100NULL;

    private:
        T100VOID                            TurnOn();
        T100VOID                            TurnOff();
};

#endif // T100EDITORVIEW_H
