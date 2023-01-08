#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100EditorCommon.h"
#include "T100EditorState.h"
#include "T100EditorTransverter.h"


namespace T100Editor{
class T100EditorApp;
class T100EditorServe;
class T100EditorView;

class T100Editor
{
    public:
        T100Editor(T100EditorApp* = T100NULL);
        virtual ~T100Editor();

        T100VOID                    Reset();

        T100EditorState*            GetCurrent();
        T100BOOL                    Change(T100EDITOR_STATE);

        T100VOID                    setServe(T100EditorServe*);
        T100EditorServe*            getServe();

        T100VOID                    setView(T100EditorView*);
        T100EditorView*             getView();

        T100VOID                    show();
        T100VOID                    quit();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100EditorApp*              m_app           = T100NULL;
        T100EditorServe*            m_serve         = T100NULL;
        T100EditorView*             m_view          = T100NULL;

        T100EditorTransverter       m_manager;

};

}

#endif // T100EDITOR_H
