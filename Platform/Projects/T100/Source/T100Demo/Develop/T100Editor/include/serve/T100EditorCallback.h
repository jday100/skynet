#ifndef T100EDITORCALLBACK_H
#define T100EDITORCALLBACK_H

#include "T100Common.h"
#include "T100EditorView.h"
#include "T100EditorServe.h"
#include "T100EditorStore.h"

class T100EditorCallback
{
    public:
        T100EditorCallback();
        virtual ~T100EditorCallback();

        static T100VOID                 init(T100EditorView*, T100EditorServe*, T100EditorStore*);

        static T100VOID                 OnMenuNewSelected();
        static T100VOID                 OnMenuOpenSelected();
        static T100VOID                 OnMenuCloseSelected();
        static T100VOID                 OnMenuSaveSelected();
        static T100VOID                 OnMenuSaveAsSelected();

        static T100VOID                 OnMenuUndoSelected();
        static T100VOID                 OnMenuRedoSelected();
        static T100VOID                 OnMenuCutSelected();
        static T100VOID                 OnMenuCopySelected();
        static T100VOID                 OnMenuPasteSelected();

        static T100VOID                 OnMenuFindSelected();
        static T100VOID                 OnMenuReplaceSelected();

        static T100VOID                 OnMenuQuitSelected();

    protected:

    private:
        static T100EditorView*          m_view;
        static T100EditorServe*         m_serve;
        static T100EditorStore*         m_store;
};

#endif // T100EDITORCALLBACK_H
