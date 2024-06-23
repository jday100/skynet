#ifndef T100EDITORSTORE_H
#define T100EDITORSTORE_H

#include "T100Common.h"
class T100Editor;

class T100EditorStore
{
    public:
        T100EditorStore(T100Editor*);
        virtual ~T100EditorStore();

    protected:

    private:
        T100Editor*         m_editor            = T100NULL;
};

#endif // T100EDITORSTORE_H
