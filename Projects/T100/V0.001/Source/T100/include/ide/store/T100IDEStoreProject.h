#ifndef T100IDESTOREPROJECT_H
#define T100IDESTOREPROJECT_H

#include "T100IDEStoreBase.h"
#include "T100IDEProjectData.h"


class T100IDEStoreProject : public T100IDEStoreBase
{
    public:
        T100IDEStoreProject(T100IDEStore*);
        virtual ~T100IDEStoreProject();

        T100BOOL            list(T100IDE_PROJECT_VECTOR&);

    protected:

    private:
        T100STDSTRING       m_base      = "..\\work";

};

#endif // T100IDESTOREPROJECT_H
