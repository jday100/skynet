#ifndef T100EDITORVIEW_H
#define T100EDITORVIEW_H

#include "T100Common.h"
#include "T100EditorMainMenu.h"
#include "T100EditorMain.h"
#include "T100EditorWindowsManager.h"

class T100EditorView
{
    public:
        T100EditorView();
        virtual ~T100EditorView();

        T100BOOL            load(T100WString&);
        T100BOOL            save(T100WString&);

        T100BOOL            show();
        T100BOOL            hide();

        T100BOOL            renew();
        T100BOOL            open(T100WString&);
        T100BOOL            close();

        T100BOOL            save();
        T100BOOL            save_as();

        T100BOOL            quit();

        T100BOOL            undo();
        T100BOOL            redo();
        T100BOOL            cut();
        T100BOOL            copy();
        T100BOOL            paste();

        T100BOOL            find();
        T100BOOL            replace();

        T100VOID*           getFrame();
        wxAuiManager*       getAuiManager();

        T100EditorCtrl*     getCurrent();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100EditorMainMenu*         m_main_menu         = T100NULL;
        T100EditorFrame*            m_main_frame        = T100NULL;

        T100EditorWindowsManager*   m_manager           = T100NULL;
};

#endif // T100EDITORVIEW_H
