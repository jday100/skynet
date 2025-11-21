#ifndef T1003DEDITORSKELETAL_H
#define T1003DEDITORSKELETAL_H

#include "T100Common.h"

class T1003DEditorStore;
class T1003DEditorServe;
class T1003DEditorView;

class T1003DEditorSkeletal
{
    public:
        T1003DEditorSkeletal();
        virtual ~T1003DEditorSkeletal();

        T100VOID                    New();
        T100VOID                    Open();
        T100VOID                    Close();

        T100VOID                    Save();

        T100VOID                    SetStore(T1003DEditorStore*);
        T1003DEditorStore*          GetStore();

        T100VOID                    SetServe(T1003DEditorServe*);
        T1003DEditorServe*          GetServe();

        T100VOID                    SetView(T1003DEditorView*);
        T1003DEditorView*           GetView();

    protected:
        T1003DEditorStore*          m_store         = T100NULL;
        T1003DEditorServe*          m_serve         = T100NULL;
        T1003DEditorView*           m_view          = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITORSKELETAL_H
