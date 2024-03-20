#ifndef T100TRANSDUCER_H
#define T100TRANSDUCER_H

#include "T100Common.h"
#include "T100TransducerSource.h"
#include "T100TransducerTarget.h"


class T100Transducer
{
    public:
        T100Transducer();
        virtual ~T100Transducer();

        virtual T100BOOL            serialize(T100TransducerSource&, T100TransducerTarget&);

        virtual T100BOOL            deserialize(T100TransducerSource&, T100TransducerTarget&);

    protected:

    private:
};

#endif // T100TRANSDUCER_H
