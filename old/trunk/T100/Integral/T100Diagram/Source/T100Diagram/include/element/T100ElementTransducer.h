#ifndef T100ELEMENTTRANSDUCER_H
#define T100ELEMENTTRANSDUCER_H

#include "T100TransducerBase.h"
#include "T100ElementTransducerSource.h"
#include "T100ElementTransducerTarget.h"

class T100ElementTransducer : public T100TransducerBase
{
    public:
        T100ElementTransducer();
        virtual ~T100ElementTransducer();

        T100BOOL            Serialize(T100ElementTransducerSource&, T100ElementTransducerTarget&);

        T100BOOL            Deserialize(T100ElementTransducerSource&, T100ElementTransducerTarget&);

    protected:

    private:
};

#endif // T100ELEMENTTRANSDUCER_H
