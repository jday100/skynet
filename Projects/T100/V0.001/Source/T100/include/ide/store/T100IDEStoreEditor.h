#ifndef T100IDESTOREEDITOR_H
#define T100IDESTOREEDITOR_H

#include "T100IDEStoreBase.h"
#include "T100EditorData.h"


class T100IDEStoreEditor : public T100IDEStoreBase
{
    public:
        T100IDEStoreEditor(T100IDEStore*);
        virtual ~T100IDEStoreEditor();

        T100BOOL            open(T100STDSTRING, T100EditorData*);

    protected:

    private:
};

#endif // T100IDESTOREEDITOR_H
