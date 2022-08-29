#ifndef T100IDESTOREBASE_H
#define T100IDESTOREBASE_H

#include "T100Common.h"
class T100IDEStore;


class T100IDEStoreBase
{
    public:
        T100IDEStoreBase(T100IDEStore*);
        virtual ~T100IDEStoreBase();

    protected:
        T100IDEStore*           m_store         = T100NULL;

    private:
};

#endif // T100IDESTOREBASE_H
