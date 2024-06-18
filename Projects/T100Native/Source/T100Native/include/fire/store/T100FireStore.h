#ifndef T100FIRESTORE_H
#define T100FIRESTORE_H

#include "T100Common.h"
#include "T100Entity.h"

class T100FireStore
{
    public:
        T100FireStore();
        virtual ~T100FireStore();

        T100BOOL            Load(T100ENTITY_VECTOR&);

    protected:

    private:
};

#endif // T100FIRESTORE_H
