#ifndef T100TRANSDUCERSOURCE_H
#define T100TRANSDUCERSOURCE_H

#include "T100Common.h"

class T100TransducerTarget;

class T100TransducerSource
{
    public:
        T100TransducerSource();
        virtual ~T100TransducerSource();

        virtual T100VOID            SetTarget(T100TransducerTarget*);

        virtual T100BOOL            Serialize();
        virtual T100BOOL            Deserialize();

    protected:
        T100TransducerTarget*       m_target        = T100NULL;

    private:
};

#endif // T100TRANSDUCERSOURCE_H
