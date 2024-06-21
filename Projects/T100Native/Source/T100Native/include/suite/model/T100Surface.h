#ifndef T100SURFACE_H
#define T100SURFACE_H

#include "T100Entity.h"

class T100Surface : public T100Entity
{
    public:
        T100Surface();
        virtual ~T100Surface();

        T100VOID            Create(T100FLOAT, T100FLOAT, T100INT, T100INT);

    protected:

    private:
};

#endif // T100SURFACE_H
