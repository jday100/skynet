#ifndef T100DIAGRAMTRANSDUCER_H
#define T100DIAGRAMTRANSDUCER_H

#include "T100DiagramTransducerSource.h"
#include "T100DiagramTransducerTarget.h"

class T100DiagramTransducer
{
    public:
        T100DiagramTransducer();
        virtual ~T100DiagramTransducer();

        T100BOOL            serialize(T100DiagramTransducerSource&, T100DiagramTransducerTarget&);
        T100BOOL            deserialize(T100DiagramTransducerSource&, T100DiagramTransducerTarget&);

    protected:

    private:
};

#endif // T100DIAGRAMTRANSDUCER_H
