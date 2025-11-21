#ifndef T1003DEDITORENTITYMANAGER_H
#define T1003DEDITORENTITYMANAGER_H

#include <atomic>
#include "T100Entity.h"

class T1003DEditorEntityManager
{
    public:
        T1003DEditorEntityManager();
        virtual ~T1003DEditorEntityManager();

        T100VOID                            update(T100ENTITY_TYPE);
        T100Entity*                         getCurrent();

    protected:
        std::atomic<T100ENTITY_TYPE>        m_type;

    private:
        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T1003DEDITORENTITYMANAGER_H
