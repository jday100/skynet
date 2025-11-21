#ifndef T1003DEDITORSTORE_H
#define T1003DEDITORSTORE_H

#include "data/T1003DEditorDocument.h"

class T1003DEditorStore
{
    public:
        T1003DEditorStore();
        virtual ~T1003DEditorStore();

        T100BOOL            Open(T100WSTRING&, T1003DEditorDocument*);
        T100BOOL            Save(T1003DEditorDocument*);
        T100BOOL            SaveAs(T100WSTRING&, T1003DEditorDocument*);

        T100BOOL            Import(T100WSTRING&, T1003DEditorDocument*);

    protected:

    private:
};

#endif // T1003DEDITORSTORE_H
