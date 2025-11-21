#ifndef T1003DEDITORSKELETAL_H
#define T1003DEDITORSKELETAL_H

#include "T100Common.h"

class T1003DEditorUIFrame;
class T1003DEditorView;
class T1003DEditorServe;
class T1003DEditorStore;


class T1003DEditorSkeletal
{
    public:
        T1003DEditorSkeletal();
        virtual ~T1003DEditorSkeletal();

        T100VOID                    SetView(T1003DEditorView* view);
        T1003DEditorView*           GetView();
        T100VOID                    SetServe(T1003DEditorServe* serve);
        T1003DEditorServe*          GetServe();
        T100VOID                    SetStore(T1003DEditorStore* store);
        T1003DEditorStore*          GetStore();

        T100VOID                    Create(T1003DEditorUIFrame*);

        T100VOID                    New();
        T100VOID                    Open();
        T100VOID                    Close();
        T100VOID                    Save();
        T100VOID                    SaveAs();
        T100VOID                    Import();
        T100VOID                    Export();
        T100VOID                    Quit();
        T100VOID                    Undo();
        T100VOID                    Redo();
        T100VOID                    Cut();
        T100VOID                    Copy();
        T100VOID                    Paste();

        T100VOID                    SetManager(T100BOOL);
        T100VOID                    ShowManager(T100BOOL);
        T100VOID                    SetProperties(T100BOOL);
        T100VOID                    ShowProperties(T100BOOL);
        T100VOID                    ShowConfig();
        T100VOID                    ShowSettings();
        T100VOID                    ShowAbout();

    protected:
        T1003DEditorView*           m_view          = T100NULL;
        T1003DEditorServe*          m_serve         = T100NULL;
        T1003DEditorStore*          m_store         = T100NULL;

    private:
        T100VOID                    Load();
        T100VOID                    Destroy();
};

#endif // T1003DEDITORSKELETAL_H
