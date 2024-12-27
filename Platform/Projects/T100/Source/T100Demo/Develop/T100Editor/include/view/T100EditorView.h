#ifndef T100EDITORVIEW_H
#define T100EDITORVIEW_H

#include "T100Common.h"
#include "T100EditorMainMenu.h"

class T100EditorView
{
    public:
        T100EditorView();
        virtual ~T100EditorView();

        T100BOOL            show();
        T100BOOL            hide();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100EditorMainMenu*         m_main_menu         = T100NULL;
};

#endif // T100EDITORVIEW_H
