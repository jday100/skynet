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

        static T100VOID                 OnMenuNewSelected();
        static T100VOID                 OnMenuOpenSelected();
        static T100VOID                 OnMenuCloseSelected();
        static T100VOID                 OnMenuSaveSelected();
        static T100VOID                 OnMenuSaveAsSelected();

    protected:

    private:
        static T100EditorView*          m_view;
        static T100EditorServe*         m_serve;
        static T100EditorStore*         m_store;
};

#endif // T100EDITORCALLBACK_H
