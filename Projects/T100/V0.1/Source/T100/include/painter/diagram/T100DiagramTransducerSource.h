#ifndef T100DIAGRAMTRANSDUCERSOURCE_H
#define T100DIAGRAMTRANSDUCERSOURCE_H

#include "T100TransducerSource.h"

namespace T100Painter{
class T100DiagramTransducerTarget;

class T100DiagramTransducerSource : public T100Library::T100TransducerSource
{
    public:
        T100DiagramTransducerSource();
        virtual ~T100DiagramTransducerSource();

        T100VOID        setTarget(T100Library::T100TransducerTarget*);

    protected:
        T100DiagramTransducerTarget*        m_target            = T100NULL;

    private:
};

}

#endif // T100DIAGRAMTRANSDUCERSOURCE_H
