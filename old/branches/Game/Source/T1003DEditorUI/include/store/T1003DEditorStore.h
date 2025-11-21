#ifndef T1003DEDITORSTORE_H
#define T1003DEDITORSTORE_H

#include "T1003DEditorDocument.h"
#include "T1003DEditorSettingsStore.h"

class T1003DEditorStore
{
    public:
        T1003DEditorStore();
        virtual ~T1003DEditorStore();

        T1003DEditorSettingsStore&          GetSettingsStore();

        T100BOOL            Open(T100WSTRING&, T1003DEditorDocument*);
        T100BOOL            Save(T1003DEditorDocument*);
        T100BOOL            SaveAs(T100WSTRING&, T1003DEditorDocument*);

        T100BOOL            Import(T100WSTRING&, T1003DEditorDocument*);

    protected:
        T100VOID            LoadGLTF(T100WSTRING&, T1003DEditorDocument*);
        T100VOID            LoadH3D(T100WSTRING&, T1003DEditorDocument*);

        T1003DEditorSettingsStore           m_settingsStore;

    private:
};

#endif // T1003DEDITORSTORE_H
