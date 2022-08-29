#ifndef T100EDITORSTOREBASE_H
#define T100EDITORSTOREBASE_H

#include "T100Common.h"
class T100EditorStore;


class T100EditorStoreBase
{
    public:
        T100EditorStoreBase(T100EditorStore*);
        virtual ~T100EditorStoreBase();

    protected:
        T100EditorStore*            m_store         = T100NULL;

    private:
};

#endif // T100EDITORSTOREBASE_H
