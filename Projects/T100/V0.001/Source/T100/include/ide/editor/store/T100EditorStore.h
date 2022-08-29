#ifndef T100EDITORSTORE_H
#define T100EDITORSTORE_H

#include "T100Common.h"
#include "T100EditorStoreText.h"
#include "T100EditorStoreBinary.h"


class T100EditorStore
{
    public:
        T100EditorStore();
        virtual ~T100EditorStore();

        T100EditorStoreText*        getText();
        T100EditorStoreBinary*      getBinary();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100EditorStoreText*        m_text          = T100NULL;
        T100EditorStoreBinary*      m_binary        = T100NULL;

};

#endif // T100EDITORSTORE_H
