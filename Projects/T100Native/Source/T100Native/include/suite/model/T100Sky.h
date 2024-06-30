#ifndef T100SKY_H
#define T100SKY_H

#include "T100Entity.h"

class T100Sky : public T100Entity
{
    public:
        T100Sky();
        virtual ~T100Sky();

        T100VOID            SetTerminus(T100FLOAT, T100FLOAT, T100FLOAT);

    protected:

    private:
};

#endif // T100SKY_H
