#ifndef T100ELEMENTTRANSDUCER_H
#define T100ELEMENTTRANSDUCER_H

#include "T100Common.h"
#include "T100TransducerBase.h"
#include "T100ElementTransducerSource.h"
#include "T100ElementTransducerTarget.h"

namespace T100Painter{

class T100ElementTransducer : public T100Library::T100TransducerBase
{
    public:
        T100ElementTransducer();
        virtual ~T100ElementTransducer();

        T100BOOL            serialize(T100ElementTransducerSource&, T100ElementTransducerTarget&);

        T100BOOL            deserialize(T100ElementTransducerSource&, T100ElementTransducerTarget&);

    protected:

    private:
};

}

#endif // T100ELEMENTTRANSDUCER_H
