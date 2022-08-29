#ifndef T100IDESTORE_H
#define T100IDESTORE_H

#include "IStore.h"
#include "T100IDEStoreEditor.h"
#include "T100IDEStoreProject.h"


class T100IDEStore : public IStore
{
    public:
        T100IDEStore();
        virtual ~T100IDEStore();

        T100IDEStoreProject*        getProject();
        T100IDEStoreEditor*         getEditor();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100IDEStoreProject*        m_project       = T100NULL;
        T100IDEStoreEditor*         m_editor        = T100NULL;

};

#endif // T100IDESTORE_H
