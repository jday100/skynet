#ifndef T100EDITORVIEW_H
#define T100EDITORVIEW_H

#include "T100Common.h"
#include "T100SceneEditorFrame.h"

class T100EditorView
{
    public:
        T100EditorView();
        virtual ~T100EditorView();

        T100VOID                    Show();

    protected:
        T100SceneEditorFrame*       m_frame             = T100NULL;
    private:
        T100VOID                    TurnOn();
        T100VOID                    TurnOff();
};

#endif // T100EDITORVIEW_H
