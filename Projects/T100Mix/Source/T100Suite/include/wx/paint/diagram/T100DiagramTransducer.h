#ifndef T100DIAGRAMTRANSDUCER_H
#define T100DIAGRAMTRANSDUCER_H

#include "base\T100Transducer.h"
#include "T100DiagramTransducerSource.h"
#include "T100DiagramTransducerTarget.h"

class T100DiagramTransducer : public T100Transducer
{
    public:
        T100DiagramTransducer();
        virtual ~T100DiagramTransducer();

        virtual T100BOOL            serialize(T100TransducerSource&, T100TransducerTarget&);

        virtual T100BOOL            deserialize(T100TransducerSource&, T100TransducerTarget&);

    protected:

    private:
};

#endif // T100DIAGRAMTRANSDUCER_H
