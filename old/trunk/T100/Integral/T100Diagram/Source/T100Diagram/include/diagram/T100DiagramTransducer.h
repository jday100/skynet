#ifndef T100DIAGRAMTRANSDUCER_H
#define T100DIAGRAMTRANSDUCER_H

#include "T100TransducerBase.h"
#include "T100DiagramTransducerSource.h"
#include "T100DiagramTransducerTarget.h"

class T100DiagramTransducer : public T100TransducerBase
{
    public:
        T100DiagramTransducer();
        virtual ~T100DiagramTransducer();

        T100BOOL        Serialize(T100DiagramTransducerSource&, T100DiagramTransducerTarget&);
        T100BOOL        Deserialize(T100DiagramTransducerSource&, T100DiagramTransducerTarget&);

    protected:

    private:
};

#endif // T100DIAGRAMTRANSDUCER_H
