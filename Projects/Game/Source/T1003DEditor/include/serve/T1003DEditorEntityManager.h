#ifndef T1003DEDITORENTITYMANAGER_H
#define T1003DEDITORENTITYMANAGER_H

#include "T100Entity.h"

class T1003DEditorEntityManager
{
    public:
        T1003DEditorEntityManager();
        virtual ~T1003DEditorEntityManager();

        T100Entity*                 getCurrent();

    protected:

    private:
};

#endif // T1003DEDITORENTITYMANAGER_H
