#ifndef T100EDITORSTORE_H
#define T100EDITORSTORE_H

#include "T100Common.h"

class T100EditorStore
{
    public:
        T100EditorStore();
        virtual ~T100EditorStore();

        T100BOOL            load();
        T100BOOL            save();

    protected:

    private:
};

#endif // T100EDITORSTORE_H
