#ifndef T100EDITORSTORETEXT_H
#define T100EDITORSTORETEXT_H

#include "T100EditorStoreBase.h"
#include "T100EditorData.h"


class T100EditorStoreText : public T100EditorStoreBase
{
    public:
        T100EditorStoreText(T100EditorStore*);
        virtual ~T100EditorStoreText();

        T100BOOL            load(T100STDSTRING, T100EditorData*&);
        T100BOOL            save(T100STDSTRING, T100EditorData*);

    protected:

    private:
};

#endif // T100EDITORSTORETEXT_H
