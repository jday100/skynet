#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100EditorStore.h"
#include "T100EditorServe.h"
#include "T100EditorView.h"

class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100VOID                    SetStore(T100EditorStore*);
        T100EditorStore*            GetStore();

        T100VOID                    SetServe(T100EditorServe*);
        T100EditorServe*            GetServe();

        T100VOID                    SetView(T100EditorView*);
        T100EditorView*             GetView();


    protected:
        T100EditorStore*            m_store             = T100NULL;
        T100EditorServe*            m_serve             = T100NULL;
        T100EditorView*             m_view              = T100NULL;

    private:
        T100VOID                    TurnOn();
        T100VOID                    TurnOff();
};

#endif // T100EDITOR_H
